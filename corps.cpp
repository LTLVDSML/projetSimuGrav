#include <iostream>
#include <cmath>
#include "corps.h"

corps::corps() {}

void corps::mouvement(corps &cible) {
       
    // const float G = 6.67e-11f;
    const float G = 6.67e-3f;

    float distanceX = cible.positionX - positionX;
    float distanceY = cible.positionY - positionY;
    float distance = sqrt(pow(distanceX,2)+pow(distanceX,2));

    if (distance == 0) return; // évite division par zéro
    
    float acceleration = (G * cible.masse)/pow(distance,2);
    
    float cos = distanceX/distance;
    float sin = distanceY/distance;

    float accX = acceleration * cos;
    float accY = acceleration * sin;

    vitesseX = vitesseX + accX;
    vitesseY = vitesseY + accY;

    positionX = positionX + vitesseX;
    positionY = positionY + vitesseY;

    std::cout << nom << " → position : (" << positionX << ", " << positionY << ")\n";
    std::cout << nom << " → vitesse : (" << vitesseX << ", " << vitesseY << ")\n";
    std::cout << nom << " → acceleration : (" << accX << ", " << accY << ")\n";

}