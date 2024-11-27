all: main

main: main.o Arc.o Graphe.o Noeud.o
	g++ -o main main.o Arc.o Graphe.o Noeud.o

main.o: main.cpp
	g++ -c main.cpp 

Arc.o: Arc.cpp Arc.h Noeud.h
	g++ -c Arc.cpp

Noeud.o: Noeud.cpp Noeud.h Arc.h
	g++ -c Noeud.cpp

Graphe.o: Graphe.cpp Graphe.h Noeud.h Arc.h
	g++ -c Graphe.cpp  

clean:
	rm -f *.o main
