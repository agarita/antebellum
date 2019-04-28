; To comply with the ABI standard, the integers and pointers are passed on registers

            global      iocatena
            global      legocatena
            global      scribocatena
            global      trimcatena
            ;global      test
            section     .data
datavar:    times 4 dd 0      ; Es de 32 bytes (El primero es para el tamanio)

            section   .text
iocatena:
            lea  rdi, [datavar]
            call legocatena
            lea  rdi, [datavar]
            call scribocatena
            mov       rax, 60                 ; system call for exit
            xor       rdi, rdi                ; exit code 0
            syscall


;Esta funcion no recibe nada y devuelve en rax el numero leido de stdin
legocatena:
            push      rbp
            mov       rbp, rsp
            ;sub       rsp, 2
            
            mov         rsi, rdi
            inc         rsi
            mov         rdi, 1                  ; file handle 1 is stdin
            mov         rdx, 31                 ; number of bytes
            mov         rax, 0                  ; system call for read
            syscall                       ; invoke operating system to do the write


            lea         rdi, [rsi-1]
            call        trimcatena

            xor         rax, rax
            ;mov         ax, word [rbp-2]   ;ESTA LINEA ES PARA QUE QUEDE EN WORD
            ;mov         al, byte [rbp-1]    ;ESTA ES PARA QUE SEA BYTE (COMO EN )
            ;add         rsp,
            mov         rsp, rbp
            pop         rbp
            ret

trimcatena: push        rbp
            mov         rbp, rsp

            mov         r9, 0
tc1:        cmp         byte [rdi+r9+1], 10
            je          tc2
            inc         r9
            jmp         tc1
tc2:        mov         byte [rdi], r9b
            mov         rsp, rbp
            pop         rbp
            ret


scribocatena:
            push        rbp
            mov         rbp, rsp

            mov         r9, rdi
            lea         rsi, [r9 + 1]
            mov         rdi, 1                  ; file handle 1 is stdout
            mov         rax, 1                  ; system call for write
            ;mov        rsi, message            ; address of string to output
            xor         rdx, rdx
            mov         dl, byte [r9]                 ; number of bytes
            syscall                           ; invoke operating system to do the write

            xor         rax, rax

            mov         rsp, rbp
            pop         rbp
            ret                        ; invoke operating system to exit


;revise el rsi y el rdi, deberia salvarlos xq los hueveo. Saludos

