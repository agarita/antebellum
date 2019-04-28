            global      catena2numerus
            global      catena2imago
            global      catena2fractio
            global      catena2dualis
            global      valrom
            global      hexval

            section     .data
constV:     db  9, "veridicus",0
constF:     db  10, "falsidicus",0

            section     .text

;##########################################
;#   Entrada:
;#      rdi: puntero a catena.
;#
;#   Salida:
;#      rax: Char
;##########################################
catena2imago:
            push      rbp
            mov       rbp, rsp
            xor         r8,r8
            xor         r9,r9
            xor         r10,r10
ci1:        cmp         r8b, byte[rdi]
            jge         ci2
            inc         r8b
            mov         r10b, byte[rdi+r8]
            add         r9w,r10w
            jmp         ci1
ci2:        xor         rax,rax
            xor         rdx, rdx
            mov         ax,r9w
            div         r8b
            mov         rsp, rbp
            pop         rbp
            ret


;##########################################
;#   Entrada:
;#      rdi: puntero a catena
;#   Salida:
;#      rax: numero 16
;#   TODO: ahorita mete todos los numeros en 7 bits (los numeros 16 bits usan max 5 + 1 de signo + 1 de spare)
;#          podemos usar el length del primer bit
;##########################################
catena2numerus:
        push    rbp
        mov     rbp, rsp

        mov     QWORD [rbp-8], rdi
        mov     rax, QWORD [rbp-8]
        movzx   eax, BYTE [rax]
        cmp     al, 2
        jle     .L2
        mov     rax, QWORD [rbp-8]
        add     rax, 1
        movzx   eax, BYTE [rax]
        cmp     al, 48
        jne     .L2
        mov     rax, QWORD [rbp-8]
        add     rax, 2
        movzx   eax, BYTE [rax]
        cmp     al, 120
        je      .L3
        mov     rax, QWORD [rbp-8]
        add     rax, 2
        movzx   eax, BYTE [rax]
        cmp     al, 88
        jne     .L4
.L3:
        call    hexval
        jmp     .L5
.L4:
        mov     rax, QWORD [rbp-8]
        add     rax, 2
        movzx   eax, BYTE [rax]
        cmp     al, 114
        je      .L6
        mov     rax, QWORD [rbp-8]
        add     rax, 2
        movzx   eax, BYTE [rax]
        cmp     al, 82
        jne     .L2
.L6:
        call    roman2decimal
        jmp     .L5
.L2:
        call    str2dec
.L5:
        pop     rbp
        ret


;##########################################
;#   Entrada:
;#      rdi: puntero a catena.
;#   Salida:
;#      rax: dualis
;#
;##########################################
catena2dualis:
            push      rbp
            mov       rbp, rsp
            xor         rax,rax
            inc         rax
            xor         r8,r8
            xor         r9,r9
            xor         r10,r10
cd1:        cmp         r8b, 10
            jg          cd2
            mov         r9b, byte[rdi+r8]
            mov         r10b, byte[constV+r8]
            inc         r8b
            cmp         r9b, r10b
            je          cd1
            add         r9b, 32
            cmp         r9b, r10b
            je          cd1
            xor         rax,rax
cd2:        mov         rsp, rbp
            pop         rbp
            ret


;##########################################
;#   Entrada:
;#      rdi: puntero a catena.
;#   Salida:
;#      rax: frctio (por convencion va aqui y no en pila (ver correos de K))
;#
;##########################################
catena2fractio:
push    rbp
        mov     rbp, rsp
        sub     rsp, 40
        mov     QWORD [rbp-40], rdi
        mov     BYTE [rbp-24], 0
        mov     QWORD [rbp-8], 0
        mov     BYTE [rbp-9], 0
        mov     DWORD [rbp-16], 1
.L7:
        mov     rax, QWORD [rbp-40]
        movzx   eax, BYTE [rax]
        movsx   eax, al
        cmp     DWORD [rbp-16], eax
        jg      .L4
        mov     eax, DWORD [rbp-16]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-40]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 124
        jne     .L5
        mov     BYTE [rbp-9], 1
        jmp     .L6
.L5:
        cmp     BYTE [rbp-9], 0
        je      .L6
        movzx   eax, BYTE [rbp-24]
        add     eax, 1
        mov     BYTE [rbp-24], al
        mov     eax, DWORD [rbp-16]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-40]
        add     rdx, rax
        movzx   eax, BYTE [rbp-24]
        movsx   eax, al
        movzx   edx, BYTE [rdx]
        cdqe
        mov     BYTE [rbp-24+rax], dl
        mov     eax, DWORD [rbp-16]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-40]
        add     rax, rdx
        mov     BYTE [rax], 0
.L6:
        add     DWORD [rbp-16], 1
        jmp     .L7
.L4:
        mov     rax, QWORD [rbp-40]
        movzx   eax, BYTE [rax]
        mov     edx, eax
        movzx   eax, BYTE [rbp-24]
        sub     edx, eax
        mov     eax, edx
        sub     eax, 1
        mov     edx, eax
        mov     rax, QWORD [rbp-40]
        mov     BYTE [rax], dl
        movzx   eax, BYTE [rbp-24]
        test    al, al
        jle     .L8
        lea     rax, [rbp-24]
        mov     rdi, rax
        call    catena2numerus
        cdqe
        mov     QWORD [rbp-8], rax
        jmp     .L9
.L8:
        mov     QWORD [rbp-8], 1
