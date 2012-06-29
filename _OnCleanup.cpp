#include "_SimulAtomMain.h"

void SimulAtomMain::OnCleanup() {
    free(screen);
    free(saLogo);
    free(background);
    free(playIcon);
    free(exitIcon);
    free(atomIconTemplate);
    free(moleculeIcon);
    free(fontSpriteSheet);

    int i;
    for(i = 0; i < atoms.size(); i++)
        delete(atoms[i]);
    for(i = 0; i < molecules.size(); i++)
        delete(molecules[i]);
    for(i = 0; i < font.size(); i++)
        delete(font[i]);
    atoms.clear();
    molecules.clear();
    font.clear();

    SDL_Quit();
}
