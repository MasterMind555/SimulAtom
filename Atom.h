#ifndef ATOM_H_INCLUDED
#define ATOM_H_INCLUDED


/*
    Atom template class.

    THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE").
    THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.
    ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

    BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.
    TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
*/

#include "Constants.h"
#include <stdlib.h>


class Atom{

    public:
                        Atom(AtomTemplate properties, int x, int y);
                        Atom();
                        ~Atom();
                        Atom(int x, int y, int numProtons, int numNeutrons, int oxydationNum, float valEn);
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

        int             getOxyNumber();
        void            setOxyNumber(int val);

        float           getEn();
        void            setEn(float val);

        bool            getMetal();
        void            setMetal(bool val);

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
        int             oxydationNumber;
        float           en;//Electronegativity
        bool            metal;

};


#endif // ATOM_H_INCLUDED
