#include <iostream>
using namespace std;
#include "Biens.hpp"
#include "Locaux.hpp"
#include "Maison.hpp"
#include "Appartement.hpp"
#include "Terrain.hpp"

// CONSTRUCTEURS //

Biens::Biens() {
    prix=0;
    adresse="unknown";
    ref=0;
    num=0;
}

Biens::Biens(int _prix,std::string _adresse_biens,int _ref_client,int _num) {
    prix=_prix;
    adresse=_adresse_biens;
    ref=_ref_client;
    num=_num;
}

// SETTERS ET GETTERS

void Biens::setPrice(int _prix) {
  prix=_prix;
}

void Biens::setAdress(std::string _adress) {
  adresse=_adress;
}

void Biens::setRef(int _ref) {
  ref=_ref;
}

void Biens::setNum(int _num) {
  num=_num;
}

int Biens::getPrice() const {
  return prix;
}

std::string Biens::getAdress() const {
  return adresse;
}

int Biens::getRef() const {
  return ref;
}

int Biens::getNum() const {
  return num;
}

// SURCHARGE D'OPERATEURS //

bool Biens::operator <(const Biens& x) const {
    return num < x.num;
}

bool Biens::operator ==(const Biens& x) const {
    return num == x.num;
}

// AFFICHAGE //

void Biens::affiche() {
  cout << "Bien numéro " << num << " :\n" <<
  "Adresse : " << adresse << ", prix : " << prix << ", référence client vendeur : " << ref << endl;

}

// SAUVEGARDE //

std::ofstream Biens::save() {
    std::ofstream ofs;
    ofs.open("Biens.txt", std::ofstream::out | std::ofstream::app);
    ofs <<"prix "<< prix << endl;
    ofs <<"adresse du bien "<< adresse << endl;
    ofs <<"reference du client " << ref << endl;
    return ofs;
}
