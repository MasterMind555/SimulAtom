#include "_SimulAtomMain.h"

void SimulAtomMain::OnCleanup() {
    free(screen);
    free(saLogo);
    free(background);
    free(playIcon);
    free(exitIcon);
    free(atomIcon);
    SDL_Quit();
}