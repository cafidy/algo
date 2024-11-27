#include <iostream>

class noeud
{
	friend class AVL ;
	int cle ;
	int N ;
	int d ;
	int h ;
	noeud * fg ;
	noeud * fd ;
	noeud * pere ;
	public :
		noeud(int x) ;
		~noeud() ;
		void affiche() ;
} ;
class AVL
{
	int H;
	noeud * r ;
	public :
		AVL(noeud* r) ;
		~AVL() ;
		AVL(const char* filename, bool option);
		noeud* root() ;
		void prefixe(noeud* x) ;
		int calculTaille(noeud* r) ;
		void update_hauteur(noeud* o);
		void insert_racine(int y);
		void insert_feuille(noeud* racine, noeud* y);
		void rotate_droite(noeud* racine);
		void rotate_gauche(noeud* racine);
		void equilibre();
};
