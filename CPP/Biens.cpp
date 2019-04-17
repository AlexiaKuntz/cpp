#include <iostream>
using namespace std;
#include "Biens.hpp"
#include "Locaux.hpp"
#include "Maison.hpp"
#include "Appartement.hpp"
#include "Terrain.hpp"

Biens::Biens() {
    prix=0;
    adresse_biens="unknown";
    ref_client=0;
    num=0;
}

Biens::Biens(int _prix,std::string _adresse_biens,int _ref_client,int _num) {
    prix=_prix;
    adresse_biens=_adresse_biens;
    ref_client=_ref_client;
    num=_num;
}

void Biens::setPrice(int _prix) {
  prix=_prix;
}

void Biens::setAdress(std::string _adress) {
  adresse_biens=_adress;
}

void Biens::setRef(int _ref) {
  ref_client=_ref;
}

void Biens::setNum(int _num) {
  num=_num;
}

int Biens::getPrice() {
  return prix;
}

std::string Biens::getAdress() {
  return adresse_biens;
}

int Biens::getRef() {
  return ref_client;
}

int Biens::getNum() {
  return num;
}


// Biens Biens::create_biens() { // le stocker dans un vector
//     int type;
//     std::string adress;
//     int ref;
//     int prixx;
//     int numm=0;
//
//     std::cout << "Quel type de biens voulez-vous ?" << '\n';
//     std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
//     std::cin >> type;
//     std::cout << "Quelle est l'adresse ?" << '\n';
//     std::cin >> adress;
//     std::cout << "Quelle est la référence ?" << '\n';
//     std::cin >> ref;
//     std::cout << "Quel est le prix ?" << '\n';
//     std::cin >> prixx;
//     numm++;
//     Biens *good=new Biens(prixx,adress,ref,numm);
//     switch (type) {
//         case 1: {Locaux *good=new Locaux(prixx, adress, ref, numm);good->create_locaux();}break;
//         case 2: {Maison *good=new Maison(prixx,adress,ref,numm); good->create_maison();}break;
//         case 3: {Terrain *good=new Terrain(prixx,adress,ref,numm); good->create_terrain();}break;
//         case 4: {Appartement *good=new Appartement(prixx,adress,ref,numm); good->create_appartement();}break;
//         // default: std::cout << "vous vous etes trompés. Recommencez." <<'\n';
//     }
//     return *good;
// }
//
// void Biens::vendre_biens() {
//     int type;
//     std::cout << "quel type de biens voulez-vous vendre ?" << '\n';
//     std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
//     std::cin >> type;
//     switch (type) {
//         case 1: void vendre_locaux();break;
//         case 2: void vendre_maison();break;
//         case 3: void vendre_terrain();break;
//         case 4: void vendre_appartement();break;
//         default : std::cout << "vous vous etes trompés. Recommencez." <<'\n';
//     }
// }



bool Biens::operator <(const Biens& x) const {
    return num < x.num;
}



void Biens::affiche() {
  cout << "\nBien numéro " << num << " :\n" <<
  "Adresse : " << adresse_biens << ", prix : " << prix << ", référence client : " << ref_client << endl;

}
