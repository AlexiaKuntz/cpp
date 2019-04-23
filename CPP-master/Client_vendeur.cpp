#include <iostream>
using namespace std;
#include "Client_vendeur.hpp"


// CONSTRUCTEURS //

Client_vendeur::Client_vendeur() : Client() {
}

Client_vendeur::Client_vendeur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {

}

// DESTRUCTEUR //

Client_vendeur::~Client_vendeur() {
  liste_biens.clear();
}

// MODIFICATION DES ATTRIBUTS (vector) //


void Client_vendeur::add_biens(Biens *b){
  liste_biens.push_back(b);
}

void Client_vendeur::delete_biens(Biens *b) {
  liste_biens.erase(std::remove(liste_biens.begin(), liste_biens.end(), b), liste_biens.end());
}

// GETTERS ET SETTER //

std::vector<Biens*> Client_vendeur::getListGoods(){
  return liste_biens;
}

void Client_vendeur::setRef(int _ref) {
  ref=_ref;
}

int Client_vendeur::getRef() {
  return ref;
}

// AFFICHAGE //

void Client_vendeur::affiche(){
  Client::affiche();
  Biens *courant;
  cout << "Liste des biens :\n" << endl;
  for(int i=0;i<liste_biens.size();i++){
    courant=liste_biens[i];
    courant->affiche();
  }
}

// SAUVEGARDE //

void Client_vendeur::save(std::ofstream &f) {
    Client::save(f);
}
