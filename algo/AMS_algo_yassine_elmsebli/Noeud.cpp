#include "Noeud.h"

Noeud::Noeud(std::string id){
    this->id=id;
}
void Noeud::add_arc_e(Arc e){
    arc_e.push_back(e);
}
void Noeud::add_arc_s(Arc s){
    arc_s.push_back(s);
}
void Noeud::affiche(){
    std::cout<<"id ville :"<<this->id<<std::endl;
    for (int i = 0; i < arc_e.size(); i++)
    {
        arc_e[i].affiche();
    }
    for (int i = 0; i < arc_s.size(); i++)
    {
        arc_s[i].affiche();
    }
}