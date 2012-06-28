#include "_SimulAtomMain.h"
#include "CSurface.h"

void SimulAtomMain::OnRender() {

    if(gameState == GAME_SCREEN)
    {
        CSurface::onDraw(screen, background, 0, 0);

        int i;

        for(i = 0; i < atoms.size(); i++)
                CSurface::onDraw(screen, atomIcons[0], atoms[i]->getPosX(), atoms[i]->getPosY());

        for(i = 0; i < molecules.size(); i++)
                CSurface::onDraw(screen, moleculeIcon, molecules[i]->getPosX(), molecules[i]->getPosY());

        CSurface::onDraw(screen, elMenuIcon, elMenuButton.getX(), elMenuButton.getY());
    }
    else if(gameState == MAIN_MENU)
    {
        CSurface::onDraw(screen, background, 0, 0);
        CSurface::onDraw(screen, saLogo, (SCREEN_WIDTH - SA_LOGO_WIDTH) / 2, (SCREEN_HEIGHT - SA_LOGO_HEIGHT) / 2 );

        int i;
        for(i = 0; i < NUM_MENU_BUTTONS; i++)
        {
            CSurface::onDraw(screen, menuButtons[i].getIcon(), menuButtons[i].getX(), menuButtons[i].getY());
        }
    }


    SDL_Flip(screen);
}
