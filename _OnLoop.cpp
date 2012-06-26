#include "_SimulAtomMain.h"



//Variables for the FPS limitor
int fpsFrames;
int fpsCurrentTime;
int fpsLastUpdateTime;
int fpsElapsedTime;

void SimulAtomMain::OnLoop() {

    if(gameState == GAME_SCREEN)
    {
        if(simulating)
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
                            checkReaction(i, e);
                            break;
                        }
                        if(atoms[e]->getOxyNumber() > 512 && atoms[i]->getOxyNumber() % 256 != 0) //If the first molecule has a positive oxydation number and the second one has a negative one
                        {
                            checkReaction(i, e);
                            break;
                        }
                    }
                }

        for(i = 0; i < molecules.size(); i++)
                    molecules[i]->move();


            //count2 = SDL_GetTicks();
            //printf("%d \n", count2 - count1);
        }

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

void SimulAtomMain::checkReaction(int i, int e)
{
    float dif = atoms[i]->getEn() - atoms[e]->getEn();
    if(dif < 0)
        dif *= -1;

    if(dif < 0.5)
        bNonPolarCovalent(i, e);
    else if(dif < 1.6)
        bPolarCovalent(i, e);
    else if(dif < 2.0)
    {
        printf("Need to know if atoms are metals or not");
    }
    else if(dif > 2.0)
        bIonic(i, e);

}

void SimulAtomMain::bNonPolarCovalent(int i, int e){

    int iOx = atoms[i]->getOxyNumber();
    int eOx = atoms[e]->getOxyNumber();

    if(iOx < 0)
        iOx *= -1;
    if(eOx < 0)
        eOx *= -1;
    if(iOx == eOx)
        createMolecule(i, 1, e, 1);

}


void SimulAtomMain::bPolarCovalent(int i, int e){

}

void SimulAtomMain::bIonic(int i, int e){

}
