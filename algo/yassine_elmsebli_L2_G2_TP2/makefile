all: main

main: main.o tp2.o
	g++ -o main main.o tp2.o

main.o: main.cpp
	g++ -c main.cpp 

KNIGHT.o: tp2.cpp tp2.h
	g++ -c tp2.cpp 

clean:
	rm -f *.o main
