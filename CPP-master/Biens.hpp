#ifndef  BIENS_HPP
#define BIENS_HPP

#include "Utils.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <map>
#include <vector>
using namespace std;

class Biens {
public:
    int prix;
    std::string adresse;
    int ref;
    int num;

public:
    Biens();
    Biens(int, std::string, int, int);

    bool operator <(const Biens&) const;
    bool operator ==(const Biens&) const;
    // int virtual save();
    void virtual save(std::ofstream &f);
    // void virtual save();

    void saveForAcheteurs(std::ofstream &f);

    int getVendeurRef();

    void setPrice(int);
    void setAdress(std::string);
    void setRef(int);
    void setNum(int);

    int getPrice() const;
    std::string getAdress() const;
    int getRef() const;
    int getNum() const;

    void virtual affiche();



};

#endif
