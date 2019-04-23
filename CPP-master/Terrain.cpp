#include <iostream>
using namespace std;
#include "Terrain.hpp"


// CONSTRUCTEURS //

Terrain::Terrain() {

}

Terrain::Terrain(int prixx, std::string adress, int ref, int numm) :Biens(prixx,adress,ref,numm) {

}

Terrain::Terrain(bool _constructible) {
    constructible = _constructible;
}


// GETTERS ET SETTERS

void Terrain::setConstructible(bool _constructible) {
  constructible=_constructible;
}

bool Terrain::getConstructible() {
    return constructible;
}


// SAUVEGARDE //

void Terrain::save(std::ofstream &f) {
    Biens::save(f);
    f << "Terrain \n";
    f << "Constructible ? :" <<constructible << endl;


}

// void Terrain::save_terrain() {
//     std::ofstream ofs=Biens::save();
//     ofs << "constructible " << constructible << endl;
//     ofs <<"type de biens "<< "t" << endl;
// }
