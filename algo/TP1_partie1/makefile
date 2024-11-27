all: main

main: main.o avl.o
	g++ -o main main.o avl.o

main.o: main.cpp
	g++ -c main.cpp 

KNIGHT.o: avl.cpp avl.h
	g++ -c avl.cpp 

clean:
	rm -f *.o main
