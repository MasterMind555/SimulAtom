#include "_SimulAtomMain.h"



//Variables for the FPS limitor
int fpsFrames;
int fpsCurrentTime;
int fpsLastUpdateTime;
int fpsElapsedTime;

void SimulAtomMain::OnLoop() {

    if(gameState == GAME_SCREEN)
    {

    //int count1, count2;
    int i, e;

    //count1 = SDL_GetTicks();
    for(i = 0; i < atoms.size(); i++)
                atoms[i]->move();

    for(i = 0; i < atoms.size(); i++)
        for(e = 0; e < atoms.size(); e++)
            if(e != i)
            {
                if(checkCollision(atoms[i]->getPosX(), atoms[i]->getPosY(), atoms[e]->getPosX(), atoms[e]->getPosY()))
                {
                    //Only 2 atoms collision for now
                    if(atoms[i]->getOxyNumber() > 512 && atoms[e]->getOxyNumber() % 256 != 0) //If the first molecule has a positive oxydation number and the second one has a negative one
                    {
                        checkReaction(i, e, true);
                        break;
                    }
                    if(atoms[e]->getOxyNumber() > 512 && atoms[i]->getOxyNumber() % 256 != 0) //If the first molecule has a positive oxydation number and the second one has a negative one
                    {
                        checkReaction(i, e, false);
                        break;
                    }
                }
            }

    for(i = 0; i < molecules.size(); i++)
                molecules[i]->move();


        //count2 = SDL_GetTicks();
        //printf("%d \n", count2 - count1);


    fpsFrames++;
    fpsLastUpdateTime = fpsCurrentTime;
    fpsCurrentTime = SDL_GetTicks();
    fpsElapsedTime = fpsCurrentTime - fpsLastUpdateTime;

    int waitTime = (int)((1000/MAX_FPS) - fpsElapsedTime);

    if(waitTime > 0)
        SDL_Delay(waitTime);
    }

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

void SimulAtomMain::createMolecule(int i, int numI, int e, int numE)
{
    Atom reactives[numI + numE];

    reactives[0] = *atoms[i];
    reactives[1] = *atoms[e];

    molecules.push_back(new Molecule(reactives, 2));

    if(i > e)//Prevents us from deleting the wrong class, since the indexing change when we delete an element
    {
        atoms.erase(atoms.begin() + i);
        atoms.erase(atoms.begin() + e);
    }
    else
    {
        atoms.erase(atoms.begin() + e);
        atoms.erase(atoms.begin() + i);
    }

}

void SimulAtomMain::checkReaction(int i, int e, bool posIsI)
{
    bool bigIsI = false;
    int big = 0;
    int small = 0;
    int iOx = atoms[i]->getOxyNumber();
    int eOx = atoms[e]->getOxyNumber();
    if(posIsI)
    {
        bigIsI = atoms[i]->getOxyNumber() > eOx * -1 ? true : false;
        big =  iOx > eOx * -1 ? iOx : eOx * -1;
        small =  iOx < eOx * -1 ? iOx : eOx * -1;
    }
    else
    {
        bigIsI = iOx * -1 > eOx  ? true : false;
        big =  iOx* -1 > eOx  ? iOx * -1 : eOx;
        small =  iOx * -1 < eOx ? iOx * -1 : eOx;
    }

    bool found = false;
    int u, o;
    for(u = 1; u < 9; u++)
    {
        if(!found)
            for(o = 1; o < 9; o++)
                if((big * u % small * o)== 0)
                {
                    createMolecule(i,
                                   bigIsI ?  u : big * u / small * o,
                                   e,
                                   bigIsI ?  big * u / small * o : o);
                    found = true;
                    break;
                }
    }

}
