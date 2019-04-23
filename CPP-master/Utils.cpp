#include "Utils.h"
#include <iostream>
#include <limits>
using namespace std;

bool getTrueBool() {
    // std::cout << "Entrez un 0 pour un Non et 1 pour Oui" << endl;
    int choix;
    cin >> choix;
    cin.ignore(); // la fonction accepte 1 caractere
    if(choix == 0 || choix == 1) {
        return true;
    }
    else {
        std::cout << "Entrez non valide, 0--> non ou 1 --> oui." << endl;
        return getTrueBool();
    }
}

int getInt() {
    int value;
    cin >> value;
    cin.ignore();
    if (cin.fail()) { // return true si il y a une erreur ou qu ela derniere operation a échoué
        cout << "Entrée non valide. Veuillez entrer un entier." << endl;
        cin.clear(); // définir l'état d'un flux
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return getInt();
    }
    return value;
}
