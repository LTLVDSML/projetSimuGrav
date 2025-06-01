#include <SFML/Graphics.hpp>

// Commande pour generer executable (depuis le fichier racine du code) :
//   g++ main.cpp -o sfml_demo -lsfml-graphics -lsfml-window -lsfml-system
// Commande pour lancer l'executable (depuis le fichier racine de l'executable) :
//   ./sfml_demo

int main()
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
}
