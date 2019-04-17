#include <iostream>
using namespace std;
#include "Client.hpp"

Client::Client() {
    nom_client="Unknown";
    adresse_client="Unknown";
}

Client::Client(std::string _nom_client, std::string _adresse_client) {
  nom_client=_nom_client;
  adresse_client=_adresse_client;
}

void Client::create_client() {
    std::cout << "Le nom du client ?" << '\n';
    std::cin >> nom_client;
    std::cout << "adresse du client ?" << '\n';
    std::cin >> adresse_client;
}

std::string Client::get_nom_client() {
    std::cout << nom_client << '\n';
    return nom_client;
}

std::string Client::get_adresse_client() {
    std::cout << adresse_client <<'\n';
    return adresse_client;
}

void Client::save_client() {
    get_nom_client();
    get_adresse_client();
}

void Client::affiche() {
    cout << "Nom : " << nom_client << ", adresse : " << adresse_client << endl;
}

void Client::add_biens(){

}

void Client::setNom(std::string _nom) {
  nom_client=_nom;
}

void Client::setAdresse(std::string _adresse) {
  adresse_client=_adresse;
}
