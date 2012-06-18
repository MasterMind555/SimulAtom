#ifndef BUTTON_H_INCLUDED
    #define BUTTON_H_INCLUDED

#include <SDL.h>

/*

    TODO: Add support for buttons with different shapes

*/

class Button {

    public:
                        Button();
        bool            checkMouseClick(int X, int Y, bool click);
        bool            checkMouseOver(int X, int Y);
        bool            checkMouseExit(int X, int Y);
        bool            checkIfValid();

        void            sleep();//Resets some of the variables used by the event functions to prevent unwanted behaviors

        int             getX();
        int             getY();
        void            setX(int val);
        void            setY(int val);

        int             getWidth();
        int             getHeight();
        void            setWidth(int val);
        void            setHeight(int val);

        SDL_Surface*    getIcon();
        void            setIcon(SDL_Surface* newIcon);

    private:
        int             x;
        int             y;
        int             width;
        int             height;
        SDL_Surface*    icon;
        bool            lastPos;//If the mouse was on the button last time we checked




};

#endif // BUTTON_H_INCLUDED
