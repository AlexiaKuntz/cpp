#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include "Biens.hpp"
using namespace std;

class Terrain : public Biens {
private:
    bool constructible;

public:
    Terrain();
    Terrain(int prixx, std::string adress, int ref, int numm);
    Terrain(bool constructible);

    void save_terrain();
void virtual save(std::ofstream &f) ;
    void setConstructible(bool);

    bool getConstructible();

};

#endif
