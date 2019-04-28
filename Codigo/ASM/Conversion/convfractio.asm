            global      fractio2catena
            global      fractio2imago
            global      fractio2numerus
            global      fractio2dualis

            extern      numerus2catena

            section     .data

            section     .text

;##########################################
;#   Entrada:
;#      rdi: puntero a fractio
;#
;#   Salida:
;#      rax: Char
;##########################################
fractio2imago:
            push        rbp
            mov         rbp, rsp
            xor         rdx,rdx
            xor         rax,rax
            mov         ax,[rdi]
            mov         r8, [rdi+2]
            div         r8
            mov         r8w, 256
            div         r8w
            xor         rax, rax
            mov         ax, dx
            mov         rsp, rbp
            pop         rbp
            ret


;##########################################
;#   Entrada:
;#      rdi: puntero a fractio
;#      rsi: puntero a string a escribir
;##########################################
fractio2catena:
            push        rbp
            mov         rbp, rsp
            push        rdi
            push        rsi
            mov         r8, rdi
            xor         rdi, rdi
            mov         di, word [r8+2]
            call        numerus2catena
            pop         rsi
            pop         rdi
            xor         r8,r8
            xor         r9,r9
            mov         r8b, byte [rsi]
fc1:        cmp         r8b, 0
            jl         fc2

            mov         r9b, byte [rsi + r8]
            push        r9
            dec         r8b
            jmp         fc1
fc2:        push        rdi
            push        rsi
            mov         r8, rdi
            xor         rdi, rdi
            mov         di, word [r8]
            call        numerus2catena
            pop         rsi
            pop         rdi
            xor         r8,r8
            xor         r9,r9
            xor         r10,r10
            inc         byte [rsi]
            mov         r8b, byte [rsi]
            mov         byte [rsi+r8],'|'
            pop         r9
            add         r8,r9
            mov         byte [rsi],r8b
            sub         r8,r9
fc3:        cmp         r9,0
            jl          fc4
            pop         r10
            inc         r8b
            mov         byte [rsi + r8],r10b
            dec         r9
            jmp         fc3
fc4:
            mov         rsp, rbp
            pop         rbp
            ret

;##########################################
;#   Entrada:
;#      rdi: puntero a fractio
;#   Salida:
;#      rax: dualis
;#
;##########################################
fractio2dualis:
            push        rbp
            mov         rbp, rsp
            xor         rdx,rdx
            xor         rax,rax
            mov         ax, word [rdi]
            cwd                             ;Esto es super importante, si no se despicha Tere
            mov         r8w, word [rdi+2]
            idiv        r8w
            mov         rsp, rbp
            pop         rbp
            ret



;##########################################
;#   Entrada:
;#      rdi: puntero a fractio
;#   Salida:
;#      rax: frctio (por convencion va aqui y no en pila (ver correos de K))
;#
;##########################################
fractio2numerus:
            push        rbp
            mov         rbp, rsp
            xor         rdx,rdx
            xor         rax,rax
            mov         ax, word [rdi]
            cwd                             ;Esto es super importante, si no se despicha Tere
            mov         r8w, word [rdi+2]
            idiv        r8w
            ;mov         r8w, 256
            ;div         r8w
            ;xor         rax, rax
            ;mov         ax, dx
            mov         rsp, rbp
            pop         rbp
            ret

