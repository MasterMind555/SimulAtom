#include "CApp.h"

void CApp::OnCleanup() {
    free(screen);
    free(saLogo);
    free(background);
    SDL_Quit();
}
