all: compile

pr.o: pr.asm
	nasm -f elf64 pr.asm

compile: pr.o
	gcc pr.c pr.o && ./a.out
