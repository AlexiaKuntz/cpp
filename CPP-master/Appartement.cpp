#include <iostream>
using namespace std;
#include "Appartement.hpp"
#include <fstream>

// CONSTRUCTEURS //

Appartement::Appartement(){
  nb_pieces = 0;
  etage = 0;
  garage = 0;
  cave = 0;
  balcon = 0;
}

Appartement::Appartement(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref,numm) {

}

Appartement::Appartement(int prix, std::string adresse_biens, int ref_client, int num, int _nb_pieces,int _etage,bool _garage,bool _cave,bool _balcon) : Biens(prix, adresse_biens,ref_client,num) {
    nb_pieces=_nb_pieces;
    etage=_etage;
    garage=_garage;
    cave=_cave;
    balcon=_balcon;
}

Appartement::Appartement(const Appartement &source) {
  prix=source.getPrice();
  adresse=source.getAdress();
  ref=source.getRef();
  num=source.getNum();
  nb_pieces=source.getNbPieces();
  etage=source.getEtage();
  garage=source.getGarage();
  cave=source.getCave();
  balcon=source.getBalcon();
}

// Appartement::Appartement(const Biens &source) {
//   prix=source.prix;
//   adresse=source.adresse;
//   ref=source.ref;
//   num=source.num;
// }
// GETTERS AND SETTERS //


void Appartement::setNbPieces(int _nb_pieces) {
  nb_pieces=_nb_pieces;
}

void Appartement::setEtage(int _etage) {
  etage=_etage;
}

void Appartement::setGarage(bool _garage) {
  garage=_garage;
}

void Appartement::setCave(bool _cave) {
  cave=_cave;
}

void Appartement::setBalcon(bool _balcon) {
  balcon=_balcon;
}


int Appartement::getNbPieces() const{
    return nb_pieces;
}

bool Appartement::getGarage() const{
    return garage;  // 0 = false 1 = true
}

bool Appartement::getCave() const{
    return cave;
}

bool Appartement::getBalcon() const{
    return balcon;
}

int Appartement::getEtage() const {
    return etage;
}

// AFFICHAGE //

void Appartement::affiche() {
  Biens::affiche();
  std::cout << "type de bien : " << typeid(this).name() << ", nombre de pièces : " << nb_pieces << ", etage numero : " << etage << ", garage ? " << getGarage() << ", cave ? " << getCave() <<", balcon ? " << getBalcon() <<endl;
}

// SAUVEGARDE //

void Appartement::save(std::ofstream &f) {
    Biens::save(f);
    f << "Appartement \n";
    f << "nombre de pièces " <<nb_pieces << endl;
    f << "etage " << etage << endl;
    f << "garage " << garage << endl;
    f << "cave " << cave << endl;
    f << "balcon " << balcon << endl;

}
