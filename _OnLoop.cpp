#include "_SimulAtomMain.h"



//Variables for the FPS limitor
int fpsFrames;
int fpsCurrentTime;
int fpsLastUpdateTime;
int fpsElapsedTime;

void SimulAtomMain::OnLoop() {
    if(gameState == GAME_SCREEN)
    {

    int count1, count2;
    int i, e;

    count1 = SDL_GetTicks();
    for(i = 0; i < MAX_ATOMS; i++)
        if(atoms[i] != NULL)
            {
                atoms[i]->move();

                for(e = 0; e < MAX_ATOMS; e++)
                    if(atoms[e] != NULL && e != i)
                    {
                        if(checkCollision(atoms[i]->getPosX(), atoms[i]->getPosY(), atoms[e]->getPosX(), atoms[e]->getPosY()))
                        {
                            free(atoms[i]);
                            atoms[i] = NULL;
                            free(atoms[e]);
                            atoms[e] = NULL;
                            break;
                        }

                    }
            }
        count2 = SDL_GetTicks();
        printf("%d \n", count2 - count1);
    }

    fpsFrames++;
    fpsLastUpdateTime = fpsCurrentTime;
    fpsCurrentTime = SDL_GetTicks();
    fpsElapsedTime = fpsCurrentTime - fpsLastUpdateTime;

    int waitTime = (int)((1000/MAX_FPS) - fpsElapsedTime);
    /*
    if(waitTime > 0)
        SDL_Delay(waitTime);*/

}

bool SimulAtomMain::checkCollision(int xA, int yA, int xB, int yB ){

    if( yA + ATOM_ICON_HEIGHT <= yB )
    {
        return false;
    }

    if( yA >= yB + ATOM_ICON_HEIGHT )
    {
        return false;
    }

    if( xA + ATOM_ICON_WIDTH <= xB )
    {
        return false;
    }

    if( xA >= xB + ATOM_ICON_WIDTH )
    {
        return false;
    }

    return true;
}
