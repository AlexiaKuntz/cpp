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
    // void create_terrain();

    void setConstructible(bool);
};

#endif
