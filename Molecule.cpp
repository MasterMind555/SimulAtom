#include "Molecule.h"


Molecule::Molecule(Atom components[]){

    *atoms = components;//Sets the 'atoms' variables to the given components
    posX = atoms[0]->getPosX();//Gets the atom's position from its first component
    posY = atoms[0]->getPosY();

    int temp = 0;
    int i;
    for(i = 0; i < sizeof(atoms); i++)
    {
        temp += atoms[i]->getTemperature();//Gets the average temperature of the atoms
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
