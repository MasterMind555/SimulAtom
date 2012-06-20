#ifndef BUTTON_H_INCLUDED
    #define BUTTON_H_INCLUDED

/*
    Button class, used for interaction with the mouse during some mouse events

    TODO: Add support for buttons with different shapes

    THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE").
    THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.
    ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

    BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.
    TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
*/

#include <SDL.h>
#include "Constants.h"

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
        void            setIcon(SDL_Surface** newIcon);

    private:
        int             x;
        int             y;
        int             width;
        int             height;
        SDL_Surface**   icon;
        bool            lastPos;//If the mouse was on the button last time we checked




};

#endif // BUTTON_H_INCLUDED
