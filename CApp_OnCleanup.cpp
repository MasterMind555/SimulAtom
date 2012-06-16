#include "CApp.h"

void CApp::OnCleanup() {
    free(screen);

    SDL_Quit();
}
