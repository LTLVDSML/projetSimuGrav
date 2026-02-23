#include <iostream>
#include "ecran.h"

using namespace std;

ecran::ecran() : positionX(0), positionY(0) {}

void ecran::deplacement(int dX, int dY){
    positionX = positionX + dX;
    positionY = positionY + dY;
}
