#ifndef ECRAN_H
#define ECRAN_H

#include <SFML/Graphics.hpp>

class ecran {
public:
    // caracteristiques
    int positionX;
    int positionY;

    // constructeur
    ecran();

    // methodes
    void deplacement (int dX, int dY);

};

#endif