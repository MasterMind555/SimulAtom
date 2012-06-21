#include "Molecule.h"

#include <stdio.h>

Molecule::Molecule(Atom* components, int size){


    atoms = components;//Sets the 'atoms' variables to the given components
    posX = atoms[0].getPosX();//Gets the atom's position from its first component
    posY = atoms[0].getPosY();

    velX = 0;
    velY = 0;

    numAtoms = size;

    atoms = components;

    int temp = 0;
    int i;
    for(i = 0; i < numAtoms; i++)
    {
        temp += components[i].getTemperature();
    }

    if(temp > 0)
        temp = temp /  numAtoms;

    temperature = temp;

}

void Molecule::move(){
    int wiggleX = 0;
    int wiggleY = 0;

    wiggleX = ((rand() % 3) - 1) * (temperature / 50);
    wiggleY = ((rand() % 3) - 1) * (temperature / 50);


    if(posX + velX < 0 || posX + velX > SCREEN_WIDTH - MOLECULE_ICON_WIDTH){//Minus 20 because of the offset of the texture ( Which is 20x20 )
        velX *= -1;
    }

    if(posY + velY < 0 || posY + velY > SCREEN_HEIGHT - MOLECULE_ICON_HEIGHT){
        velY *= -1;
    }

    if(posX + wiggleX < 0 || posX + wiggleX > SCREEN_WIDTH - MOLECULE_ICON_WIDTH){//Minus 20 because of the offset of the texture ( Which is 20x20 )
        wiggleX *= -1;
    }

    if(posY + wiggleY < 0 || posY + wiggleY > SCREEN_HEIGHT - MOLECULE_ICON_HEIGHT){
        wiggleY *= -1;
    }

    posX += velX + wiggleX;
    posY += velY + wiggleY;
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
