/************************************************************************/
/* Auteur : S. Gueye							*/
/* TP : Transformation d'un arbre binaire quelconque en arbre binaire	*/
/* de recherche								*/
/* Date dernière maj : 20/12/2019					*/
/************************************************************************/

#include <iostream>
#include "AB.h"

using namespace std;

/****************************************/
/* Objectif : Constructeur d'un noeud dont les fils sont NULL
/* Entrées : entier x
/* Complexité : 0(1)
/****************************************/
noeud::noeud(int x)
{
	cle = x;
	fg = fd = pere =  NULL;
}

/****************************************/
/* Objectif : Constructeur d'un noeud de fils donnés
/* Entrées : entier x, fg, fd
/* Complexité : 0(1)
/****************************************/
noeud::noeud(int x, noeud* fg, noeud* fd)
{
	cle = x;
	this->fg = fg;
	this->fd = fd;
}

/****************************************/
/* Objectif : Destructeur d'un noeud
/****************************************/
noeud::~noeud()
{
	if(fg)
		delete(fg);
	if(fd)
		delete(fd);
}

/****************************************/
/* Objectif : Constructeur d'un AB
/****************************************/
AB::AB(noeud* x)
{
	r = x;	
	k=0;
}

/****************************************/
/* Objectif : Destructeur d'un AB
/****************************************/
AB::~AB()
{
	if(r)
		delete(r);
}

/****************************************/
/* Objectif : Accesseur à la racine r
/****************************************/
noeud* AB::root()
{
	return(r);
}

/****************************************/
/* Objectif : Parcours infixe
/****************************************/
void AB::AfficheT()
{
	n = N(r);
	cout << "T = ";
	
	for(int i = 0; i < n; i++)
		cout << T[i] << " ";
	
	cout << endl;
}


/****************************************/
/* Objectif : Parcours prefixe
/****************************************/
void AB::Prefixe(noeud* x)
{
	if(x){
		cout << " " << x->cle;
		Prefixe(x->fg);
		Prefixe(x->fd);
	}
}

/****************************************/
/* Objectif : Parcours postfixe
/****************************************/
void AB::Postfixe(noeud* x)
{
	if(x){
		Postfixe(x->fg);
		Postfixe(x->fd);
		cout << " " << x->cle;
	}
}

/****************************************/
/* Objectif : Parcours infixe
/****************************************/
void AB::Infixe(noeud* x)
{
	if(x){
		Infixe(x->fg);
		cout << " " << x->cle;
		Infixe(x->fd);
	}
}


/****************************************/
/* Objectif : Nombre d'éléments de l'arbre
/****************************************/
int AB::N(noeud* x)
{
    if (x!=NULL)
	{
		return n + 1 +N(x->fd) +N(x->fg);
	}else
	{
		return 0;
	}
}



/****************************************/
/* Objectif : Hauteur de l'arbre de racine x
/****************************************/
int AB::Hauteur(noeud* x)
{
	int res, resfg, resfd;

	res = resfg = resfd = -1;

	if(x){
		resfg = Hauteur(x->fg);
		resfd = Hauteur(x->fd);

		if(resfg > resfd)	
			res = resfg+1;
		else
			res = resfd+1;
	}

	return(res);
}

void AB::stock(noeud *x){
	if (x!=NULL)
	{
		T[k]=x->cle;
		k+=1;
		if (x->fd!=NULL)
		{
			dr++;
		}
		if (x->fg!=NULL)
		{
			gu++;
		}
		
		stock(x->fg);
		stock(x->fd);	
	}
}
/****************************************/
/* Objectif : Stocker dans T les valeurs 
/* de l'arbre triées en ordre croissant
/****************************************/
void AB::Tri() {
    stock(r);

    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i-1 ; j++) {
            if (T[j] > T[j + 1]) {
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

/****************************************/
/* Objectif : Transformation d'un arbre binaire de racine x
/* en un arbre binaire de recherche contenant les mêmes 
/* valeurs et ayant la même structure
/****************************************/
void AB::remplirArbre(noeud* x) {
    if (!x) return; // Si le nœud est nul, retour
    remplirArbre(x->fg);   // Parcours du sous-arbre gauche
    x->cle = T[k++];        // Remplacement de la clé par la valeur triée
    remplirArbre(x->fd);   // Parcours du sous-arbre droit
}
void AB::ABtoABR(noeud* x) {
    // Étape 1 : Stocker les valeurs de l'arbre dans le tableau T
    k = 0; // Initialisation de l'index pour remplir le tableau
    stock(x);

    // Étape 2 : Trier les valeurs du tableau T
    Tri();

    // Étape 3 : Réinsérer les valeurs triées dans l'arbre
    k = 0; // Réinitialisation de l'index pour réinsertion
    remplirArbre(x);
}


