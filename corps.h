#ifndef CORPS_H
#define CORPS_H

class corps {
public:
    // attributs
    std::string nom;
    bool fixe;
    bool nonInfluence;
    float masse;
    float positionX;
    float positionY;
    float vitesseX;
    float vitesseY;

    float sommeVitesseX;

    // constructeur
    corps();

    // methodes
    void mouvement(corps &cible);
};

#endif