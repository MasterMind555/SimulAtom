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

    const bool h[6][5] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1}
    };

    const bool he[6][11] = {
        { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
        { 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        { 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0},
        { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        { 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0}
    };

    int i, e;

    for(i = 0; i < 2; i++)
        atomIcons.push_back(atomIconTemplate);

    for(i = 0; i < 6; i++)
        for(e = 0; e < 5; e++)
            if(h[i][e])
                CSurface::setPixel(atomIcons[0], ATOM_ICON_WIDTH / 2 - 3 + e, ATOM_ICON_HEIGHT / 2 - 2 + i, 0xFFFFFF);

    menuButtons[PLAY_BUTTON].setIcon(&playIcon);
    menuButtons[EXIT_BUTTON].setIcon(&exitIcon);


    return true;
}
