#ifndef BUTTON_H_INCLUDED
    #define BUTTON_H_INCLUDED

#include <SDL.h>

class Button {

    public:
                        Button();
        void            checkClick(int X, int Y);

        bool             checkIfValid();

        int             getX();
        int             getY();
        void            setX(int val);
        void            setY(int val);

        int             getWidth();
        int             getHeight();
        void            setWidth(int val);
        void            setHeight(int val);

        SDL_Surface*    getIcon();
        void            setIcon(SDL_Surface* icon);
    private:
        int             x;
        int             y;
        int             width;
        int             height;
        SDL_Surface*    icon;

        void (*action)();




};

#endif // BUTTON_H_INCLUDED
