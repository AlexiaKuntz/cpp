#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"


// CONSTRUCTEURS //

Client_acheteur::Client_acheteur() : Client() {

}


Client_acheteur::Client_acheteur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {
}



// MODIFICATION DES ATTRIBUTS (maps)

void Client_acheteur::addProposal(Biens *b) {
  int prop;
  std::cout << "Quelle est sa proposition d'achat ?" << '\n';
  cin >> prop;
  map_proposal[b]=prop;
}


void Client_acheteur::addVisite(Biens *b) {
    map_visites[b]=map_visites[b]+1;
}

void Client_acheteur::add_biens(Biens *b){
  map_visites[b]=0;
  map_proposal[b]=0;
}

void Client_acheteur::delete_biens(Biens *b) {
  map_proposal.erase(b);
  map_visites.erase(b);
}

// GETTER //

std::map<Biens*,int> Client_acheteur::getMapProposal(){
  return map_proposal;
}

// AFFICHAGE //

void Client_acheteur::affiche(){
  Client::affiche();
  cout << "Liste des biens, de leurs visites et leurs propositions d'achat:\n" << endl;
  std::map<Biens*,int>::iterator iter;
  for (iter = map_proposal.begin(); iter != map_proposal.end(); iter++) {
    auto courant=iter->first;
    if(iter->second!=0){
      courant->affiche();
      cout << "Proposition d'achat : " << iter->second << endl;
    }
  }
}


// SAUVEGARDE //

void Client_acheteur::save_acheteurs() {
  std::ofstream ofs ("acheteurs.txt", std::ofstream::out | std::ofstream::app);
  ofs << "Nom du client "<< nom_client << endl;
  ofs << "bien acheté " << endl;
}
