; To comply with the ABI standard, the integers and pointers are passed on registers

            global      iofractio
            global      legofractio
            global      scribofractio
            extern      legonumerus
            extern      scribonumerus
            ;global      test
            section     .data
datavar:    dw          0   ;
            dw          1   ;Se inicializa en 0 sobre 1 porque no se puede dividir entre 0
pipe:       db          124

            section   .text
iofractio:  lea         rdi, [datavar]
            call        legofractio
            lea         rdi, [datavar]
            call        scribofractio
            mov         rax, 60                 ; system call for exit
            xor         rdi, rdi                ; exit code 0
            ;syscall
            ret


legofractio:
            push        rbp
            mov         rbp, rsp

            push        rdi
            call        legonumerus
            mov         r9, rax
            push        r9
            call        legonumerus
            mov         r10, rax
            pop         r9
            pop         rdi
            mov         word [rdi], r9w
            mov         word [rdi+2], r10w


            ;Esto que sigue que esta comentado era la funcion como estaba anteriormente, por alguna razon
            ;tiene alguna pulga, lo de arriba funciona bien
            ;push        rdi
            ;call        legonumerus
            ;pop         rdi
            ;mov         word [rdi], ax
            ;push        rdi
            ;call        legonumerus
            ;pop         rdi
            ;mov         word [rdi+2], ax

            xor         rax, rax
            mov         rsp, rbp
            pop         rbp
            ret


scribofractio:
            push        rbp
            mov         rbp, rsp

            mov         r9, rdi
            push        r9
            xor         rdi, rdi
            mov         di, word [r9]
            call        scribonumerus


            mov         rdi, 1                  ; file handle 1 is stdout
            mov         rsi, pipe            ; address of string to output
            mov         rdx, 1                 ; number of bytes
            mov         rax, 1                  ; system call for write
            syscall

            pop     r9
            xor     rdi, rdi
            mov     di, word [r9+2]
            call    scribonumerus

            mov         rsp, rbp
            pop         rbp
            ret
