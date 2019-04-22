#include <iostream>
using namespace std;
#include "Agence.hpp"
#include <iterator>
#include <fstream>

static int numm=0;

// CONSTRUCTEUR //

Agence::Agence(){

}

// CREATION DES DIFFERENTS BIENS //

Biens* Agence::idGood() {
  std::string adress;
  int ref;
  int prixx;

  std::cout << "Quelle est l'adresse ?" << '\n';
  std::cin >> adress;
  std::cout << "Quelle est la référence ?" << '\n';
  std::cin >> ref;
  std::cout << "Quel est le prix ?" << '\n';
  std::cin >> prixx;
  numm++;
  Biens *good = new Biens(prixx,adress,ref,numm);
  return good;
}

Terrain* Agence::idTerrain(Biens *b) {
  bool constructible;

  Terrain *good = new Terrain(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "Le terrain est-il constructible ? false/true" << '\n';
  std::cin >> constructible;
  good->setConstructible(constructible);

  return good;
}

Maison* Agence::idMaison(Biens *b) {
  int nb_pieces;
  bool garage, jardin, piscine;

  Maison *good = new Maison(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "combien de pièces ?" << '\n';
  std::cin >> nb_pieces;
  good->setNbPieces(nb_pieces);
  std::cout << "voulez-vous un garage ? false/true" << '\n';
  std::cin >> garage;
  good->setGarage(nb_pieces);
  std::cout << "voulez-vous un jardin ? false/true" << '\n';
  std::cin >> jardin;
  good->setJardin(jardin);
  std::cout << "voulez-vous une piscine ? false/true" << '\n';
  std::cin >> piscine;
  good->setPiscine(piscine);

  return good;
}

Locaux* Agence::idLocaux(Biens *b) {
  int taille_vitrine;
  bool stocker;

  Locaux *good = new Locaux(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "quelle taille vitrine ?" << '\n';
  std::cin >> taille_vitrine;
  good->setTailleVitrine(taille_vitrine);
  std::cout << "voulez-vous une piece pour stocker ? false/true" << '\n';
  std::cin >> stocker;
  good->setStocker(stocker);

  return good;
}

Appartement* Agence::idFlat(Biens *b) {
  int nb_pieces;
  int etage;
  bool garage, cave, balcon;

  Appartement *good = new Appartement(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "combien de pièces ?" << '\n';
  std::cin >> nb_pieces;
  good->setNbPieces(nb_pieces);
  std::cout << "A quel étage ?" << '\n';
  std::cin >> etage;
  good->setEtage(etage);
  std::cout << "voulez-vous un garage ? false/true" << '\n';
  std::cin >> garage;
  good->setGarage(garage);
  std::cout << "voulez-vous une cave ? false/true" << '\n';
  std::cin >> cave;
  good->setCave(cave);
  std::cout << "voulez-vous un balcon ? false/true" << '\n';
  std::cin >> balcon;
  good->setBalcon(balcon);

  return good;

}

// AJOUTS DES BIENS DANS LES ATTRIBUTS DE L'AGENCE //

void Agence::addOneGood(){
  int type;
  std::string nom;

      std::cout << "Quel type de biens ?" << '\n';
      std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
  std::cin >> type;

  Biens *good = idGood();
  Maison *goodMaison;
  Terrain *goodTerrain;
  Locaux *goodLocaux;
  Appartement *goodFlat;

  switch (type) {
      case 1:
        goodLocaux = idLocaux(good);
        goods_map[goodLocaux];
        for(int i = 0; i < sellers.size(); i++) {
          if(sellers[i]->getRef()==goodLocaux->getRef()) {
            sellers[i]->add_biens(goodLocaux);
          }
        }
        break;
      case 2:
        goodMaison = idMaison(good);
        goods_map[goodMaison];
        for(int i = 0; i < sellers.size(); i++) {
          if(sellers[i]->getRef()==goodMaison->getRef()) {
            sellers[i]->add_biens(goodMaison);
          }
        }
        break;
      case 3:
        goodTerrain = idTerrain(good);
        goods_map[goodTerrain];
        for(int i = 0; i < sellers.size(); i++) {
          if(sellers[i]->getRef()==goodTerrain->getRef()) {
            sellers[i]->add_biens(goodTerrain);
          }
        }
        break;
      case 4:
        goodFlat = idFlat(good);
        goods_map[goodFlat];
        for(int i = 0; i < sellers.size(); i++) {
          if(sellers[i]->getRef()==goodFlat->getRef()) {
            sellers[i]->add_biens(goodFlat);
          }
        }
        break;
      default: std::cout << "vous vous etes trompés. Recommencez." <<'\n';
  }



  for(int i = 0; i < buyers.size(); i++) {
      buyers[i]->add_biens(good);
  }

}

void Agence::addGoods() {
  int nb;

  std::cout << "Combien voulez-vous ajouter de biens ?" << '\n';
  std::cin >> nb;

  for(int i = 0; i < nb; i++) {
    addOneGood();
  }
  afficheGoods();
}

// CREATION DES CLIENTS ET AJOUTS DES CLIENTS DANS LES ATTRIBUTS DE L'AGENCE //

void Agence::idClients(Client *c) {
  std::string nom;
  std::string adresse;
  std::cout << "Quel est le nom du client ?" << '\n';
  std::cin >> nom;
  c->setNom(nom);
  std::cout << "Quelle est son adresse ?" << '\n';
  std::cin >> adresse;
  c->setAdresse(adresse);

}

void Agence::addClients(){
  std::string choix;
  int nb;

  std::cout << "Voulez-vous ajouter des acheteurs ou des vendeurs ? a/v" << '\n';
  std::cin >> choix;
  std::cout << "Combien voulez-vous en ajouter ?" << '\n';
  std::cin >> nb;
  if(choix=="a") {
    for(int i = 0; i<nb; i++){
      addBuyers();
    }
  }
  else if(choix=="v") {
    for(int i = 0; i<nb; i++) {
      addSellers();
    }
  }
}

void Agence::addBuyers() {
  Client_acheteur *idv = new Client_acheteur();
  idClients(idv);
  buyers.emplace_back(idv);

}

void Agence::proposal(){
    std::string nom;
    std::cout << "Quel est le nom de l'acheteur ?" << '\n';
    std::cin >> nom;
    Biens *courant=searchGood();

    for(int i = 0;i<buyers.size();i++){
      if(buyers[i]->get_nom_client()==nom){
        buyers[i]->addProposal(courant);
        goods_map[courant].emplace_back(*buyers[i]);
      }
    }
}

void Agence::visite(){
  std::string nom;
  std::cout << "Quel est le nom de l'acheteur ?" << '\n';
  std::cin >> nom;
  Biens *good = searchGood();
  for(int i = 0;i<buyers.size();i++){
    if(buyers[i]->get_nom_client()==nom){
      buyers[i]->addVisite(good);
}
}
}

void Agence::addSellers() {
  int ref;
  Client_vendeur *idv = new Client_vendeur();
  idClients(idv);
  cout << "Quel est son numéro référence ?" << endl;
  cin >> ref;
  idv->setRef(ref);
  sellers.emplace_back(idv);
}

// VENTE DE BIENS //


void Agence::sellGoods() {
  bool loop=true;
  int id;
  afficheGoods();
  while(loop!=false){
    std::string nom;
    cout << "Quel est le nom de l'acheteur ?" << endl;
    std::cin >> nom;

    // recherche du bien d'intérêt //
    Biens *courant = searchGood();

    // suppression du bien de la liste des biens du vendeur //
    for(int i = 0; i<sellers.size(); i++) {
      if(sellers[i]->getRef()==courant->getRef()) {
        sellers[i]->delete_biens(courant);
        break;
      }
    }

    // suppression du bien dans la liste des biens des acheteurs intéressés //
    for(int i = 0;i<buyers.size();i++){
      if(std::find(goods_map[courant].begin(),goods_map[courant].end(),*buyers[i])!=goods_map[courant].end()){
        buyers[i]->delete_biens(courant);
      }
    }

    // suppression de l'acheteur qui a acheté le bien //
    for(int i = 0;i<buyers.size();i++){
      if(buyers[i]->get_nom_client()==nom){
        buyers.erase(std::remove(buyers.begin(), buyers.end(),buyers[i]),buyers.end());
      }
    }

    // suppression du bien de la liste des biens de l'agence //
    goods_map.erase(courant);

    std::cout << "D'autres biens ont-ils été vendus ? 0 --> non, 1 --> oui" << '\n';
    std::cin >> loop;
  }
}

// AFFICHAGE //

void Agence::afficheGoods() {
  std::map<Biens*,std::vector<Client_acheteur>>::iterator iter;
  for (iter = goods_map.begin(); iter != goods_map.end(); iter++) {
    auto courant = iter->first;
    courant->affiche();
    cout << "Intéressés : " << "\t";
    for(int i = 0; i<goods_map[courant].size(); i++) {
      cout << goods_map[courant][i].get_nom_client() << "\t";
    }
    cout << "\n" << endl;
  }
}


void Agence::afficheClients(){
  cout << "Vendeurs :\n" << endl;
    for(int i=0;i<sellers.size();i++) {
      sellers[i]->affiche();
    }
  cout << "\nAcheteurs :\n" << endl;
    for(int i=0;i<buyers.size();i++) {
      buyers[i]->affiche();
    }
}


// RECUPERATION D'UN BIEN PARTICULIER //

Biens* Agence::searchGood() {
  int id;

  std::cout << "Quel est l'identifiant du bien ?" << '\n';
  std::cin >> id;

  std::map<Biens*,std::vector<Client_acheteur>>::iterator iter;
  for (iter = goods_map.begin(); iter != goods_map.end(); iter++) {
    auto courant=iter->first;
    if(courant->getNum()==id) {
      return courant;
    }

}
}

void Agence::recherche() {
    std::vector<Biens> v;
    int type;
    int prix;
    // std::string adresse;
    // int ref;
    std::string answer;
    int taille;
    int etage;
    int nb_pieces;
    bool piscine;
    bool stock;
    bool garage;
    bool cave;
    bool balcon;
    bool jardin;
    bool constructible;

    std::cout << "Quel prix maximum ? ?" << '\n';
    std::cin >> prix;
    // std::cout << "Quelle adresse ?" << '\n';
    // std::cin >> adresse;
    // std::cout << "Quelle ref du client ?" << '\n';
    // std::cin >> ref;
    for(std::map<Biens*,std::vector<Client_acheteur> >::iterator it=goods_map.begin();it!=goods_map.end();it++) {
        Biens* test = it->first;
        std::cout << typeid(*test).name() << '\n';
        // && test->getAdress() == adresse && test->getRef() == ref
        if(test->getPrice() < prix) {
          test->affiche();
            // v.push_back(test);
            std::cout << "quel type de biens ? " << '\n';
            std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
            std::cin >> type;
            switch (type) {
                // case 1: {
                // // Locaux *test = new Locaux(prix,adresse,ref,1);
                //         // std::cout << "Quelle taille de vitrine ?" << '\n';
                //         // std::cin >> taille;
                //         std::cout << "Une piece pour stocker ? 0 --> non 1 --> oui " << '\n';
                //         std::cin >> stock;
                //         // test->getTaille()==taille &&
                //         if(test->getStock()==stock) {
                //             v.push_back(test);
                //         }
                //       } break;
                //
                // case 2:{
                // // Maison *test = new Maison(prix,adresse,ref,1);
                //         // std::cout << "combien de piece ?" << '\n';
                //         // std::cin >> nb_pieces;
                //         std::cout << "voulez-vous un garage ? 0 --> non 1--> oui" << '\n';
                //         std::cin >> garage;
                //         std::cout << "voulez-vous un jardin ? 0 --> non 1--> oui" << '\n';
                //         std::cin >> jardin;
                //         std::cout << "voulez-vous une piscine ? 0 --> non 1--> oui" << '\n';
                //         std::cin >> piscine;
                //         // test->getNbPieces()==nb_pieces &&
                //         if(test->getGarage()==garage && test->getJardin()==jardin && test->getPiscine()==piscine) {
                //             v.push_back(test);
                //         }}break;
                //
                // case 3:{
                // // Terrain *test = new Terrain(prix,adresse,ref,1);
                //         std::cout << "constructible 0 --> non 1--> oui?" << '\n';
                //         std::cin >> constructible;
                //         if(test->getConstructible()==constructible) {
                //             v.push_back(test);
                //         }
                //       } break;
// new Appartement(test->getPrice(),test->getAdress(),test->getRef(),test->getNum(),test->getNbPieces(),test->getEtage(),test->getGarage(),test->getCave(),test->getBalcon());
                case 4:{ Appartement *test;
                    test->affiche();
                        std::cout << "combien de piece ?" << '\n';
                        std::cin >> nb_pieces;
                        std::cout << "A quel etage ?" << '\n';
                        std::cin >> etage;
                        std::cout << "voulez-vous un garage ? 0 --> non 1--> oui" << '\n';
                        std::cin >> garage;
                        std::cout << "voulez-vous une cave ? 0 --> non 1--> oui" << '\n';
                        std::cin >> cave;
                        std::cout << "voulez-vous un balcon ? 0 --> non 1--> oui" << '\n';
                        std::cin >> balcon;
                        if(test->getNbPieces()==nb_pieces && test->getEtage()==etage && test->getGarage()==garage && test->getBalcon()==balcon && test->getCave()==cave) {

                            v.push_back(*test);
                        }}break;
              }
          }
      }
      for(int i=0;i<v.size();i++){
        auto courant = v[i];
        std::cout << "recherche:" << '\n';
        courant.affiche();
      }
}


void Agence::load_fichier() {
    int nom_fichier;
    std::cout << "quel fichier voulez vous ? 1: biens.txt / 2 : acheteurs.txt / 3: vendeurs.txt" << '\n';
    std::cin >> nom_fichier;
    switch(nom_fichier) {
        case 1 : load_biens();break;
        case 2 : load_acheteurs();break;
        case 3 : load_vendeurs();break;
    }
}


void Agence::load_biens() {
  vector<std::string> vecString;
    ifstream fInFile("biens.txt");
    copy(istream_iterator<std::string>(fInFile), istream_iterator<std::string>(), back_inserter(vecString));
    for(int i=0; i<=vecString.size();i++ ) {
      std::cout << vecString[i] << '\t';
    }
}

void Agence::load_acheteurs() {
  vector<std::string> vecacheteurs;
    ifstream fichier("acheteurs.txt");
    copy(istream_iterator<std::string>(fichier), istream_iterator<std::string>(), back_inserter(vecacheteurs));
    for(int i=0; i<=vecacheteurs.size();i++ ) {
        std::cout << vecacheteurs[i] << '\t';}
}

void Agence::load_vendeurs() {
  vector<std::string> vecvendeurs;
    ifstream fichier2("vendeurs.txt");
    copy(istream_iterator<std::string>(fichier2), istream_iterator<std::string>(), back_inserter(vecvendeurs));
    for(int i=3; i<=vecvendeurs.size();i++ ) {
        std::cout << "vendeurs : " << vecvendeurs[i] << '\t';
    }
}
