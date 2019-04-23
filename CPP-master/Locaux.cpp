#include <iostream>
using namespace std;
#include "Locaux.hpp"


// CONSTRUCTEURS //

Locaux::Locaux() {
  taille_vitrine = 0;
  stocker = 0;
}

Locaux::Locaux(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref, numm) {

}

Locaux::Locaux(int m_taille_vitrine, bool m_stocker) {
    taille_vitrine = m_taille_vitrine;
    stocker = m_stocker;
}


// GETTERS AND SETTERS //


void Locaux::setTailleVitrine(int _taille) {
  taille_vitrine=_taille;
}

void Locaux::setStocker(bool _stocker) {
  stocker=_stocker;
}

int Locaux::getTaille() const {
    return taille_vitrine;
}

bool Locaux::getStock() const {
    return stocker;
}

// SAUVEGARDE //

void Locaux::save(std::ofstream &f) {
    Biens::save(f);
    f << "Local \n";
    f << "taille vitrine :" <<taille_vitrine << endl;
    f << "piece pour stocker :" << stocker << endl;


}

// void Locaux::save_locaux() {
//     std::ofstream ofs=Biens::save();
//     ofs << "taille_vitrine" << taille_vitrine << endl;
//     ofs << "stocker " << stocker << endl;
//     ofs <<"type de biens "<< "l" << endl;
// }
