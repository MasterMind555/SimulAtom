#include "Atom.h"

Atom::Atom(int x, int y, int numProtons, int numNeutrons){

    posX = x;
    posY = y;
    protons = numProtons;
    neutrons = numNeutrons;
    temperature = 0;

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
