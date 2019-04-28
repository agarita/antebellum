; To comply with the ABI standard, the integers and pointers are passed on registers

            global      ioliber
            global      legoliber
            global      scriboliber
            extern      scribocatena
            extern      trimcatena
            ;global      test
            section     .data

datavar:    times 2 dq 0    ; 128 bytes Ruta y nombre
            dw      0       ; 1 word Handle.... Este handle es si es para abrir o leer o que?
            db      0       ; 1 byte estado
            times 34 db 0    ; 34 bytes de buffer


            section   .text
ioliber:
            lea  rdi, [datavar]
            call legoliber
            lea  rdi, [datavar]
            call scriboliber
            mov       rax, 60                 ; system call for exit
            xor       rdi, rdi                ; exit code 0
            syscall


;Esta funcion no recibe nada y devuelve en rax el numero leido de stdin
legoliber:
            push      rbp
            mov       rbp, rsp
            ;sub       rsp, 2
            
            mov         rsi, rdi
            inc         rsi
            mov         rdi, 1                  ; file handle 1 is stdin
            mov         rdx, 128                 ; number of bytes
            mov         rax, 0                  ; system call for read
            syscall                       ; invoke operating system to do the write


            lea         rdi, [rsi-1]
            call        trimcatena

            xor         rax, rax
            mov         rsp, rbp
            pop         rbp
            ret



scriboliber:
            call        scribocatena
            ret
            ;push        rbp
            ;mov         rbp, rsp
;
            ;mov         r9, rdi
            ;lea         rsi, [r9 + 1]
            ;mov         rdi, 1                  ; file handle 1 is stdout
            ;mov         rax, 1                  ; system call for write
            ;;mov        rsi, message            ; address of string to output
            ;xor         rdx, rdx
            ;mov         dl, byte [r9]                 ; number of bytes
            ;syscall                           ; invoke operating system to do the write
;
            ;xor         rax, rax
;
            ;mov         rsp, rbp
            ;pop         rbp
            ;ret                        ; invoke operating system to exit


;revise el rsi y el rdi, deberia salvarlos xq los hueveo. Saludos

