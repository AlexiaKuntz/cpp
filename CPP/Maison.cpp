#include <iostream>
using namespace std;
#include "Maison.hpp"

Maison::Maison(){}

Maison::Maison(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref,numm) {

}


Maison::Maison(int _nb_pieces,bool _garage,bool _jardin,bool _piscine) {
    nb_pieces=_nb_pieces;
    garage=_garage;
    jardin=_jardin;
    piscine=_piscine;
}

// void Maison::create_maison() {
//     int nb;
//
//     std::cout << "combien de maison voulez vous ?" << '\n';
//     std::cin >> nb;
//     for (int i=0;i<=nb; i++) {
//         std::cout << "combien de pièces ?" << '\n';
//         std::cin >> nb_pieces;
//         std::cout << "voulez-vous un garage ? false/true" << '\n';
//         std::cin >> garage;
//         std::cout << "voulez-vous un jardin ? false/true" << '\n';
//         std::cin >> jardin;
//         std::cout << "voulez-vous une piscine ? false/true" << '\n';
//         std::cin >> piscine;
//     }
//
// }


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
