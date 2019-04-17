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
    std::map<Biens,std::vector<Client_acheteur> >goods_map;
    std::vector<Client_vendeur>sellers;
    std::vector<Client_acheteur>buyers;

public:
    Agence();

    Biens idGood();
    void idTerrain(Biens);
    void idMaison(Biens);
    void idFlat(Biens);
    void idLocaux(Biens);
    void addOneGood();

    void idClients(Client*);
    void addClients();
    void addBuyers();
    void addSellers();



    // void save_client();
    void ajouter_biens();
    // void proposition_achat();
    void virtual affiche();
    // void virtual create_biens();
};
#endif
