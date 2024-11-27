#include "Arc.h"

Arc::Arc(std::string id){
    this->id=id;
    this->distance=0;
    this->type=' ';
}
Arc::Arc(std::string id, std::string type , bool one,int distance){
    this->id=id;
    this->distance=distance;

    this->type=type;
    this->onoway=one;

}
void Arc::affiche(){
    std::cout<<"id : "<<this->id<<std::endl<<"distance :"<<this->distance<<std::endl;
}
