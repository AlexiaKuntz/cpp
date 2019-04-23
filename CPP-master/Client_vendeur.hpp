#ifndef CLIENT_VENDEUR_HPP
#define CLIENT_VENDEUR_HPP

#include <iostream>
#include "Client.hpp"
#include "Biens.hpp"
#include <vector>

class Client_vendeur : public Client {
private:
  int ref;
  std::vector<Biens*> liste_biens;

public:
    Client_vendeur();
    Client_vendeur(std::string,std::string);
    ~Client_vendeur();

    void add_biens(Biens *b);
    void delete_biens(Biens *b);

    void save_vendeurs();

    void virtual affiche();
    void virtual save(std::ofstream &f);


    std::vector<Biens*> getListGoods();
    void setRef(int);
    int getRef();

};


#endif
