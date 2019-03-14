CC         = -gcc
GCC        = -g++

TOP = $(shell pwd)
COVERAGE = $(TOP)/coverage

CFLAGS = \
	-std=c++17 \
	-lm \
	-ftest-coverage \
	-fprofile-arcs

OBJECT = main.o

all: main valgrind coverage

clean:
	rm  *.o

main.o: main.cpp
	g++ -c main.cpp $(CFLAGS)

main: main.cpp
	g++ -o out $(CFLAGS) main.cpp
valgrind:
	valgrind  ./out
coverage: $(OBJECT)
	gcov -d $@ $(OBJECT)
	rm *.gcno *.gcda
	mv *.gcov $(COVERAGE)


#Компиляция динамической библиотеки
dynamic_build: $(OBJECTS) libdynamic.so
	g++ -o dynamic_build $(INCLUDES) $(OBJECTS) -L. -ldynamic -Wl,-rpath,.
libdynamic.so: $(OBJECTS)
	g++ -shared -o libdynamic.so $(OBJECTS)
