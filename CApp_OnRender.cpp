#include "CApp.h"
#include "CSurface.h"

void CApp::OnRender() {

    if(gameState == Game_screen)
    {

    }
    else if(gameState == Main_menu)
    {
        CSurface::OnDraw(screen, background, 0, 0);
        CSurface::OnDraw(screen, saLogo, (SCREEN_WIDTH - SA_LOGO_WIDTH) / 2, (SCREEN_HEIGHT - SA_LOGO_HEIGHT) / 2 );
    }


    SDL_Flip(screen);
}
