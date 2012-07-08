#include "Molecule.h"



Molecule::Molecule(Atom** components, int size, SDL_Surface* iconTemplate, TTF_Font* font) {

    int i;
    for(i = 0; i < size; i++)
        atoms.push_back(components[i]);

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
        for(e = 0; e < sizeof(symb2); e++)
        {
            if(symb2[e] == '\x0')
                break;
        }

        formula = (char*) malloc (i + e + 1);
        memset(formula, '\x0', i + e + 1);
        memcpy(formula, symb1, i);
        memcpy(formula + i, symb2, e);

    }

    posX = atoms[0]->getPosX();
    posY = atoms[0]->getPosY();

    int temp = 0;
    for(i = 0; i < size; i++)
    {
        temp += components[i]->getTemperature();
    }

    if(temp > 0)
        temp = temp /  size;

    temperature = temp;

    icon = CSurface::onLoadPng("img/molecule.png");//Not the best, but works

    int h, w;
    if(TTF_SizeText(font, formula, &w, &h)){
        printf("%s", TTF_GetError());
    }

    CSurface::onDraw(icon,
                 TTF_RenderText_Solid(font, formula, textColor),
                 (MOLECULE_ICON_WIDTH / 2) - (w / 2),
                 (MOLECULE_ICON_HEIGHT / 2) - (h / 2),
                 NULL);

}

Molecule::~Molecule(){

    free(icon);

    int i;
    for(i = 0; i < atoms.size(); i++)
        free(atoms[i]);

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

SDL_Surface* Molecule::getIcon() {
    return icon;
}
