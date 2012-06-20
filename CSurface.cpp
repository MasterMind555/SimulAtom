#include "CSurface.h"

CSurface::CSurface() {
}

SDL_Surface* CSurface::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {//Tries to load the BMP into Surf_Temp
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);//Sets the image to the correct format
    SDL_FreeSurface(Surf_Temp);//Gets rid of the temporary surface

    return Surf_Return;
}

SDL_Surface* CSurface::OnLoadPng(char* File) {

    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL)//Tries to load the PNG
        return NULL;

    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);//Sets the image to the right format while keeping transparency
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));//Sets the given colour to transparent

    return true;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}
