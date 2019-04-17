#include <iostream>
using namespace std;
#include "Appartement.hpp"

Appartement::Appartement(){}

Appartement::Appartement(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref,numm) {

}

Appartement::Appartement(int prix, std::string adresse_biens, int num, int ref_client, int _nb_pieces,int _etage,bool _garage,bool _cave,bool _balcon) : Biens(prix, adresse_biens,ref_client,num) {
    nb_pieces=_nb_pieces;
    etage=_etage;
    garage=_garage;
    cave=_cave;
    balcon=_balcon;
}

// void Appartement::create_appartement() {
//     int nb_apparts;
//     std::cout << "combien d'appartement voulez vous ?" << '\n';
//     std::cin >> nb_apparts;
//     for (int i=0;i<=nb_apparts; i++) {
//         std::cout << "combien de pièces ?" << '\n';
//         std::cin >> nb_pieces;
//         std::cout << "A quel étage ?" << '\n';
//         std::cin >> etage;
//         std::cout << "voulez-vous un garage ? false/true" << '\n';
//         std::cin >> garage;
//         std::cout << "voulez-vous une cave ? false/true" << '\n';
//         std::cin >> cave;
//         std::cout << "voulez-vous un balcon ? false/true" << '\n';
//         std::cin >> balcon;
//
//     }
// }


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
