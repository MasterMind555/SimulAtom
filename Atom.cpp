#include "Atom.h"

Atom::Atom(int x, int y, int numProtons, int numNeutrons, int oxydationNum, float valEn){

    //Initializes a new Atom of given type with the given coordinates at 0K
    posX = x;
    posY = y;
    protons = numProtons;
    neutrons = numNeutrons;
    oxydationNumber = oxydationNum;
    en = valEn;

    temperature = 295;
    velX = 0;
    velY = 0;
}

Atom::Atom(AtomTemplate properties, int x, int y){
    posX = x;
    posY = y;
    protons = properties.protons;
    neutrons = properties.neutrons;
    oxydationNumber = properties.oxydationNumber;
    en = properties.en;
    metal = properties.metal;
    temperature = 295;

    velX = 0;
    velY = 0;
}

Atom::Atom(){

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

int Atom::getOxyNumber(){
    return oxydationNumber;
}

void Atom::setOxyNumber(int val){
    oxydationNumber = val;
}

bool Atom::getMetal(){
    return metal;
}

void Atom::setMetal(bool val){
    metal = val;
}

/*
void setBonded(bool val){

}
*/

float Atom::getEn(){
    return en;
}

void Atom::setEn(float val){
    en = val;
}


void Atom::move(){

    velX += ((rand() % 3) - 1) * (temperature / 50);//Moves randomly
    velY += ((rand() % 3) - 1) * (temperature / 50);

    if(posX + velX < 0 || posX + velX > SCREEN_WIDTH - ATOM_ICON_WIDTH){//Minus 20 because of the offset of the texture ( Which is 20x20 )
        velX *= ATOM_SPEED_LOSS;
    }

    if(posY + velY < 0 || posY + velY > SCREEN_HEIGHT - ATOM_ICON_HEIGHT){
        velY *= ATOM_SPEED_LOSS;
    }

    posX += velX;
    posY += velY;

}
