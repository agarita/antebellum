            global      dualis2catena
            global      dualis2numerus
            global      dualis2fractio
            global      dualis2imago


            section     .data
constV:     db  9, "veridicus",0
constF:     db  10, "falsidicus",0
            section     .text

;##########################################
;#   Entrada:
;#      rdi: dualis (16 bits)
;#
;#   Salida:
;#      rax: numerus
;##########################################
dualis2numerus:
            xor         rax,rax
            cmp         di, 0
            je          dn1
            mov         ax, 1
dn1:        ret


;##########################################
;#   Entrada:
;#      rdi: dualis (16 bits)
;#      rsi: puntero a string a escribir
;##########################################
dualis2catena:
            xor         rax,rax
            xor         r10, r10
            lea         r9, [constV]
            cmp         di, 0
            je          dc1
            lea         r9, [constF]
dc1:        cmp         r10b, byte [r9]
            jg         dc2
            mov         r11b , byte [r9 + r10]
            mov         byte [rsi + r10], r11b
            inc         r10b
            jmp         dc1
dc2: ret

;##########################################
;#   Entrada:
;#      rdi: dualis (16 bits)
;#   Salida:
;#      rax: imago
;#
;##########################################
dualis2imago:
            xor         rax,rax
            mov         al, 'V'
            cmp         di, 0
            je          di1
            mov         al, 'F'
di1:        ret


;##########################################
;#   Entrada:
;#      rdi: dualis (16 bits)
;#   Salida:
;#      rax: frctio (por convencion va aqui y no en pila (ver correos de K))
;#
;##########################################
dualis2fractio:
            xor         rax,rax
            mov         al, 1
            shl         rax, 16
            cmp         di, 0
            jne         df
            mov         al, 1
df:         ret

