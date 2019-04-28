            global      imago2catena
            global      imago2numerus
            global      imago2fractio
            global      imago2dualis


            section     .data

            section     .text

;##########################################
;#   Entrada:
;#      rdi: char (8bits)
;#
;#   Salida:
;#      rax: numerus
;##########################################
imago2numerus:
            xor         rax,rax
            mov         al,dil
            ret


;##########################################
;#   Entrada:
;#      rdi: char (8bits)
;#      rsi: puntero a string a escribir
;##########################################
imago2catena:
            mov         byte [rsi], 1
            mov         byte [rsi+1], dil
            ret

;##########################################
;#   Entrada:
;#      rdi: char (8bits)
;#   Salida:
;#      rax: dualis
;#
;##########################################
imago2dualis:
            xor         rax, rax
            cmp         rdi, 'v'
            je          id1
            cmp         rdi, 'V'
            jne         id2
id1:        mov         rax, 1
id2:        ret


;##########################################
;#   Entrada:
;#      rdi: char (8bits)
;#   Salida:
;#      rax: frctio (por convencion va aqui y no en pila (ver correos de K))
;#
;##########################################
imago2fractio:
            push      rbp
            mov       rbp, rsp
            xor         rax,rax
            mov         al, 1
            shl         rax, 16
            mov         al,dil
            mov         rsp, rbp
            pop         rbp
            ret

