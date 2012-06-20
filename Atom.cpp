#include "Atom.h"

Atom::Atom(int x, int y, int numProtons, int numNeutrons){

    //Initializes a new Atom of given type with the given coordinates at 0K
    posX = x;
    posY = y;
    protons = numProtons;
    neutrons = numNeutrons;
    temperature = 295;

    velX = 0;
    velY = 0;
}

int Atom::getPosX(){
    return posX;
}

int Atom::getPosY(){
    return posY;
}

void Atom::setPosX(int val){
    posX = val;
}

void Atom::setPosY(int val){
    posY = val;
}

int Atom::getVelX(){
    return velX;
}

int Atom::getVelY(){
    return velY;
}

void Atom::setVelX(int val){
    velX = val;
}

void Atom::setVelY(int val){
    velY = val;
}

int Atom::getAmountProtons(){
    return protons;
}

void Atom::setAmountProtons(int val){
    protons = val;
}

int Atom::getAmountNeutrons(){
    return neutrons;
}

void Atom::setAmountNeutrons(int val){
    neutrons = val;
}

bool Atom::getBonded(){
    return bonded;
}

int Atom::getTemperature(){
    return temperature;
}

void Atom::setTemperature(int val){
    temperature = val;
}

/*
void setBonded(bool val){

}
*/

void Atom::move(){

    int wiggleX = 0;
    int wiggleY = 0;

    wiggleX = ((rand() % 3) - 1) *(temperature / 50);
    wiggleY = ((rand() % 3) - 1)*(temperature / 50);


    if(posX + velX < 0 || posX + velX > SCREEN_WIDTH - 20){//Minus 20 because of the offset of the texture ( Which is 20x20 )
        velX *= -1;
    }

    if(posY + velY < 0 || posY + velY > SCREEN_HEIGHT - 20){
        velY *= -1;
    }

    if(posX + wiggleX < 0 || posX + wiggleX > SCREEN_WIDTH - 20){//Minus 20 because of the offset of the texture ( Which is 20x20 )
        wiggleX *= -1;
    }

    if(posY + wiggleY < 0 || posY + wiggleY > SCREEN_HEIGHT - 20){
        wiggleY *= -1;
    }

    posX += velX + wiggleX;
    posY += velY + wiggleY;

}