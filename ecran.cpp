#include <iostream>
#include "ecran.h"

using namespace std;

ecran::ecran() : positionX(0), positionY(0), grandissement(1) {}

void ecran::deplacement(int dX, int dY){
    positionX = positionX + dX;
    positionY = positionY + dY;
}

void ecran::zoom(char dA){
    // Vers l'avant
    if (dA == 1){
    grandissement = grandissement * 0.9;
    }
    // Vers l'arriere
    else if (dA == 0){
    grandissement = grandissement * 1.1;
    }
    // std::cout << grandissement << "\n";
}
