#include "_SimulAtomMain.h"

void SimulAtomMain::OnLoop() {
    int i;
    for(i = 0; i < 32; i++)
        if(atoms[i] != NULL)
            {
                atoms[i]->move();
            }
}
