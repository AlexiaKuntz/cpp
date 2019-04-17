#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"

Client_acheteur::Client_acheteur() : Client() {

}


Client_acheteur::Client_acheteur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {

}


// void Client_acheteur::create_client(){
//     Client::create_client();
// }


// void Client_acheteur::add_biens(){
//       int nb;
//       int prix;
//       cout << "Combien de biens l'intéresse ?" << endl;
//       cin >> nb;
//       for(int i=0;i<nb;i++){
//         Biens good;
//         cout << "\n\nCréation du bien numéro " << i << endl;
//         good.create_biens();
//         cout << "Une proposition d'achat a-t-elle été faite ? Si oui, rentrez le prix. Sinon, rentrez 0." << endl;
//         cin >> prix;
//         map_visites[good]=prix;
//       }
//
// }


std::map<Biens,int> Client_acheteur::getMapVisites(){
  return map_visites;
}

// void Client_acheteur::afficher() {
//     for(std::map<std::string,int>::iterator it=liste_visite.begin();it!=liste_visite.end();it++){
//         std::cout << it->first <<endl;
//     }
// }

void Client_acheteur::affiche(){
  Client::affiche();
  Biens courant;
  cout << "Liste des biens et leurs propositions d'achat:\n" << endl;
  std::map<Biens,int>::iterator iter;
  for (iter = map_visites.begin(); iter != map_visites.end(); iter++) {
    courant=iter->first;
    courant.affiche();
    cout << "Proposition d'achat : " << iter->second << endl;
  }
}
