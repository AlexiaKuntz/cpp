#ifndef CLIENT_HPP
#define  CLIENT_HPP

#include <iostream>


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
    void virtual add_biens();
    void virtual delete_biens();

    void setNom(std::string);
    void setAdresse(std::string);
};


#endif
