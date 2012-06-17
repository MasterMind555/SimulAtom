#ifndef MOLECULE_H_INCLUDED
#define MOLECULE_H_INCLUDED

#include "Atom.h"

class Molecule{
    public:
                        Molecule(Atom components[]);
        int             getPosX();
        int             getPosY();
        void            setPosX(int val);
        void            setPosY(int val);

        int             getTemperature();
        void            setTemperature(int val);

    private:
        int             posX;
        int             posY;
        Atom*           atoms[];
        int             temperature;



};


#endif // MOLECULE_H_INCLUDED
