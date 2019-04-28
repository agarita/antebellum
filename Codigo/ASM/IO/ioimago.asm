; To comply with the ABI standard, the integers and pointers are passed on registers

            global      ioimago
            global      legoimago
            global      scriboimago
            ;global      test
            section     .data
datavar:    dw          0      ; note the newline at the end

            section   .text
ioimago:
            call legoimago
            mov  rdi, rax                ;Guardo el resultado de legoimago
            call scriboimago
            mov       rax, 60                 ; system call for exit
            xor       rdi, rdi                ; exit code 0
            syscall


;Esta funcion no recibe nada y devuelve en rax el numero leido de stdin
legoimago:
            push      rbp
            mov       rbp, rsp
            sub       rsp, 2
            
            mov         rdi, 1                  ; file handle 1 is stdin
            lea         rsi, [rbp - 1]
            mov         rdx, 1                 ; number of bytes
            mov         rax, 0                  ; system call for read
            syscall                       ; invoke operating system to do the write
            xor         rax, rax
            ;mov         ax, word [rbp-2]   ;ESTA LINEA ES PARA QUE QUEDE EN WORD
            mov         al, byte [rbp-1]    ;ESTA ES PARA QUE SEA BYTE (COMO EN )
            add         rsp, 2
            mov         rsp, rbp
            pop         rbp
            ret


scriboimago:
            push        rbp
            mov         rbp, rsp
            sub         rsp, 2

            mov         [rbp - 1], rdi
            mov         rdi, 1                  ; file handle 1 is stdout
            lea         rsi, [rbp - 1]
            mov         rdx, rax
            mov         rax, 1                  ; system call for write
            ;mov        rsi, message            ; address of string to output
            mov         rdx, 1                 ; number of bytes
            syscall                           ; invoke operating system to do the write

            xor         rax, rax

            add         rsp, 2
            mov         rsp, rbp
            pop         rbp
            ret                        ; invoke operating system to exit


;revise el rsi y el rdi, deberia salvarlos xq los hueveo. Saludos

