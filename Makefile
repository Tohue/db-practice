CC         = -gcc
GCC        = -g++

TOP = $(shell pwd)
SRCDIR = $(TOP)/src
INCDIR = $(TOP)/include

SOURCES = \
	$(wildcard $(SRCDIR)/*.cpp )

COVERAGE = $(TOP)/coverage

UNITTEST = $(SRCDIR)/unittest/unittest.cpp

INCLUDES = \
	-I$(INCDIR)

CFLAGS = \
	-std=c++17 \
	-lm \
	-ftest-coverage \
	-fprofile-arcs

OBJECTS = main.o base.o OEF.o interact.o

all: OEFdb unittest cppcheck $(OBJECTS) valgrind coverage static_build dynamic_build

OEFdb:$(SOURCES)
	$(GCC) -o $@ $^ $(INCLUDES) $(CFLAGS)
unittest: $(UNITTEST) $(SRCDIR)/OEF.cpp
	g++ -o unittest $(INCLUDES) $(UNITTEST) $(SRCDIR)/OEF.cpp
	./unittest
cppcheck:
	cppcheck --enable=all --language=c++ $(SOURCES) $(INCLUDES)
clean:
	rm  *.o *.a *.so unittest OEFdb static_build  dynamic_build

main.o: $(SRCDIR)/main.cpp
	g++ -c $(INCLUDES) $(SRCDIR)/main.cpp
base.o: $(SRCDIR)/base.cpp
	g++ -c -fPIC $(INCLUDES) $(SRCDIR)/base.cpp
OEF.o: $(SRCDIR)/OEF.cpp
	g++ -c -fPIC $(INCLUDES) $(SRCDIR)/OEF.cpp
interact.o: $(SRCDIR)/interact.cpp
	g++ -c -fPIC $(INCLUDES) $(SRCDIR)/interact.cpp
valgrind:
	valgrind  ./OEFdb
coverage: $(OBJECTS)
	gcov -d $@ $(OBJECTS)
	rm *.gcno *.gcda
	mv *.gcov $(COVERAGE)
	#valgrind --tool=callgrind ./start
	#Компиляция статической библиотеки
static_build: $(OBJECTS) libstatic.a
	g++ -o static_build $(OBJECTS)  -L. -lstatic
libstatic.a: $(OBJECTS)
	ar cr libstatic.a $(OBJECTS)

#Компиляция динамической библиотеки
dynamic_build: $(OBJECTS) libdynamic.so
	g++ -o dynamic_build $(INCLUDES) $(OBJECTS) -L. -ldynamic -Wl,-rpath,.
libdynamic.so: $(OBJECTS)
	g++ -shared -o libdynamic.so $(OBJECTS)
