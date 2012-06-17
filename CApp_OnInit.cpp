#include "CApp.h"
#include "CSurface.h"
#include "Constants.h"

bool CApp::OnInit() {


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((saLogo = CSurface::OnLoadPng("img/logo.png")) == NULL) {
        printf("Can't find SimulAtom Logo");
        return false;
    }
    if((background = CSurface::OnLoadPng("img/background.png")) == NULL) {
        printf("Can't find background");
        return false;
    }

    return true;
}
