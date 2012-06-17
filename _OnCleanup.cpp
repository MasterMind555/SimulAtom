#include "_SimulAtomMain.h"

void SimulAtomMain::OnCleanup() {
    free(screen);
    free(saLogo);
    free(background);
    SDL_Quit();
}
