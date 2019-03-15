test:
	fasm pr.asm pr.o 
	g++ -no-pie -c -fPIC pr.cpp -o out.o   
	g++ -o test out.o pr.o 
	./test