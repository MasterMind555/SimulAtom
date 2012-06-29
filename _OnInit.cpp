#include "_SimulAtomMain.h"
#include "CSurface.h"
#include "Constants.h"

bool SimulAtomMain::OnInit() {

    //Redirects stdout and stderr output to the debug console
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((saLogo = CSurface::onLoadPng("img/logo.png")) == NULL) {
        printf("Can't find SimulAtom Logo");
        return false;
    }

    if((background = CSurface::onLoadPng("img/background.png")) == NULL) {
        printf("Can't find background");
        return false;
    }

    if((playIcon = CSurface::onLoadPng("img/play.png")) == NULL) {
        printf("Can't find play icon");
        return false;
    }

    if((exitIcon = CSurface::onLoadPng("img/exit.png")) == NULL) {
        printf("Can't find exit icon");
        return false;
    }

    if((atomIconTemplate = CSurface::onLoadPng("img/atom.png")) == NULL) {
        printf("Can't find atom icon");
        return false;
    }

    if((moleculeIcon = CSurface::onLoadPng("img/h2.png")) == NULL) {
        printf("Can't find atom icon");
        return false;
    }
    if((elMenuIcon = CSurface::onLoadPng("img/menuslide.png")) == NULL) {
        printf("Can't find element menu icon");
        return false;
    }
    if((fontSpriteSheet = CSurface::onLoadPng("img/font-spritesheet.png")) == NULL) {
        printf("Can't find the font spritesheet");
        return false;
    }

    menuButtons[PLAY_BUTTON].setIcon(&playIcon);
    menuButtons[EXIT_BUTTON].setIcon(&exitIcon);

    atomIcons.push_back(atomIconTemplate);


    /*
    int i;
    for(i = 0; i < 62; i++)
    {
        SDL_Surface temp;
        SDL_Rect zone;
        zone.x = (i * 10) % 427;
        zone.y = (i / 427) * 11;
        zone.w = 10;
        zone.h = 11;
        printf("%d %d %d %d \n", zone.x, zone.y, zone.w, zone.h);
        CSurface::onDraw(&temp, fontSpriteSheet, 0, 0, &zone);
        font.push_back(&temp);
    }
    */



    return true;
}
