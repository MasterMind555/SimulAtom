#include "_SimulAtomMain.h"


SimulAtomMain::SimulAtomMain() {

    //Sets all the pointers to NULL
    screen = NULL;
    saLogo = NULL;
    background = NULL;
    playIcon = NULL;
    exitIcon = NULL;
    atomIconTemplate = NULL;

    preciseCollision = false;

    running = true;
    simulating = true;
    gameState = MAIN_MENU;


    //Sets the play and exit button's position and size
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

    while(running) {

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
    int i;
    for(i = 0; i < MAX_ATOMS; i++)
            atoms.push_back(new Atom(THydrogen, rand() % SCREEN_WIDTH - ATOM_ICON_WIDTH, rand() % SCREEN_HEIGHT - ATOM_ICON_HEIGHT));


}

void SimulAtomMain::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){

    if(gameState == GAME_SCREEN)
    {
        if(sym == SDLK_ESCAPE)
            gameState = MAIN_MENU;
        if(sym == SDLK_SPACE)
            simulating = !simulating;
    }
}

void SimulAtomMain::OnLButtonDown(int mX, int mY){

    if(menuButtons[EXIT_BUTTON].checkMouseClick(mX, mY, true))
    {
        running = false;
    }
    else if(menuButtons[PLAY_BUTTON].checkMouseClick(mX, mY, true))
    {
        gameState = GAME_SCREEN;
    }

}
