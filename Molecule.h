#ifndef MOLECULE_H_INCLUDED
#define MOLECULE_H_INCLUDED

/*
    Molecule template class.

    THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE").
    THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.
    ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

    BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.
    TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
*/

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "Atom.h"
#include "CSurface.h"


class Molecule{
    public:
                        Molecule(Atom** components, int size, SDL_Surface* iconTemplate, TTF_Font* font);
                        ~Molecule();
        int             getPosX();
        int             getPosY();
        void            setPosX(int val);
        void            setPosY(int val);

        int             getVelX();
        int             getVelY();
        void            setVelX(int val);
        void            setVelY(int val);

        int             getTemperature();
        void            setTemperature(int val);

        char*           getFormula();

        SDL_Surface*    getIcon();

        void            move();

    private:
        int             posX;
        int             posY;
        int             velX;
        int             velY;
        char*           formula;

        SDL_Surface*    icon;

        std::vector<Atom*>      atoms;


        int             temperature;



};


#endif // MOLECULE_H_INCLUDED
