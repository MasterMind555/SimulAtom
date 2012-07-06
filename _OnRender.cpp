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
            CSurface::onDraw(screen, moleculeIconTemplate, molecules[i]->getPosX(), molecules[i]->getPosY(), NULL);

            int h, w;
            if(TTF_SizeText(font, molecules[i]->getFormula(), &w, &h)){
                printf("%s", TTF_GetError());
            }

            CSurface::onDraw(screen,
                         TTF_RenderText_Solid(font, molecules[i]->getFormula(), textColor),
                         (MOLECULE_ICON_WIDTH / 2) - (w / 2) + molecules[i]->getPosX(),
                         (MOLECULE_ICON_HEIGHT / 2) - (h / 2) + molecules[i]->getPosY(),
                         NULL);
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
