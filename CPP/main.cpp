#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"
#include "Biens.hpp"
#include "Agence.hpp"

int main() {

    Client_acheteur *c= new Client_acheteur();
    Agence test;
    // test.addBuyers();
    test.idClients(c);
    c->affiche();
    // Agence test;
    // test.save_client();
    // test.save_client();
    // test.proposition_achat();
    // test.affiche();

    return 0;
}
