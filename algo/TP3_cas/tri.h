class tri{
	int* T;
	int n;	// Taille du tableau
	int k;	// Valeur maximale se trouvant dans le tableau
	friend class evaluate;
	public :
	tri(char* filename);
	void affiche();
	void triDenombrement();
};