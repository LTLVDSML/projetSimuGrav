#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "corps.h"

using namespace std;

// Commande pour generer executable (depuis le fichier racine du code) :
//   g++ main.cpp corps.cpp -o gravite -lsfml-graphics -lsfml-window -lsfml-system
// Commande pour lancer l'executable (depuis le fichier racine de l'executable) :
//   ./gravite


int main() {
    corps terre;
    terre.nom          = "terre";
    terre.fixe         = false;
    terre.nonInfluence = false;
    terre.masse        = 1000000;
    terre.positionX    = 100;
    terre.positionY    = 100;
    terre.vitesseX     = 0;
    terre.vitesseY     = 0;
    terre.vitesseY     = 0;
    terre.rayon        = 20;
    terre.couleur      = "bleu";

    corps lune;
    lune.nom          = "lune";
    lune.fixe         = false;
    lune.nonInfluence = false;
    lune.masse        = 100000;
    lune.positionX    = 600;
    lune.positionY    = 550;
    lune.vitesseX     = 0;
    lune.vitesseY     = 0;
    lune.rayon        = 10;
    lune.couleur      = "blanc";

    corps mars;
    mars.nom          = "mars";
    mars.fixe         = false;
    mars.nonInfluence = false;
    mars.masse        = 500000;
    mars.positionX    = 100;
    mars.positionY    = 550;
    mars.vitesseX     = 0;
    mars.vitesseY     = 0;
    mars.rayon        = 15;
    mars.couleur      = "rouge";

    // Liste corps
    list<corps> listCorps;
    listCorps.push_back(lune);
    listCorps.push_back(terre);
    listCorps.push_back(mars);

    // Crée une fenêtre 
    sf::RenderWindow window(sf::VideoMode(1100, 600), "gravite");

    // generation des caracteristiques des corps
    for (auto& it : listCorps) {
        it.figure.setRadius(it.rayon);
        // Couleur
        if (it.couleur == "blanc") {
            it.figure.setFillColor(sf::Color::White);
        }
        if (it.couleur == "bleu") {
            it.figure.setFillColor(sf::Color::Blue);
        }
        if (it.couleur == "rouge") {
            it.figure.setFillColor(sf::Color::Red);
        }
    }    

    // Boucle de calcul ////////////////////////////////////////////
    while (window.isOpen())
    {
        // Gestion fermeture
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Fermer la fenêtre si on clique sur la croix
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // efface la fenêtre (fond noir)
        window.clear();  

        // Deplacement et dessin des corps
        for (auto& it : listCorps) {
            it.acceleration(it, listCorps);
            it.mouvement(it);

            it.figure.setPosition(it.positionX, it.positionY);
            window.draw(it.figure);
        }

    window.display();  // affiche tout
    sleep(0.001);

    }
    return 0;

}

