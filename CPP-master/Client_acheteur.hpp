#ifndef Client_acheteur_HPP
#define Client_acheteur_HPP

#include "Client.hpp"
#include "Biens.hpp"
#include <map>
#include <vector>

class Client_acheteur : public Client {
private:

    map<Biens*,int> map_proposal;
    map<Biens*,int> map_visites;


public:
    Client_acheteur();
    Client_acheteur(std::string,std::string);
    ~Client_acheteur();

    void save_acheteurs();


    void addProposal(Biens*);
    void addVisite(Biens*);

    void virtual affiche();
    void virtual save(std::ofstream &f);
    std::map<Biens*,int> getMapProposal();




    void add_biens(Biens *b);
    void delete_biens(Biens *b);
};

#endif
