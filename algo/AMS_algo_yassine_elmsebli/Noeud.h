
#define NOEUD_H

#include"Arc.h"

class Arc;

class Noeud
{
    std::string id ;
    std::vector<Arc> arc_e;
    std::vector<Arc> arc_s;
    public :
        Noeud(std::string id) ;
        void add_arc_e(Arc e);
        void add_arc_s(Arc s);
        //~Noeud() ;
        void affiche() ;
} ;