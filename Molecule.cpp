#include "Molecule.h"

#include <stdio.h>
#include <string.h>

Molecule::Molecule(Atom* components, int size) {

    velX = 0;
    velY = 0;

    int i;
    for(i = 0; i < size; i++)
        atoms.push_back(&components[i]);

    char *symb1 = (char*)TAtoms[atoms[0]->getAmountProtons()].symbol;
    char *symb2 = (char*)TAtoms[atoms[1]->getAmountProtons()].symbol;

    if(atoms[0]->getAmountProtons() == atoms[1]->getAmountProtons())//TODO: Add support for more then 2 atoms
    {
        for(i = 0; i < sizeof(symb1); i++)
        {
            if(symb1[i] == '\x0')
                break;
        }

        formula = (char*) malloc (i + 2);
        memcpy(formula, symb1, i);
        char num = '2';
        formula[i] = num;
        formula[i + 1] = '\x0';
    }
    else
    {
        for(i = 0; i < sizeof(symb1); i++)
        {
            if(symb1[i] == '\x0')
                break;
        }
        int e;
        for(e = 0; e < sizeof(symb1); e++)
        {
            if(symb1[e] == '\x0')
                break;
        }
        formula = (char*) malloc (i + e + 1);
        memcpy(formula, symb1, i);
        memcpy(formula + i, symb2, e);
        formula[i + e + 1] = '\x0';
    }

    //printf("%s \n", formula);
    posX = atoms[0]->getPosX();
    posY = atoms[0]->getPosY();

    int temp = 0;
    for(i = 0; i < size; i++)
    {
        temp += components[i].getTemperature();
    }

    if(temp > 0)
        temp = temp /  size;

    temperature = temp;

}

void Molecule::move() {
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

int Molecule::getPosX() {
    return posX;
}

int Molecule::getPosY() {
    return posY;
}

void Molecule::setPosX(int val) {
    posX = val;
}

void Molecule::setPosY(int val) {
    posY = val;
}

int Molecule::getVelX() {
    return velX;
}

int Molecule::getVelY() {
    return velY;
}

void Molecule::setVelX(int val) {
    velX = val;
}

void Molecule::setVelY(int val) {
    velY = val;
}

int Molecule::getTemperature() {
    return temperature;
}

void Molecule::setTemperature(int val) {
    temperature = val;
}

char* Molecule::getFormula() {
    return formula;
}
