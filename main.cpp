#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>   // sfml-2.6.2-1
#include <SFML/Window/Keyboard.hpp>
#include "corps.h"
#include "ecran.h"

using namespace std;

// Commande pour generer executable (depuis le fichier racine du code) :
//   g++ main.cpp corps.cpp ecran.cpp -o gravite -lsfml-graphics -lsfml-window -lsfml-system
// Commande pour lancer l'executable (depuis le fichier racine de l'executable) :
//   ./gravite


int main() {
    corps terre;
    terre.nom          = "terre";
    terre.fixe         = false;
    terre.nonInfluence = false;
    terre.masse        = 1000000;
    terre.positionX    = 0;
    terre.positionY    = 0;
    terre.vitesseX     = 0;
    terre.vitesseY     = 0;
    terre.rayon        = 20;
    terre.couleur      = "bleu";

    corps lune;
    lune.nom          = "lune";
    lune.fixe         = false;
    lune.nonInfluence = false;
    lune.masse        = 100000;
    lune.positionX    = -500;
    lune.positionY    = 0;
    lune.vitesseX     = 0;
    lune.vitesseY     = 0.03;
    lune.rayon        = 10;
    lune.couleur      = "blanc";

    /*
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
    */

    // Liste corps
    list<corps> listCorps;
    listCorps.push_back(lune);
    listCorps.push_back(terre);
    //listCorps.push_back(mars);

    // Crée une fenêtre 
    int largeur = 1366;
    int hauteur = 768;
    sf::RenderWindow window(sf::VideoMode(largeur, hauteur), "gravite");
    window.requestFocus();	
    ecran fenetre;

    // generation des caracteristiques des corps
    for (auto& it : listCorps) {
        it.figure.setRadius(it.rayon * fenetre.grandissement);
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
        float coordX;
        float coordY;
        for (auto& it : listCorps) {
            // Changement rayons corps avec grossissement 
            it.figure.setRadius(it.rayon * fenetre.grandissement);

            it.acceleration(it, listCorps);
            it.mouvement(it);

            // Dessin des corps
            coordX = ((float)it.positionX + (float)fenetre.positionX) * fenetre.grandissement + largeur/2;
            coordY = ((float)it.positionY + (float)fenetre.positionY) * fenetre.grandissement + hauteur/2;

            it.figure.setPosition(nearbyint(coordX), nearbyint(coordY));
            window.draw(it.figure);
        }

        // Detection deplacement ecran
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            fenetre.deplacement(5, 0);
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            fenetre.deplacement(-5, 0);
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            fenetre.deplacement(0, 5);
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            fenetre.deplacement(0, -5);
        };
        // Detection zoom vers haut
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            fenetre.zoom((char)1);
        };
        // Detection zoom vers bas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
            fenetre.zoom((char)0);
        };


    window.display();  // affiche tout
    sleep(0.001);

    }
    return 0;

}

