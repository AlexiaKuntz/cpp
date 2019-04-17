#include <iostream>
using namespace std;
#include "Client_vendeur.hpp"

Client_vendeur::Client_vendeur() : Client() {
}

Client_vendeur::Client_vendeur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {

}


// void Client_vendeur::create_client(){
//     Client::create_client();
//   }

// void Client_vendeur::add_biens(){
//   int nb;
//   cout << "Combien de biens vend-il ?" << endl;
//   cin >> nb;
//   for(int i=0;i<nb;i++){
//     Biens good;
//     cout << "Création du bien numéro " << i << endl;
//     good.create_biens();
//     liste_biens.push_back(good);
//   }
// }


std::vector<Biens> Client_vendeur::getListGoods(){
  return liste_biens;
}


void Client_vendeur::affiche(){
  Client::affiche();
  Biens courant;
  cout << "Liste des biens :\n" << endl;
  for(int i=0;i<liste_biens.size();i++){
    courant=liste_biens[i];
    courant.affiche();
  }
}


// void Client_vendeur::add_biens(Biens b){
//   liste_biens.emplace_back(b);
// }
