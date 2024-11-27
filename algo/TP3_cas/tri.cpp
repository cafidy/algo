#include <iostream>
#include <fstream>
#include <algorithm>
#include "tri.h"

using namespace std;

/****************************************/
/* Objectif : Constructeur
/* Complexité : 0(n)
/****************************************/
tri::tri(char* filename){
	ifstream file(filename);

	file >> n;
	file >> k;  

	T = new int[n];	

	for(int i = 0; i < n ; i++)
		file >> T[i];	
	
	file.close();
}


/****************************************/
/* Objectif : Affiche
/* Complexité : 0(n)
/****************************************/
void tri::affiche()
{
	for(int i = 0; i < n; i++)
		cout << " " <<  T[i];
	cout << endl;
}

/****************************************/
/* Objectif : Tri
/* Complexité : 0(n + k)
/****************************************/
void tri::triDenombrement()
{
        int maxElement = T[0];
    for (int i = 1; i < n; i++) {
        if (T[i] > maxElement) {
            maxElement = T[i];
        }
    }

    // Étape 2 : Créer un tableau de comptage avec une taille de maxElement + 1
    int *count = new int[maxElement + 1];

    // Initialiser le tableau de comptage avec des zéros sans utiliser memset
    for (int i = 0; i <= maxElement; i++) {
        count[i] = 0;
    }

    // Étape 3 : Compter les occurrences de chaque élément
    for (int i = 0; i < n; i++) {
        count[T[i]]++;
    }

    // Étape 4 : Reconstruire le tableau trié
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            T[index++] = i;
            count[i]--;
        }
    }

    // Libérer la mémoire allouée pour le tableau de comptage
    delete[] count;
}
