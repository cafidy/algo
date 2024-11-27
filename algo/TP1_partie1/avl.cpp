#include "avl.h"
#include <fstream>


void noeud::affiche(){
    std::cout<<"cle :"<<cle;
}


noeud::~noeud(){
    delete(fg);
    delete(fd);
    delete(pere);
}


noeud::noeud(int x){
    cle=x;
}


AVL::AVL(noeud* r){
    this->r=r;
}

AVL::~AVL(){
    delete(r);
}

AVL::AVL(const char* filename, bool option){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "impossible d ouvrir le fichier" << std::endl;
        return;
    }
    
    int nombre;
    file >> nombre;
    int valeur;
    for (int i = 0; i < nombre; i++) {
        file >> valeur;
        noeud* z= new noeud(valeur);
        if (option)
        {
            insert_feuille(r,z);
        }
        else
        {
            insert_racine(valeur);
        }
        
        
    }   

}

void AVL::prefixe(noeud*x){
    if (x!=NULL)
    {
        x->affiche();
        prefixe(x->fg);
        prefixe(x->fd);
    }
}

int AVL::calculTaille(noeud* r) {
    if (r == nullptr) return 0;
    return 1 + calculTaille(r->fg) + calculTaille(r->fd);
}
void AVL::update_hauteur(noeud* o){
    if (o==r) o->h=0;
    if (o!=NULL)
    {
        o->h=o->pere->h+1;
        update_hauteur(o->fd);
        update_hauteur(o->fg);
        if (o->fd)
        {
            /* code */
        }
        
    }
    
}
void AVL::insert_racine(int v){
    noeud* o=new noeud(v);
    
    if (r->cle>v)
    {
        o->fd=r;
    }else{
        o->fg=r;
    }
    r->pere=o;
    update_hauteur(o);
}
void AVL::insert_feuille(noeud * racine, noeud* y) {
    noeud* pere = nullptr;
    while (racine != nullptr) {
        pere = racine;
        if (y->cle <= racine->cle) {
            racine = racine->fg;
        } else {
            racine = racine->fd;
        }
    }
    y->pere=pere;
    if (y->pere == nullptr) {
        r = y;
    } else {
        if (y->cle <= y->pere->cle) {
            y->pere->fg = y;  
        } else {
            y->pere->fd = y;
        }
        
    }
}



void AVL::rotate_droite(noeud* racine) {
    noeud* pere = r->pere;
    noeud* G = r->fg;  
    
    if (G == nullptr) return;  
    
    G->pere = pere;
    
    r->fg = G->fd;
    if (G->fd != nullptr) {
        G->fd->pere = r;
    }
    
    G->fd = r;
    r->pere = G;
    
    
    if (pere == nullptr) {
        racine = G;  
    } else {
        if (pere->fg == r) {
            pere->fg = G;  
        } else {
            pere->fd = G;  
        }
    }
}
void AVL::rotate_gauche(noeud* racine) {
    noeud* pere = r->pere;
    noeud* D = r->fd;  
    
    if (D == nullptr) return; 
   
    D->pere = pere;
    
    r->fd = D->fg;
    if (D->fg != nullptr) {
        D->fg->pere = r;
    }
    
    D->fg = r;
    r->pere = D;
    
    if (pere == nullptr) {
        racine = D;  
    } else {
        if (pere->fd == r) {
            pere->fd = D;  
        } else {
            pere->fg = D;  
        }
    }
}
void AVL::equilibre(){
    
}