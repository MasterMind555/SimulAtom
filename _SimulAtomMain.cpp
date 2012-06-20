#include "_SimulAtomMain.h"



SimulAtomMain::SimulAtomMain() {
    screen = NULL;
    saLogo = NULL;
    background = NULL;
    playIcon = NULL;
    exitIcon = NULL;
    atomIcon = NULL;

    int i;
    for(i = 0; i < 32; i++)
        atoms[i] = NULL;


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

    setAtomDemo();

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

void SimulAtomMain::setAtomDemo(){
    atoms[0] = new Atom(500, 400, 1, 1);

}

void SimulAtomMain::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){

    if(gameState == GAME_SCREEN)
    {
        if(sym == SDLK_ESCAPE)
            gameState = MAIN_MENU;
    }
}
void SimulAtomMain::OnLButtonDown(int mX, int mY){

    if(menuButtons[EXIT_BUTTON].checkMouseClick(mX, mY, true))
    {
        Running = false;
    }
    else if(menuButtons[PLAY_BUTTON].checkMouseClick(mX, mY, true))
    {
        gameState = GAME_SCREEN;
    }

}
