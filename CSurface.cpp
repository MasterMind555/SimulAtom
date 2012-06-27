#include "CSurface.h"

CSurface::CSurface() {
}

SDL_Surface* CSurface::onLoad(char* file) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = SDL_LoadBMP(file)) == NULL) {//Tries to load the BMP into Surf_Temp
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);//Sets the image to the correct format
    SDL_FreeSurface(Surf_Temp);//Gets rid of the temporary surface

    return Surf_Return;
}

SDL_Surface* CSurface::onLoadPng(char* file) {

    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = IMG_Load(file)) == NULL)//Tries to load the PNG
        return NULL;

    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);//Sets the image to the right format while keeping transparency
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

bool CSurface::transparent(SDL_Surface* destination, int R, int G, int B) {
    if(destination == NULL) {
        return false;
    }

    SDL_SetColorKey(destination, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(destination->format, R, G, B));//Sets the given colour to transparent

    return true;
}

void CSurface::setPixel(SDL_Surface* target, int x, int y, Uint32 color)
{
    Uint8* pixel = (Uint8*)target->pixels;
    pixel += (y * target->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = color;
}

bool CSurface::onDraw(SDL_Surface* destination, SDL_Surface* source, int X, int Y) {
    if(destination == NULL || source == NULL) {
        return false;
    }

    SDL_Rect destR;

    destR.x = X;
    destR.y = Y;

    SDL_BlitSurface(source, NULL, destination, &destR);

    return true;
}
