            global      numerus2catena
            global      numerus2imago
            global      numerus2fractio
            global      numerus2dualis


            section     .data

            section     .text

;##########################################
;#   Entrada:
;#      rdi: numero de 16 bits. (Lo demas se ignora)
;#
;#   Salida:
;#      rax: Char
;##########################################
numerus2imago:
            push      rbp
            mov       rbp, rsp
            xor         rdx,rdx
            xor         rax,rax
            mov         ax,di
            mov         r8w, 256
            div         r8w
            xor         rax, rax
            mov         ax, dx
            mov         rsp, rbp
            pop         rbp
            ret


;##########################################
;#   Entrada:
;#      rdi: numero de 16 bits
;#      rsi: puntero a string a escribir
;##########################################
numerus2catena:
            push      rbp
            mov       rbp, rsp
            xor         r9, r9      ;length
            mov         r10, 10     ;numero 10 fijo
            xor         r11, r11    ;es negativo?
            mov         rax, rdi
            cmp         ax, 0
            jge         nc1
            mov         r11, 1      ;indicamos que el numero es negativo
            neg         di
            xor         rax, rax
            mov         ax, di
nc1:        xor         rdx, rdx
            inc         r9
            div         r10         ;quotient rax - remainder rdx
            add         dl, '0' ;Se le suma el valor ascii al remainder
            lea         rcx, [rsi+8]
            sub         rcx, r9
            mov         byte [rcx], dl
            cmp         rax, 0
            jle         nc5
            jmp         nc1
nc5:        cmp         r11, 1          ;if es negativo
            jne         nc4
            inc         r9
            lea         rcx, [rsi+8]
            sub         rcx, r9
            mov         byte [rcx], 45  ;Pone el negativo
nc4:        ;mov         r8 ,r9          ; fi
            mov         byte [rsi], r9b ; guardar el tamanno del string
            inc         rsi
            lea         r11, [rsi+7]    ;contador
            mov         r10, r11
            sub         r10, r9
            mov         rax, 0
nc2:        ;mov         r10, r11
            ;add         r10, rax
            mov         al, byte [r10]
            mov         byte [rsi], al
            inc         r10
            inc         rsi
            cmp         r10, r11
            jl          nc2
            mov         byte [rsi], 0
            xor         rax, rax
            mov         rax, r9
            mov         rsp, rbp
            pop         rbp
            ret

;##########################################
;#   Entrada:
;#      rdi: numero de 16 bits. (Lo demas se ignora)
;#   Salida:
;#      rax: dualis
;#
;##########################################
numerus2dualis:
            mov         ax,di       ;hacking into CIA
            ret


;##########################################
;#   Entrada:
;#      rdi: numero de 16 bits. (Lo demas se ignora)
;#   Salida:
;#      rax: frctio (por convencion va aqui y no en pila (ver correos de K))
;#
;##########################################
numerus2fractio:
            push      rbp
            mov       rbp, rsp
            xor         rax,rax
            mov         ax, 1
            shl         rax, 16
            mov         ax,di
            mov         rsp, rbp
            pop         rbp
            ret

