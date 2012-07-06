#include "_SimulAtomMain.h"

void SimulAtomMain::OnCleanup() {
    free(screen);

    free(background);
    free(saLogo);

    free(playIcon);
    free(exitIcon);

    free(elMenuIcon);

    free(atomIconTemplate);
    free(moleculeIconTemplate);

    free(font);

    int i;
    for(i = 0; i < sizeof(atomIcons) / sizeof(Button); i++)
        delete(atomIcons[i]);
    for(i = 0; i < atoms.size(); i++)
        delete(atoms[i]);
    for(i = 0; i < molecules.size(); i++)
        delete(molecules[i]);

    atoms.clear();
    molecules.clear();

    TTF_Quit();
    SDL_Quit();
}
