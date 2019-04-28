; To comply with the ABI standard, the integers and pointers are passed on registers

            global      iodualis
            global      legodualis
            global      scribodualis
            extern      legonumerus
            extern      scribonumerus
            ;global      test
            section     .data
datavar:    dw          0      ; note the newline at the end

            section   .text
iodualis:
            call legodualis
            mov  rdi, rax                ;Guardo el resultado de legodualis
            call scribodualis
            mov       rax, 60                 ; system call for exit
            xor       rdi, rdi                ; exit code 0
            syscall


;Esta funcion no recibe nada y devuelve en rax el numero leido de stdin
legodualis:
            call    legonumerus
            ret


scribodualis:
            call    scribonumerus
            ret                        ; invoke operating system to exit
