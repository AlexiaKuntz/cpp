#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"
#include "Biens.hpp"
#include "Agence.hpp"



 void menu() {
  std::cout << "##### MENU #####" << '\n';
  std::cout << "-----------------" << '\n';
  std::cout << "1. Ajouter un client (acheteur ou vendeur) " << '\n';
  std::cout << "2. Ajouter un bien à vendre" << '\n';
  std::cout << "3. Ajouter une visite." << '\n';
  std::cout << "4. Ajouter une proposition d'achat" << '\n';
  std::cout << "5. Vente d'un bien." << '\n';
  std::cout << "6. Rechercher un bien" << '\n';
  std::cout << "7. Enregistrer les données dans des fichiers" << '\n';
  std::cout << "8. lire les donnees dans un fichier " << '\n';
  std::cout << "9. Quitter le programme." << '\n';
  }

int main() {

    Agence *a = new Agence();
    bool loop = true;
    while(loop){

        menu();

        int choix=getInt();
        switch(choix){
          case 1: a->addClients();break;
          case 2: a->addGoods();break;
          case 3: a->visite();break;
          case 4: a->proposal();break;
          case 5: a->sellGoods();break;
          case 6: a->recherche();break;
          case 7: a->save();break;// save_clients ou pas le bon fichier?;break;
          case 8: a->load_fichier();break;
          case 9: loop=false;break;

          return 0;
          default: std::cout << "Ce menu n'existe pas, essayez de nouveau svp." << '\n';break;
        }
        a->afficheGoods();
        a->afficheClients();
    }

    delete a;

    return 0;
}
