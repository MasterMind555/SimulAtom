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

        for(i = 0; i < molecules.size(); i++)
                molecules[i]->move();

        for(i = 0; i < atoms.size(); i++)
        {
            for(e = 0; e < atoms.size(); e++)
                if(e != i)
                {
                    if(checkCollision(atoms[i]->getPosX(), atoms[i]->getPosY(), atoms[e]->getPosX(), atoms[e]->getPosY(), false, false))
                    {
                        atoms[i]->setVelX(atoms[i]->getVelX() * ATOM_SPEED_LOSS);
                        atoms[i]->setVelY(atoms[i]->getVelY() * ATOM_SPEED_LOSS);
                        atoms[e]->setVelX(atoms[e]->getVelX() * ATOM_SPEED_LOSS);
                        atoms[e]->setVelY(atoms[e]->getVelY() * ATOM_SPEED_LOSS);
                        checkReaction(i, e);
                        break;
                    }
                }
            for(e = 0; e < molecules.size(); e++)
                    if(checkCollision(atoms[i]->getPosX(), atoms[i]->getPosY(), molecules[e]->getPosX(), molecules[e]->getPosY(), false, true))
                    {
                        atoms[i]->setVelX(atoms[i]->getVelX() * ATOM_SPEED_LOSS);
                        atoms[i]->setVelY(atoms[i]->getVelY() * ATOM_SPEED_LOSS);
                        molecules[e]->setVelX(molecules[e]->getVelX() * ATOM_SPEED_LOSS);
                        molecules[e]->setVelY(molecules[e]->getVelY() * ATOM_SPEED_LOSS);
                        break;
                    }

        }


            //count2 = SDL_GetTicks();
            //printf("%d \n", count2 - count1);
        }


    }
    fpsFrames++;
    fpsLastUpdateTime = fpsCurrentTime;
    fpsCurrentTime = SDL_GetTicks();
    fpsElapsedTime = fpsCurrentTime - fpsLastUpdateTime;

    int waitTime = (int)((1000/MAX_FPS) - fpsElapsedTime);

    if(waitTime > 0)
        SDL_Delay(waitTime);

}

bool SimulAtomMain::checkCollision(int xA, int yA, int xB, int yB, bool aMol, bool bMol ){

    //TODO: Optimize this
    if(!aMol && !bMol)
    {
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
    }
    else if(aMol && !bMol)
    {
        if( yA + MOLECULE_ICON_HEIGHT <= yB )
        {
            return false;
        }

        if( yA >= yB + ATOM_ICON_HEIGHT )
        {
            return false;
        }

        if( xA + MOLECULE_ICON_WIDTH <= xB )
        {
            return false;
        }

        if( xA >= xB + ATOM_ICON_WIDTH )
        {
            return false;
        }
    }
    else if(!aMol && bMol)
    {
        if( yA + ATOM_ICON_HEIGHT <= yB )
        {
            return false;
        }

        if( yA >= yB + MOLECULE_ICON_HEIGHT )
        {
            return false;
        }

        if( xA + ATOM_ICON_WIDTH <= xB )
        {
            return false;
        }

        if( xA >= xB + MOLECULE_ICON_WIDTH )
        {
            return false;
        }

    }
    else
    {
        if( yA + MOLECULE_ICON_HEIGHT <= yB )
        {
            return false;
        }

        if( yA >= yB + MOLECULE_ICON_HEIGHT )
        {
            return false;
        }

        if( xA + MOLECULE_ICON_WIDTH <= xB )
        {
            return false;
        }

        if( xA >= xB + MOLECULE_ICON_WIDTH )
        {
            return false;
        }
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

    if(dif < 0.5 && dif >= 0)
        bNonPolarCovalent(i, e);
    else if(dif < 1.6 && dif >= 0.5)
        bPolarCovalent(i, e);
    else if(dif >= 1.6 && dif < 2.0)
    {
        if(atoms[e]->getMetal() || atoms[e]->getMetal())
            bIonic(i, e);
        else
            bPolarCovalent(i, e);
    }
    else if(dif >= 2.0)
        bIonic(i, e);

}

void SimulAtomMain::bNonPolarCovalent(int i, int e){

    int iOx = atoms[i]->getOxyNumber();
    int eOx = atoms[e]->getOxyNumber();

    if((iOx % 256 >= 128 && eOx % 256 >= 128) ||
       (iOx % 128 >= 64 && eOx % 128 >= 64) ||
       (iOx % 64 >= 32 && eOx % 64 >= 32) ||
       (iOx % 32 >= 16 && eOx % 32 >= 16))
        createMolecule(i, 1, e, 1);


}


void SimulAtomMain::bPolarCovalent(int i, int e){
    bNonPolarCovalent(i, e);
}

void SimulAtomMain::bIonic(int i, int e){


    if((atoms[i]->getMetal() && atoms[e]->getMetal()) || (!atoms[i]->getMetal() && !atoms[e]->getMetal()))//If both are metal or none are metal
        return;


    int iOx = atoms[i]->getOxyNumber();
    int eOx = atoms[e]->getOxyNumber();

    if(iOx % 256 >= 32 && (eOx % 65536 >= 8192 || eOx % 4096 >= 512))//If iOx has a negative value between -3 and -1 and eOx has a positive value between 5 and 7 or 1 and 3
    {

        if(iOx % 256 >= 128 && eOx % 65536 >= 32768)// -1 and +7
            createMolecule(i, 1, e, 1);
        else if(iOx % 128 >= 64 && eOx % 32768 >= 16384)// -2 and +6
            createMolecule(i, 1, e, 1);
        else if(iOx % 64 >= 32 && eOx % 16384 >= 8192)// -3 and +5
            createMolecule(i, 1, e, 1);
        else if(iOx % 256 >= 128 && eOx % 1024 >= 512)// -1 and +1
            createMolecule(i, 1, e, 1);
        else if(iOx % 128 >= 64 && eOx % 2048 >= 1024)// -2 and +2
            createMolecule(i, 1, e, 1);
        else if(iOx % 64 >= 32 && eOx % 4096 >= 2048)// -3 and +3
            createMolecule(i, 1, e, 1);

    }
    else if(eOx % 256 >= 32 && (iOx % 65536 >= 8192 || iOx % 4096 >= 512))
    {
        if(eOx % 256 >= 128 && iOx % 65536 >= 32768)// -1 and +7
            createMolecule(i, 1, e, 1);
        else if(eOx % 128 >= 64 && iOx % 32768 >= 16384)// -2 and +6
            createMolecule(i, 1, e, 1);
        else if(eOx % 64 >= 32 && iOx % 16384 >= 8192)// -3 and +5
            createMolecule(i, 1, e, 1);
        else if(eOx % 256 >= 128 && iOx % 1024 >= 512)// -1 and +1
            createMolecule(i, 1, e, 1);
        else if(eOx % 128 >= 64 && iOx % 2048 >= 1024)// -2 and +2
            createMolecule(i, 1, e, 1);
        else if(eOx % 64 >= 32 && iOx % 4096 >= 2048)// -3 and +3
            createMolecule(i, 1, e, 1);
    }
}
