#ifndef AGENCE_HPP
#define AGENCE_HPP

#include <iostream>
#include "Client_acheteur.hpp"
#include "Client_vendeur.hpp"
#include "Biens.hpp"
#include "Appartement.hpp"
#include "Terrain.hpp"
#include "Maison.hpp"
#include "Locaux.hpp"
using namespace std;
#include <map>
#include <vector>
#include <string>

class Client;

class Agence {


protected:
    std::map<Biens*,std::vector<Client_acheteur> >goods_map;
    std::vector<Client_vendeur*>sellers;
    std::vector<Client_acheteur*>buyers;

public:
    Agence();
    ~Agence();

    Biens* idGood();
    Terrain* idTerrain(Biens*);
    Maison* idMaison(Biens*);
    Appartement* idFlat(Biens*);
    Locaux* idLocaux(Biens*);
    void addOneGood();
    void addGoods();

    void idClients(Client*);
    void addClients();
    void addBuyers();
    void proposal();
    void visite();
    void addSellers();

    void sellGoods();

    Biens* searchGood();

    void virtual afficheClients();
    void afficheGoods();
    void recherche();
    void save();


    void load_fichier();
    void load_biens();
    void load_acheteurs();
    void load_vendeurs();

};
#endif
