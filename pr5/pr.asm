;edi, esi, edx;
;(x+2*y+3*z)/4

format ELF64 

section '.text' executable

public testf
testf:
        imul esi, 2
        imul edx, 3
        add esi, edx
        add edi, esi
        mov eax, edi


        mov edx, 0
        mov esi, 4
        cdq
        idiv esi

        ret