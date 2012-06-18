#include "_SimulAtomMain.h"



SimulAtomMain::SimulAtomMain() {
    screen = NULL;
    saLogo = NULL;
    background = NULL;
    playIcon = NULL;
    exitIcon = NULL;
    Running = true;
    gameState = MAIN_MENU;


    menuButtons[EXIT_BUTTON].setWidth(119);
    menuButtons[EXIT_BUTTON].setHeight(50);
    menuButtons[EXIT_BUTTON].setX(100);
    menuButtons[EXIT_BUTTON].setY(SCREEN_HEIGHT - 60);
    if(menuButtons[EXIT_BUTTON].checkIfValid() == false)
        printf("Problem while initializing the %dth button", EXIT_BUTTON);

    menuButtons[PLAY_BUTTON].setWidth(117);
    menuButtons[PLAY_BUTTON].setHeight(50);
    menuButtons[PLAY_BUTTON].setX(SCREEN_WIDTH - 117 - 100);
    menuButtons[PLAY_BUTTON].setY(SCREEN_HEIGHT - 60);
    if(menuButtons[PLAY_BUTTON].checkIfValid() == false)
        printf("Problem while initializing the %dth button", PLAY_BUTTON);


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
