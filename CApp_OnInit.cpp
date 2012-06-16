#include "CApp.h"
#include "CSurface.h"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((screen = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }


    return true;
}
