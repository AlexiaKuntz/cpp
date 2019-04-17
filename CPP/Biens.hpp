#ifndef  BIENS_HPP
#define BIENS_HPP

#include <iostream>
using namespace std;

class Biens {
protected:
    int prix;
    std::string adresse_biens;
    int ref_client;
    int num;

public:
    Biens();
    Biens(int prix, std::string adresse_biens,int ref_client,int num);
    // Biens virtual create_biens();
    // void vendre_biens();
    bool operator <(const Biens& x) const;
    void virtual affiche();

    void setPrice(int);
    void setAdress(std::string);
    void setRef(int);
    void setNum(int);

    int getPrice();
    std::string getAdress();
    int getRef();
    int getNum();



};

#endif
