#ifndef MAISON_HPP
#define MAISON_HPP

#include <iostream>
#include "Biens.hpp"
using namespace std;

class Maison : public Biens{
private:
    int nb_pieces;
    bool garage;
    bool jardin;
    bool piscine;

public:
    Maison();
    Maison(int prixx, std::string adress, int ref, int numm);
    Maison(int nb_pieces,bool garage,bool jardin,bool pisicne);
    // void create_maison();

    void setNbPieces(int);
    void setGarage(bool);
    void setJardin(bool);
    void setPiscine(bool);

};

#endif
