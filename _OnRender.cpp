#include "_SimulAtomMain.h"
#include "CSurface.h"

void SimulAtomMain::OnRender() {

    if(gameState == GAME_SCREEN)
    {
        CSurface::onDraw(screen, background, 0, 0, NULL);

        int i;

        for(i = 0; i < atoms.size(); i++)
        {
            CSurface::onDraw(screen, atomIcons[atoms[i]->getAmountProtons()], atoms[i]->getPosX(), atoms[i]->getPosY(), NULL);
        }

        for(i = 0; i < molecules.size(); i++)
        {
            CSurface::onDraw(screen, molecules[i]->getIcon(), molecules[i]->getPosX(), molecules[i]->getPosY(), NULL);


        }

        CSurface::onDraw(screen, elMenuButton.getIcon(), elMenuButton.getX(), elMenuButton.getY(), NULL);
    }
    else if(gameState == MAIN_MENU)
    {
        CSurface::onDraw(screen, background, 0, 0, NULL);
        CSurface::onDraw(screen, saLogo, (SCREEN_WIDTH - SA_LOGO_WIDTH) / 2, (SCREEN_HEIGHT - SA_LOGO_HEIGHT) / 2, NULL);

        int i;
        for(i = 0; i < NUM_MENU_BUTTONS; i++)
        {
            CSurface::onDraw(screen, menuButtons[i].getIcon(), menuButtons[i].getX(), menuButtons[i].getY(), NULL);
        }

    }

    SDL_Flip(screen);
}
