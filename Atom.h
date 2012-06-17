#ifndef ATOM_H_INCLUDED
#define ATOM_H_INCLUDED

class Atom{
    public:
                        Atom(int x, int y, int numProtons, int numNeutrons);
        int             getPosX();
        int             getPosY();
        void            setPosX(int val);
        void            setPosY(int val);

        int             getAmountProtons();
        void            setAmountProtons(int val);

        int             getAmountNeutrons();
        void            setAmountNeutrons(int val);

        int             getTemperature();
        void            setTemperature(int val);

        bool            getBonded();
        //void          setBonded(bool val);


    private:
        int             posX;
        int             posY;
        int             protons;
        int             neutrons;
        bool            bonded;
        int             temperature;

};


#endif // ATOM_H_INCLUDED
