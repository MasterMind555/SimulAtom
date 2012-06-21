#include "_SimulAtomMain.h"

void SimulAtomMain::OnCleanup() {
    free(screen);
    free(saLogo);
    free(background);
    free(playIcon);
    free(exitIcon);
    free(atomIcon);

    free(moleculeIcon);

    int i;
    for(i = 0; i < MAX_ATOMS; i++)
        free(atoms[i]);
    free(atoms);

    for(i = 0; i < MAX_MOLECULES; i++)
        free(molecules[i]);
    free(molecules);


    SDL_Quit();
}
