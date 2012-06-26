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

    menuButtons[PLAY_BUTTON].setIcon(&playIcon);
    menuButtons[EXIT_BUTTON].setIcon(&exitIcon);


    return true;
}
