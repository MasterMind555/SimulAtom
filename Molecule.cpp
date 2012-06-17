#include "Molecule.h"


Molecule::Molecule(Atom components[]){

    *atoms = components;
    posX = atoms[0]->getPosX();
    posY = atoms[0]->getPosY();

    int temp = 0;
    int i;
    for(i = 0; i < sizeof(atoms); i++)
    {
        temp += atoms[i]->getTemperature();
    }
    temp /= i;

    temperature = temp;
}

int Molecule::getPosX(){
    return posX;
}

int Molecule::getPosY(){
    return posY;
}

void Molecule::setPosX(int val){
    posX = val;
}

void Molecule::setPosY(int val){
    posY = val;
}

int Molecule::getTemperature(){
    return temperature;
}

void Molecule::setTemperature(int val){
    temperature = val;
}
