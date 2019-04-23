#include <iostream>
using namespace std;
#include "Client.hpp"
#include <fstream>

Client::Client() {
    nom_client="Unknown";
    adresse_client="Unknown";
}

Client::Client(std::string _nom_client, std::string _adresse_client) {
  nom_client=_nom_client;
  adresse_client=_adresse_client;
}

bool Client::operator ==(const Client& x) const{
  return nom_client==x.nom_client;
}

std::string Client::get_nom_client() {
    return nom_client;
}

std::string Client::get_adresse_client() {
    return adresse_client;
}

void Client::affiche() {
    cout << "Nom : " << nom_client << ", adresse : " << adresse_client << endl;
}

void Client::setNom(std::string _nom) {
  nom_client=_nom;
}

void Client::setAdresse(std::string _adresse) {
  adresse_client=_adresse;
}

void Client::save(std::ofstream &f) {
    f << "Le nom du client est :" << get_nom_client() << endl;
    f <<"L'adresse du client est :"<< get_adresse_client() << endl;
}
