#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL.h>
#include <SDL_image.h>

class CSurface {
    public:
        CSurface();

    public:
        static SDL_Surface* OnLoad(char* File);

        static SDL_Surface* OnLoadPng(char* File);

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

        static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif
