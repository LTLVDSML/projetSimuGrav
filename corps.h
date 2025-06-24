#ifndef CORPS_H
#define CORPS_H

#include <SFML/Graphics.hpp>

class corps {
public:
    // attributs
    std::string nom;
    std::string couleur;
    bool fixe;
    bool nonInfluence;
    float masse = 1000;
    float accelerationX = 0;
    float accelerationY = 0;
    float positionX = 0;
    float positionY = 0;
    float vitesseX = 0;
    float vitesseY = 0;
    int rayon = 10;

    sf::CircleShape figure;

    // constructeur
    corps();

    // methodes
    void acceleration(corps, std::list<corps>&listeCibles);
    void mouvement(corps);
};

#endif