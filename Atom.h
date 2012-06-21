#ifndef ATOM_H_INCLUDED
#define ATOM_H_INCLUDED

#include "Constants.h"
#include <stdlib.h>

class Atom{

    public:
                        Atom();
                        Atom(int x, int y, int numProtons, int numNeutrons);
        int             getPosX();
        int             getPosY();

        void            setPosX(int val);
        void            setPosY(int val);

        int             getVelX();
        int             getVelY();

        void            setVelX(int val);
        void            setVelY(int val);

        int             getAmountProtons();
        void            setAmountProtons(int val);

        int             getAmountNeutrons();
        void            setAmountNeutrons(int val);

        int             getTemperature();
        void            setTemperature(int val);

        bool            getBonded();
        //void          setBonded(bool val);

        void            move();


    private:
        int             posX;
        int             posY;
        int             velX;
        int             velY;
        int             protons;
        int             neutrons;
        bool            bonded;
        int             temperature;


};


#endif // ATOM_H_INCLUDED