.L9:
        sal     QWORD [rbp-8], 16
        mov     rax, QWORD [rbp-40]
        mov     rdi, rax
        call    catena2numerus
        cdqe
        and     rax, 0xFFFF
        add     QWORD [rbp-8], rax
        mov     rax, QWORD [rbp-8]
        leave
        ret




;##########################################
;#
;#   AUXILIARES
;#
;##########################################

str2dec:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     DWORD [rbp-4], 1
        mov     DWORD [rbp-8], 0
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     DWORD [rbp-12], eax
sd4:
        cmp     DWORD [rbp-12], 0
        jle     sd2
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 47
        jle     sd3
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 57
        jg      sd3
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        sub     eax, 48
        imul    eax, DWORD [rbp-4]
        add     DWORD [rbp-8], eax
        mov     edx, DWORD [rbp-4]
        mov     eax, edx
        sal     eax, 2
        add     eax, edx
        add     eax, eax
        mov     DWORD [rbp-4], eax
sd3:
        sub     DWORD [rbp-12], 1
        jmp     sd4
sd2:
        mov     rax, QWORD [rbp-24]
        add     rax, 1
        movzx   eax, BYTE [rax]
        cmp     al, 45
        jne     sd5
        neg     DWORD [rbp-8]
sd5:
        mov     eax, DWORD [rbp-8]
        pop     rbp
        ret


roman2decimal:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 24
        mov     QWORD [rbp-24], rdi
        mov     DWORD [rbp-4], 0
        mov     DWORD [rbp-8], 3
rd23:
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        movsx   eax, al
        cmp     DWORD [rbp-8], eax
        jg      rd18
        mov     eax, DWORD [rbp-8]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     edi, eax
        call    valrom
        mov     DWORD [rbp-12], eax
        mov     eax, DWORD [rbp-8] ;;if
        lea     edx, [rax+1]
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        movsx   eax, al
        cmp     edx, eax
        jg     rd19
        mov     eax, DWORD [rbp-8]
        cdqe
        lea     rdx, [rax+1]
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     edi, eax
        call    valrom
        mov     DWORD [rbp-16], eax
        mov     eax, DWORD [rbp-12]
        cmp     eax, DWORD [rbp-16]
        jl      rd20
        mov     eax, DWORD [rbp-12]
        add     DWORD [rbp-4], eax
        jmp     rd22
rd20:
        mov     edx, DWORD [rbp-4]
        mov     eax, DWORD [rbp-16]
        add     eax, edx
        sub     eax, DWORD [rbp-12]
        mov     DWORD [rbp-4], eax
        add     DWORD [rbp-8], 1
        jmp     rd22
rd19:
        mov     eax, DWORD [rbp-12]
        add     DWORD [rbp-4], eax
        add     DWORD [rbp-8], 1
rd22:
        add     DWORD [rbp-8], 1
        jmp     rd23
rd18:
        mov     eax, DWORD [rbp-4]
        leave
        ret


valrom:
        push    rbp
        mov     rbp, rsp
        xor     rax, rax

        cmp     dil, 73
        je      vr2
        cmp     dil, 105
        jne     vr3
vr2:
        mov     rax, 1
        jmp     vr4
vr3:
        cmp     dil, 86
        je      vr5
        cmp     dil, 118
        jne     vr6
vr5:
        mov     rax, 5
        jmp     vr4
vr6:
        cmp     dil, 88
        je      vr7
        cmp     dil, 120
        jne     vr8
vr7:
        mov     rax, 10
        jmp     vr4
vr8:
        cmp     dil, 76
        je      vr9
        cmp     dil, 108
        jne     vr10
vr9:
        mov     rax, 50
        jmp     vr4
vr10:
        cmp     dil, 67
        je      vr11
        cmp     dil, 99
        jne     vr12
vr11:
        mov     rax, 100
        jmp     vr4
vr12:
        cmp     dil, 68
        je      vr13
        cmp     dil, 100
        jne     vr14
vr13:
        mov     rax, 500
        jmp     vr4
vr14:
        cmp     dil, 77
        je      vr15
        cmp     dil, 109
        jne     vr16
vr15:
        mov     rax, 1000
        jmp     vr4
vr16:
        mov     rax, -1
vr4:
        mov         rsp, rbp
        pop     rbp
        ret

hexval: push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     DWORD [rbp-4], 1
        mov     DWORD [rbp-8], 0
        mov     rax, QWORD [rbp-24]
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     DWORD [rbp-12], eax
hv6:    cmp     DWORD [rbp-12], 0
        jle      hv2
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 47
        jle     hv3
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 57
        jg      hv3
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        sub     eax, 48
        imul    eax, DWORD [rbp-4]
        add     DWORD [rbp-8], eax
        sal     DWORD [rbp-4], 4
        jmp     hv4
hv3:
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 64
        jle     hv5
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 70
        jg      hv5
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        sub     eax, 55
        imul    eax, DWORD [rbp-4]
        add     DWORD [rbp-8], eax
        sal     DWORD [rbp-4], 4
        jmp     hv4
hv5:
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 96
        jle     hv4
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        cmp     al, 102
        jg      hv4
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        sub     eax, 87
        imul    eax, DWORD [rbp-4]
        add     DWORD [rbp-8], eax
        sal     DWORD [rbp-4], 4
hv4:
        sub     DWORD [rbp-12], 1
        jmp     hv6
hv2:
        mov     eax, DWORD [rbp-8]
        pop     rbp
        ret