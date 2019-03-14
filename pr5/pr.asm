global testf
section .text
testf:
mov r13, rdi
mov r14, rsi
mov r15, rdx
imul r8, r14, 2
mov r9, r13
sub r9, r8
mov rax, r9
xor rdx, rdx
idiv r15

ret 
