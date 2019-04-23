#include <iostream>
using namespace std;
#include "Maison.hpp"

// CONSTRUCTEURS //

Maison::Maison(){

}

Maison::Maison(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref,numm) {

}


Maison::Maison(int _nb_pieces,bool _garage,bool _jardin,bool _piscine) {
    nb_pieces=_nb_pieces;
    garage=_garage;
    jardin=_jardin;
    piscine=_piscine;
}


// GETTERS ET SETTERS


void Maison::setNbPieces(int _nb_pieces) {
  nb_pieces=_nb_pieces;
}

void Maison::setGarage(bool _garage) {
  garage=_garage;
}

void Maison::setJardin(bool _jardin) {
  jardin=_jardin;
}

void Maison::setPiscine(bool _piscine) {
  piscine=_piscine;
}

int Maison::getNbPieces() const{
    return nb_pieces;
}

bool Maison::getGarage() const {
    return garage;
}

bool Maison::getJardin() const {
    return jardin;
}

bool Maison::getPiscine() const {
    return piscine;
}


// SAUVEGARDE //

void Maison::save(std::ofstream &f) {
    Biens::save(f);
    f << "Maison\n";
    f << "nombre de pièces :" <<nb_pieces << endl;
    f << "garage :" << garage << endl;
    f << "jardin :" << jardin << endl;
    f << "piscine :" << piscine << endl;

}

// void Maison::save_maison() {
//     std::ofstream ofs=Biens::save();
//     ofs << "nombre de pièces " << nb_pieces << endl;
//     ofs << "garage " << garage << endl;
//     ofs << "jardin " << jardin << endl;
//     ofs << "piscine " << piscine << endl;
//     ofs <<"type de biens "<< "m" << endl;
// }
