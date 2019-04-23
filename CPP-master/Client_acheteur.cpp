#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"
#include "Biens.hpp"


// CONSTRUCTEURS //

Client_acheteur::Client_acheteur() : Client() {

}


Client_acheteur::Client_acheteur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {
}

// DESTRUCTEUR //

Client_acheteur::~Client_acheteur() {
  map_proposal.clear();
  map_visites.clear();
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
  std::map<Biens*,int>::iterator iter2;
  for (iter = map_visites.begin(); iter != map_visites.end(); iter++) {
    auto courant=iter->first;
    if(iter->second!=0){
      courant->affiche();
      cout << "Nombre de visites : " << iter->second << endl;
      for(iter2=map_proposal.begin();iter2!=map_proposal.end();iter2++){
        auto courant2=iter2->first;
        if(iter2->second!=0 && courant==courant2){
          cout << "Proposition d'achat : " << iter2->second << endl;
          break;
        }
      }
    }
  }
}


// SAUVEGARDE //

void Client_acheteur::save(std::ofstream &f) {
    Client::save(f);
    f<<"acheteurs\n"<<endl;
    for (auto& [first,second] : map_visites) {
        first->saveForAcheteurs(f);
        f << endl;
   }
}
