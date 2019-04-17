#include <iostream>
using namespace std;
#include "Terrain.hpp"

Terrain::Terrain() {

}

Terrain::Terrain(int prixx, std::string adress, int ref, int numm) :Biens(prixx,adress,ref,numm) {

}

Terrain::Terrain(bool _constructible) {
    constructible = _constructible;
}

// void Terrain::create_terrain() {
//     int nb;
//     std::cout << "combien de locaux voulez vous ?" << '\n';
//     std::cin >> nb;
//     for (int i=0;i<=nb; i++) {
//         std::cout << "voulez-vous un terrain constructibe ? false/true" << '\n';
//         std::cin >> constructible;
//     }
//
// }

void Terrain::setConstructible(bool _constructible) {
  constructible=_constructible;
}
