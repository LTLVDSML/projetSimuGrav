#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "corps.h"

// Commande pour generer executable (depuis le fichier racine du code) :
//   g++ main.cpp corps.cpp -o gravite -lsfml-graphics -lsfml-window -lsfml-system
// Commande pour lancer l'executable (depuis le fichier racine de l'executable) :
//   ./gravite

// EXEMPLE///////////////////////////////////////////////////////////////

/*int main()
{
    // Crée une fenêtre de 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Demo");

    // Crée un cercle rouge
    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(200, 150);

    // Boucle principale
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Fermer la fenêtre si on clique sur la croix
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Efface la fenêtre (fond noir)
        window.clear();

        // Dessine le cercle
        window.draw(circle);

        // Affiche le contenu à l'écran
        window.display();
    }

    return 0;
}*/

/////////////////////////////////////////////////////////////////////////////


int main() {
    corps terre;
    terre.nom          = "terre";
    terre.fixe         = false;
    terre.nonInfluence = false;
    terre.masse        = 10000000;
    terre.positionX    = 100;
    terre.positionY    = 100;
    terre.vitesseX     = 1e-3;
    terre.vitesseY     = 0;

    corps lune;
    lune.nom          = "lune";
    lune.fixe         = false;
    lune.nonInfluence = false;
    lune.masse        = 1000000;
    lune.positionX    = 600;
    lune.positionY    = 550;
    lune.vitesseX     = 0;
    lune.vitesseY     = -1e-3;


    // Crée une fenêtre 
    sf::RenderWindow window(sf::VideoMode(1100, 600), "gravite");
    // Crée des cercles pour les planetes
    sf::CircleShape earth(20);
    earth.setFillColor(sf::Color::Blue);
    earth.setPosition(terre.positionX, terre.positionY);
    sf::CircleShape moon(10);
    moon.setFillColor(sf::Color::White);
    moon.setPosition(lune.positionX, lune.positionY);


    // Boucle de calcul
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

        terre.mouvement(lune);
        lune.mouvement(terre);
        sleep(0.01);

        // Affichage planetes
        earth.setPosition(terre.positionX, terre.positionY);
        moon.setPosition(lune.positionX, lune.positionY);
        // Efface la fenêtre (fond noir)
        window.clear();
        // Dessine les planetes
        window.draw(earth);
        window.draw(moon);
        // Affiche le contenu à l'écran
        window.display();

    }
    return 0;

}

