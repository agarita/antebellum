; To comply with the ABI standard, the integers and pointers are passed on registers

            global      ionumerus
            global      legonumerus
            global      scribonumerus
            extern      catena2numerus
            extern      numerus2catena
            ;global      test
            section     .data
datavar:    dw          0      ; note the newline at the end

            section   .text
ionumerus:
            call legonumerus
            mov  rdi, rax                ;Guardo el resultado de legonumerus
            call scribonumerus
            mov       rax, 60                 ; system call for exit
            xor       rdi, rdi                ; exit code 0
            syscall


;Esta funcion no recibe nada y devuelve en rax el numero leido de stdin
legonumerus:
            push      rbp
            mov       rbp, rsp
            sub       rsp, 8
            mov         r9, 0
            mov         [rbp - 8], r9           ;limpiar la pila
            mov         rdi, 1                  ; file handle 1 is stdin
            lea         rsi, [rbp - 8]
            ;mov         rsi, rbp
            ;sub         rsi, 8
            mov         rax, 0                  ; system call for read
            mov         rdx, 8                 ; number of bytes
            syscall                       ; invoke operating system to do the write
            mov         rdi, rsi
            call        catena2numerus
            add         rsp, 8
            mov         rsp, rbp
            pop         rbp
            ret





scribonumerus:
            push      rbp
            mov       rbp, rsp
            sub       rsp, 8
            mov         r9, 0
            mov         [rbp - 8] , r9 ;limpiar la pila (?)
            mov         rsi, rbp
            sub         rsi, 8
            push        rsi
            push        rdi
            call        numerus2catena
            pop         rdi
            pop         rsi

            mov       rdi, 1                  ; file handle 1 is stdout
            mov       rdx, rax
            mov       rax, 1                  ; system call for write
            ;mov       rsi, message            ; address of string to output
            ;mov       rdx, 13                 ; number of bytes
            syscall                           ; invoke operating system to do the write
            xor rax, rax
            add         rsp, 8
            mov         rsp, rbp
            pop         rbp
            ret                        ; invoke operating system to exit


;revise el rsi y el rdi, deberia salvarlos xq los hueveo. Saludos

