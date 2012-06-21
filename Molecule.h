#ifndef MOLECULE_H_INCLUDED
#define MOLECULE_H_INCLUDED

#include "Atom.h"

class Molecule{
    public:
                        Molecule(Atom* components, int size);
        int             getPosX();
        int             getPosY();
        void            setPosX(int val);
        void            setPosY(int val);

        int             getTemperature();
        void            setTemperature(int val);

        void            move();

    private:
        int             posX;
        int             posY;

        int             velX;
        int             velY;

        Atom*           atoms;
        int             numAtoms;

        int             temperature;



};


#endif // MOLECULE_H_INCLUDED
