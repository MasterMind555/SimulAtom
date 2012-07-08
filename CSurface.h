#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

/*
    Surface 'Library', holds methods to load and draw SDL_Surface's

    THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE").
    THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.
    ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

    BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.
    TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
*/

#include <SDL.h>
#include <SDL_image.h>

class CSurface {
    public:
        CSurface();

    public:
        static SDL_Surface* onLoad(char* file);

        static SDL_Surface* onLoadPng(char* file);

        static bool onDraw(SDL_Surface* destination, SDL_Surface* source, int X, int Y, SDL_Rect* section);

        static bool transparent(SDL_Surface* destination, int R, int G, int B);

        static void setPixel(SDL_Surface* target, int x, int y, Uint32 color);
};

#endif
