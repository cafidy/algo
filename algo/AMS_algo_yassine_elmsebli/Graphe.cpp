#include "Graphe.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


Graphe::Graphe(std::string file_arc,std::string file_noeud){
    this->file_arc=file_arc;
    this->file_noeud=file_noeud;
}

int Graphe::lecture_arc() {
    std::ifstream file(file_arc); 
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 0;
    }
    int number=0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string first, second, jsonField;
        number++;

        std::getline(lineStream, first, ',');
        std::getline(lineStream, second, ',');


        std::getline(lineStream, jsonField);


        std::string name, highway;
        double length = 0.0;
        bool oneway = false;
        


        auto namePos = jsonField.find("'name': ");
        if (namePos != std::string::npos) {
            auto start = jsonField.find("'", namePos + 8) + 1;
            auto end = jsonField.find("'", start);
            name = jsonField.substr(start, end - start);
        }


        auto lengthPos = jsonField.find("'length': ");
        if (lengthPos != std::string::npos) {
            auto start = lengthPos + 10;
            auto end = jsonField.find(",", start);
            length = std::stod(jsonField.substr(start, end - start));
        }


        auto onewayPos = jsonField.find("'oneway': ");
        if (onewayPos != std::string::npos) {
            auto start = onewayPos + 10;
            auto end = jsonField.find(",", start);
            std::string onewayValue = jsonField.substr(start, end - start);
            oneway = (onewayValue == "True");
        }
        
        auto highwayPos = jsonField.find("'highway': ");
        if (highwayPos != std::string::npos) {
            auto start = jsonField.find("'", highwayPos + 11) + 1;
            auto end = jsonField.find("'", start);
            highway = jsonField.substr(start, end - start);
        }

        Arc *nv=new Arc(name,highway,oneway,length);
        route.push_back(nv);
    }

    file.close();
    
}

