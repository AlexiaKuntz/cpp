#include <iostream>
using namespace std;
#include "Agence.hpp"
#include "Biens.hpp"
#include "Appartement.hpp"
#include <iterator>
#include <fstream>
#include "Utils.h"
static int numm=0;

// CONSTRUCTEUR //

Agence::Agence(){

}


// DESTRUCTEUR //

Agence::~Agence() {
    goods_map.clear();
    buyers.clear();
    sellers.clear();
}

// CREATION DES DIFFERENTS BIENS //

Biens* Agence::idGood() {
  std::string adress;
  int ref;
  int prixx;
  int ok = 0;

  std::cout << "Quelle est l'adresse ?" << '\n';
  std::cin >> adress;
  while(ok==0){
    std::cout << "Quelle est la référence ?" << '\n';
    ref=getInt();

    for(int i=0;i<sellers.size();i++){
      if(ref==sellers[i]->getRef()) {
        ok=1;
        break;
      }
    }
    if(ok==0){
      std::cout << "Référence correspondant à aucun vendeur. Réessayez." << '\n';
    }
  }

  std::cout << "Quel est le prix ?" << '\n';
  prixx=getInt();

  numm++;
  Biens *good = new Biens(prixx,adress,ref,numm);
  return good;
}

Terrain* Agence::idTerrain(Biens *b) {
  bool constructible;

  Terrain *good = new Terrain(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "Le terrain est-il constructible ? 0 --> non, 1 --> oui" << '\n';
  constructible=getTrueBool();
  good->setConstructible(constructible);

  return good;
}

Maison* Agence::idMaison(Biens *b) {
  int nb_pieces;
  bool garage, jardin, piscine;

  Maison *good = new Maison(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "combien de pièces ?" << '\n';
  nb_pieces=getInt();
  good->setNbPieces(nb_pieces);
  std::cout << "voulez-vous un garage ? 0 --> non, 1 --> oui" << '\n';
  garage=getTrueBool();
  good->setGarage(nb_pieces);
  std::cout << "voulez-vous un jardin ? 0 --> non, 1 --> oui" << '\n';
  jardin=getTrueBool();
  good->setJardin(jardin);
  std::cout << "voulez-vous une piscine ? 0 --> non, 1 --> oui" << '\n';
  piscine=getTrueBool();
  good->setPiscine(piscine);

  return good;
}

Locaux* Agence::idLocaux(Biens *b) {
  int taille_vitrine;
  bool stocker;

  Locaux *good = new Locaux(b->getPrice(), b->getAdress(), b->getRef(),
  b->getNum());

  std::cout << "quelle taille vitrine ?" << '\n';
  taille_vitrine=getInt();
  good->setTailleVitrine(taille_vitrine);
  std::cout << "voulez-vous une piece pour stocker ? 0 --> non, 1 --> oui" << '\n';
  stocker=getTrueBool();
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
  nb_pieces=getInt();
  good->setNbPieces(nb_pieces);
  std::cout << "A quel étage ?" << '\n';
  etage=getInt();
  good->setEtage(etage);
  std::cout << "voulez-vous un garage ? 0 --> non, 1 --> oui" << '\n';
  garage=getTrueBool();
  good->setGarage(garage);
  std::cout << "voulez-vous une cave ? 0 --> non, 1 --> oui" << '\n';
  cave=getTrueBool();
  good->setCave(cave);
  std::cout << "voulez-vous un balcon ? 0 --> non, 1 --> oui" << '\n';
  balcon=getTrueBool();
  good->setBalcon(balcon);

  return good;

}

// AJOUTS DES BIENS DANS LES ATTRIBUTS DE L'AGENCE //

void Agence::addOneGood(){
  int type;
  std::string nom;
  int ok=0;

  while(ok==0){
      std::cout << "Quel type de biens ?" << '\n';
      std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
      type=getInt();
      if(type>0 && type<5){
        ok=1;
      }
      else{
        std::cout << "Veuillez entrer un chiffre entre 1 et 4." << '\n';
      }
    }


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
  nb=getInt();

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
  int ok=0;

  while(ok==0){
    std::cout << "Voulez-vous ajouter des acheteurs ou des vendeurs ? a/v" << '\n';
    std::cin >> choix;
    if(choix=="a" || choix=="v"){
      ok=1;
    }
    else{
      std::cout << "Veuillez entrer a pour acheteur, et v pour vendeur." << '\n';
    }
  }

  std::cout << "Combien voulez-vous en ajouter ?" << '\n';
  nb=getInt();
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
  bool loop=0;
  while(loop==0){
    std::string nom;
    std::cout << "Quel est le nom de l'acheteur ?" << '\n';
    std::cin >> nom;
    Biens *courant=searchGood();

    for(int i = 0;i<buyers.size();i++){
      if(buyers[i]->get_nom_client()==nom){
        buyers[i]->addProposal(courant);
        goods_map[courant].emplace_back(*buyers[i]);
        loop=1;
      }
      else{
        std::cout << "Acheteur non trouvé. Réessayez" << '\n';
      }
    }
  }
}

void Agence::visite(){
  bool loop=0;
  while(loop==0){
    std::string nom;
    std::cout << "Quel est le nom de l'acheteur ?" << '\n';
    std::cin >> nom;
    Biens *good = searchGood();
    for(int i = 0;i<buyers.size();i++){
      if(buyers[i]->get_nom_client()==nom){
        buyers[i]->addVisite(good);
        loop=1;
      }
      else {
        std::cout << "Acheteur non trouvé. Réessayez" << '\n';
      }
    }
  }
}

void Agence::addSellers() {
  int ref;
  Client_vendeur *idv = new Client_vendeur();
  idClients(idv);
  cout << "Quel est son numéro référence ?" << endl;
  ref=getInt();
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
    loop=getTrueBool();
  }
}

// AFFICHAGE //

void Agence::afficheGoods() {
  std::map<Biens*,std::vector<Client_acheteur> >::iterator iter;
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
  id=getInt();

  std::map<Biens*,std::vector<Client_acheteur> >::iterator iter;
  for (iter = goods_map.begin(); iter != goods_map.end(); iter++) {
    auto courant=iter->first;
    if(courant->getNum()==id) {
      return courant;
    }
  }
  std::cout << "Aucun bien trouvé." << '\n';
}

void Agence::recherche() {
    std::vector<Biens> v;
    int type;
    int prix;
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
    int ok=0;

    std::cout << "Quel prix maximum ? ?" << '\n';
    prix=getInt();
    std::cout << "quel type de biens ? " << '\n';


    while(ok==0){
        std::cout << "Quel type de biens ?" << '\n';
        std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
        type=getInt();
        if(type>=0 && type<=4){
          ok=1;
        }
        else{
          std::cout << "Veuillez entrer un chiffre entre 1 et 4." << '\n';
        }
      }


    switch (type) {
        case 1: {
                std::cout << "Une piece pour stocker ? 0 --> non 1 --> oui " << '\n';
                stock=getTrueBool();
              } break;

        case 2:{
                std::cout << "voulez-vous un garage ? 0 --> non 1--> oui" << '\n';
                garage=getTrueBool();
                std::cout << "voulez-vous un jardin ? 0 --> non 1--> oui" << '\n';
                jardin=getTrueBool();
                std::cout << "voulez-vous une piscine ? 0 --> non 1--> oui" << '\n';
                piscine=getTrueBool();
              } break;

        case 3:{
                std::cout << "constructible 0 --> non 1--> oui?" << '\n';
                constructible=getTrueBool();
              } break;
        case 4:{
                std::cout << "combien de piece ?" << '\n';
                nb_pieces=getInt();
                std::cout << "A quel etage ?" << '\n';
                etage=getInt();
                std::cout << "voulez-vous un garage ? 0 --> non 1--> oui" << '\n';
                garage=getTrueBool();
                std::cout << "voulez-vous une cave ? 0 --> non 1--> oui" << '\n';
                cave=getTrueBool();
                std::cout << "voulez-vous un balcon ? 0 --> non 1--> oui" << '\n';
                balcon=getTrueBool();
              } break;
      }

      for(std::map<Biens*,std::vector<Client_acheteur> >::iterator it=goods_map.begin();it!=goods_map.end();it++) {
          Biens* test = it->first;
          if(test->getPrice() < prix) {
            switch (type) {
                case 1: {
                    Locaux *locaux = (Locaux*) test;
                        if(locaux->getStock()==stock) {
                            v.push_back(*locaux);
                        }
                      } break;

                case 2:{
                    Maison *maison = (Maison*) test;
                        if(maison->getGarage()==garage && maison->getJardin()==jardin && maison->getPiscine()==piscine) {
                            v.push_back(*maison);
                        }
                      } break;

                case 3:{
                    Terrain *terrain =(Terrain*) test;
                        if(terrain->getConstructible()==constructible) {
                            v.push_back(*terrain);
                        }
                      } break;
                case 4:{
                    Appartement *flat=(Appartement*) test;
                        if(flat->getNbPieces()==nb_pieces && flat->getEtage()==etage && flat->getGarage()==garage && flat->getBalcon()==balcon && flat->getCave()==cave) {
                            v.push_back(*flat);
                        }
                      } break;
              }
            }
          }

          std::cout << "Résultats de recherche : " << '\n';
          for(int i=0;i<v.size();i++){
            auto courant = v[i];
            courant.affiche();
          }
}

void Agence::save() {
    ofstream goodsFile;
    goodsFile.open("Biens.txt");
    if (goodsFile.is_open()) {
        for (auto&& [first,second] : goods_map) {
            first->save(goodsFile);
            goodsFile << endl;
        }
        goodsFile.close();
    }


    ofstream sellersFile;
    sellersFile.open("Vendeurs.txt");
    if (sellersFile.is_open()) {
        for (auto& seller : sellers) {
            seller->save(sellersFile);
            sellersFile << endl;
        }
        sellersFile.close();
    }

    ofstream buyersFile;
    buyersFile.open("Acheteurs.txt");
    if (buyersFile.is_open()) {
        for (auto& buyer : buyers){
            buyer->save(buyersFile);
            buyersFile << endl;
        }
        buyersFile.close();
    }
}


void Agence::load_fichier() {
    int nom_fichier;
    int ok=0;

    while(ok==0){
      std::cout << "Quel fichier voulez vous ? 1: biens.txt / 2 : acheteurs.txt / 3: vendeurs.txt" << '\n';
      nom_fichier=getInt();
      if(nom_fichier>0 && nom_fichier<4){
        ok=1;
      }
      else{
        std::cout << "Veuillez entrer un nombre entre 1 et 3." << '\n';
      }
    }

    switch(nom_fichier) {
        case 1 : load_biens();break;
        case 2 : load_acheteurs();break;
        case 3 : load_vendeurs();break;
    }
}


void Agence::load_biens() {
    ifstream fInFile("Biens.txt");
    char c = fInFile.get();
        while (fInFile.good()) {
            std::cout << c;
            c = fInFile.get();
   }
}

void Agence::load_acheteurs() {
    ifstream fInFile("Acheteurs.txt");
    char c = fInFile.get();
        while (fInFile.good()) {
            std::cout << c;
            c = fInFile.get();
   }
}

void Agence::load_vendeurs() {
    ifstream fInFile("Vendeurs.txt");
    char c = fInFile.get();
        while (fInFile.good()) {
            std::cout << c;
            c = fInFile.get();
   }
}
