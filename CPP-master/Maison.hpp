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

    void save_maison();

    void setNbPieces(int);
    void setGarage(bool);
    void setJardin(bool);
    void setPiscine(bool);

void virtual save(std::ofstream &f);

    int getNbPieces() const;
    bool getGarage() const;
    bool getJardin() const;
    bool getPiscine() const;

};

#endif
