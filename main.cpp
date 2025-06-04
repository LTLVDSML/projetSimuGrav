#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "corps.h"

// Commande pour generer executable (depuis le fichier racine du code) :
//   g++ main.cpp corps.cpp -o gravite
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
    terre.masse        = 10;
    terre.positionX    = 5;
    terre.positionY    = 5;
    terre.vitesseX     = 0;
    terre.vitesseY     = 0;

    terre.sommeVitesseX = 0;

    corps lune;
    lune.nom          = "lune";
    lune.fixe         = false;
    lune.nonInfluence = false;
    lune.masse        = 1;
    lune.positionX    = 1;
    lune.positionY    = 1;
    lune.vitesseX     = 0;
    lune.vitesseY     = 0;

    lune.sommeVitesseX = 0;


    for (int idx = 0; idx < 100; idx++) {
        std::cout << idx << std::endl;
        terre.mouvement(lune);
        lune.mouvement(terre);
        sleep(1);
    }

    return 0;

}

