; To comply with the ABI standard, the integers and pointers are passed on registers

            global      iodiem
            global      legodiem
            global      scribodiem

            ;global      test
            section     .data
datavar:    dq          0      ; note the newline at the end

            section   .text
iodiem:
            call legodiem
            mov  rdi, rax                ;Guardo el resultado de legodiem
            call scribodiem
            mov       rax, 60                 ; system call for exit
            xor       rdi, rdi                ; exit code 0
            syscall


;Esta funcion no recibe nada y devuelve en rax el numero leido de stdin
legodiem:
            push      rbp
            mov       rbp, rsp
            sub       rsp, 32

            mov         rdi, 1                  ; file handle 1 is stdin
            lea         rsi, [rbp - 32]
            ;mov         rsi, rbp
            ;sub         rsi, 8
            mov         rax, 0                  ; system call for read
            mov         rdx, 32                 ; number of bytes
            syscall                       ; invoke operating system to do the write
            mov         rdi, rsi


            call        catena2diem
            add         rsp, 32
            mov         rsp, rbp
            pop         rbp
            ret


global diem2catena
diem2catena:push      rbp
            mov       rbp, rsp
            xor         r9, r9      ;length
            mov         r10, 10     ;numero 10 fijo
            xor         r11, r11    ;es negativo?
            mov         rax, rdi
            cmp         rax, 0
            jge         nc1
            mov         r11, 1      ;indicamos que el numero es negativo
            neg         rdi
            xor         rax, rax
            mov         rax, rdi
nc1:        xor         rdx, rdx
            inc         r9
            div         r10         ;quotient rax - remainder rdx
            add         dl, '0' ;Se le suma el valor ascii al remainder
            lea         rcx, [rsi+32]
            sub         rcx, r9
            mov         byte [rcx], dl
            cmp         rax, 0
            jle         nc5
            jmp         nc1
nc5:        cmp         r11, 1
            jne         nc4
            inc         r9
            lea         rcx, [rsi+32]
            sub         rcx, r9
            mov         byte [rcx], 45
nc4:        lea         r11, [rsi+32] ;contador
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


scribodiem:
            push      rbp
            mov       rbp, rsp
            sub       rsp, 8
            mov         r9, 0
            mov         [rbp - 8] , r9 ;limpiar la pila (?)
            mov         rsi, rbp
            sub         rsi, 8
            push        rsi
            push        rdi
            call        diem2catena
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

global catena2diem
catena2diem:
            mov         r8, 31              ;Este es el contador del ciclo
            mov         r9, 1              ;Multiplicador del valor
            mov         r10, 0              ;Numero parseado
cn0:        cmp         r8, 0
            jl          cn3
            ;cmp         byte [rdi + r8], 10
            ;je          cn3
cn1:        cmp         byte [rdi + r8], 47
            jle         cn2
            cmp         byte [rdi + r8], 58
            jge         cn2
            xor         rax, rax
            mov         al, byte [rdi + r8]
            sub         al, 48
            mul         r9
            add         r10, rax
            mov         rax,r9
            mov         r11,5
            mul         r11
            shl         rax,1
            mov         r9,rax
cn2:        dec         r8
            jmp         cn0
cn3:        mov         rax, r10
            cmp         byte [rsi], 45
            jne         cn4
            mov         rax, r10
            neg         rax
            ;sub         rax, r10
cn4:        ret