#ifndef CLIENT_HPP
#define  CLIENT_HPP

#include <iostream>
#include "Biens.hpp"

class Client {
protected:
    std::string nom_client;
    std::string adresse_client;

public:
    Client();
    Client(std::string,std::string);

    bool virtual operator ==(const Client&) const;


    std::string get_nom_client();
    std::string get_adresse_client();

    void virtual affiche();
    void virtual add_biens(Biens*)=0;
    void virtual delete_biens(Biens*)=0;
    void virtual save(std::ofstream &f);

    void setNom(std::string);
    void setAdresse(std::string);
};


#endif
