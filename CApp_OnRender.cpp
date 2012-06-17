#include "CApp.h"
#include "CSurface.h"

void CApp::OnRender() {

    if(gameState == GAME_SCREEN)
    {
        CSurface::OnDraw(screen, background, 0, 0);
    }
    else if(gameState == MAIN_MENU)
    {
        CSurface::OnDraw(screen, background, 0, 0);
        CSurface::OnDraw(screen, saLogo, (SCREEN_WIDTH - SA_LOGO_WIDTH) / 2, (SCREEN_HEIGHT - SA_LOGO_HEIGHT) / 2 );
    }


    SDL_Flip(screen);
}
