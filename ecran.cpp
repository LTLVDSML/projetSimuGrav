#include <iostream>
#include "ecran.h"

using namespace std;

ecran::ecran() : positionX(0), positionY(0), grandissement(1) {}

void ecran::deplacement(int dX, int dY){
    positionX = positionX + dX;
    positionY = positionY + dY;
}

void ecran::zoom(float dA){
    if (grandissement + dA > 0.1){
    grandissement = grandissement + dA;
    }
    std::cout << grandissement << "\n";
}
