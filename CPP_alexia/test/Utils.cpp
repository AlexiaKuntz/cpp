#include "Utils.h"
#include <iostream>
#include <limits>

bool Utils::getTrueBool() {
    std::cout << "Entrez un 0 pour un non et 1 ou autre entier pour Oui" << endl;
    int choix;
    cin >> choix; 
    cin.ignore(); // la fonction accepte 1 caractere
    if(choix == 0 || choix == 1) {
        return true;
    }
    else {
        std::cout << "Entrez non valide" << endl;
        return getTrueBool();
    }
}

int Utils::getInt() {
    int value;
    cin >> value;
    cin.ignore();
    if (cin.fail()) { // return true si il y a une erreur ou qu ela derniere operation a échoué
        cout << "Ceci n'est pas un entier ..." << endl;
        cin.clear(); // définir l'état d'un flux
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return getInt();
    }
    return value;
}

