#include "_SimulAtomMain.h"



SimulAtomMain::SimulAtomMain() {
    screen = NULL;
    saLogo = NULL;
    background = NULL;
    Running = true;
    gameState = MAIN_MENU;
}

int SimulAtomMain::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {

        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();

        OnRender();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    SimulAtomMain theApp;

    return theApp.OnExecute();
}

void SimulAtomMain::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){

    if(gameState == MAIN_MENU)
    {
        if(sym == SDLK_RETURN)
            gameState = GAME_SCREEN;
    }
    else if(gameState == GAME_SCREEN)
    {
        if(sym == SDLK_ESCAPE)
            gameState = MAIN_MENU;
    }
}
