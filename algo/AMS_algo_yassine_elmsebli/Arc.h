
#define ARC_H

#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

class Noeud;

class Arc
{
    std::string id ;
    Noeud *villed;
    Noeud *villea;
    std::string type ;
    bool onoway;
    bool es;
    int distance ;
    
    public :
        Arc(std::string id) ;
        Arc(std::string id, std::string type , bool one,int distance);
        //~Arc() ;
        void affiche() ;

} ;