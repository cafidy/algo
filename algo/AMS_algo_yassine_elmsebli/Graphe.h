#define Graphe_H

#include"Arc.h"

class Noeud ;
class Arc ;

class Graphe
{
    std::vector<Noeud*> ville;
    std::vector<Arc*> route;
    int nnoeud;
    int narc;
    std::string file_arc;
    std::string file_noeud;
    public:
        Graphe(std::string file_arc,std::string fie_noeud);
        //~Graphe();
        //void affiche();
        int lecture_arc();
} ;