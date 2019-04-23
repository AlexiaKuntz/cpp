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
    Appartement(const Appartement&);
    // Appartement(const Biens &source);

    void virtual save(std::ofstream &f);

    void setNbPieces(int);
    void setEtage(int);
    void setGarage(bool);
    void setCave(bool);
    void setBalcon(bool);

    void affiche();

    int getNbPieces() const;
    bool getGarage() const;
    bool getCave() const;
    bool getBalcon() const;
    int getEtage() const;
};



#endif
