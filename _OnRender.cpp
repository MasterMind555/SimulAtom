#include "_SimulAtomMain.h"
#include "CSurface.h"

void SimulAtomMain::OnRender() {

    if(gameState == GAME_SCREEN)
    {
        CSurface::OnDraw(screen, background, 0, 0);

        int i;
        for(i = 0; i < MAX_ATOMS; i++)
            if(atoms[i] != NULL)
            {
                CSurface::OnDraw(screen, atomIcon, atoms[i]->getPosX(), atoms[i]->getPosY());
            }
        for(i = 0; i < MAX_MOLECULES; i++)
            if(molecules[i] != NULL)
            {
                CSurface::OnDraw(screen, moleculeIcon, molecules[i]->getPosX(), molecules[i]->getPosY());
            }
    }
    else if(gameState == MAIN_MENU)
    {
        CSurface::OnDraw(screen, background, 0, 0);
        CSurface::OnDraw(screen, saLogo, (SCREEN_WIDTH - SA_LOGO_WIDTH) / 2, (SCREEN_HEIGHT - SA_LOGO_HEIGHT) / 2 );

        int i;
        for(i = 0; i < NUM_MENU_BUTTONS; i++)
        {
            CSurface::OnDraw(screen, menuButtons[i].getIcon(), menuButtons[i].getX(), menuButtons[i].getY());
        }
    }


    SDL_Flip(screen);
}
