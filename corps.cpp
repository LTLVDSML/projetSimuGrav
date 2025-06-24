#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "corps.h"

using namespace std;

corps::corps() {}

void corps::acceleration(corps, std::list<corps>&listeCibles){
    accelerationX = 0;
    accelerationY = 0;

    for (auto& it : listeCibles) {
        //const float G = 6.67e-11f;
        const float G = 6.67e-7f;
        float distanceX = it.positionX - positionX;
        float distanceY = it.positionY - positionY;
        float distance = sqrt(pow(distanceX,2)+pow(distanceY,2));

        // Detection du cas ou il s'agit de la meme planete
        if (&it != this && distance !=0) {
            float acc = (G * it.masse)/pow(distance,2);

            float cos = distanceX/distance;
            float sin = distanceY/distance;

            float accX = acc * cos;
            float accY = acc * sin;

            accelerationX = accelerationX + accX;
            accelerationY = accelerationY + accY;
        }

    }

}

void corps::mouvement(corps) {

    vitesseX = vitesseX + accelerationX;
    vitesseY = vitesseY + accelerationY;

    positionX = positionX + vitesseX;
    positionY = positionY + vitesseY;

    std::cout << nom << " → position : (" << positionX << ", " << positionY << ")\n";
    std::cout << nom << " → vitesse : (" << vitesseX << ", " << vitesseY << ")\n";
    std::cout << nom << " → acceleration : (" << accelerationX << ", " << accelerationY << ")\n";

}
