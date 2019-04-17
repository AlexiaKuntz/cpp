#include <iostream>
using namespace std;
#include "Locaux.hpp"

Locaux::Locaux(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref, numm) {

}

Locaux::Locaux(int m_taille_vitrine, bool m_stocker) {
    taille_vitrine = m_taille_vitrine;
    stocker = m_stocker;
}

void Locaux::create_locaux() {
    int nb;

    std::cout << "combien de locaux voulez vous ?" << '\n';
    std::cin >> nb;
    for (int i=0;i<=nb; i++) {
        std::cout << "quelle taille vitrine ?" << '\n';
        std::cin >> taille_vitrine;
        std::cout << "voulez-vous une piece pour stocker ? false/true" << '\n';
        std::cin >> stocker;
    }

}


void Locaux::setTailleVitrine(int _taille) {
  taille_vitrine=_taille;
}

void Locaux::setStocker(bool _stocker) {
  stocker=_stocker;
}
