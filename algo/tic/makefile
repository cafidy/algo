all: main

main: main.o tic.o
	g++ -o main main.o tic.o

main.o: main.cpp
	g++ -c main.cpp 

tic.o: tic.cpp tic.h
	g++ -c tic.cpp 

clean:
	rm -f *.o main
