#include "_SimulAtomMain.h"



//Variables for the FPS limitor
int fpsFrames;
int fpsCurrentTime;
int fpsLastUpdateTime;
int fpsElapsedTime;

void SimulAtomMain::OnLoop() {
    int i;
    for(i = 0; i < 32; i++)
        if(atoms[i] != NULL)
            {
                atoms[i]->move();
            }


    fpsFrames++;
    fpsLastUpdateTime = fpsCurrentTime;
    fpsCurrentTime = SDL_GetTicks();
    fpsElapsedTime = fpsCurrentTime - fpsLastUpdateTime;

    int waitTime = (int)((1000/MAX_FPS) - fpsElapsedTime);

    if(waitTime > 0)
        SDL_Delay(waitTime);

}
