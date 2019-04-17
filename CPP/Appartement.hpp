#ifndef APPARTEMENT_HPP
#define APPARTEMENT_HPP

#include <iostream>
#include "Biens.hpp"
using namespace std;

class Appartement : public Biens {
private:
    int nb_pieces;
    int etage;
    bool garage;
    bool cave;
    bool balcon;

public:
    Appartement();
    Appartement(int prixx, std::string adress, int ref, int numm);
    Appartement(int prix, std::string adresse_biens, int num, int ref_client,int nb_pieces,int etage,bool garage,bool cave,bool balcon);
    // void create_appartement();

    void setNbPieces(int);
    void setEtage(int);
    void setGarage(bool);
    void setCave(bool);
    void setBalcon(bool);
};



#endif
