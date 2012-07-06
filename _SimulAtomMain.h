#ifndef _CAPP_H_
    #define _CAPP_H_

/*
    Main class of the program.

    THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE").
    THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.
    ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

    BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.
    TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
*/


#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "CEvent.h"
#include "CSurface.h"
#include "Constants.h"
#include "Button.h"
#include "Atom.h"

#include "Atom.h"
#include "Molecule.h"
#include <string>

class SimulAtomMain : public CEvent {

    private:
        bool            running;
        bool            simulating;

        int             selected;

        SDL_Surface*    screen;

        SDL_Surface*    background;
        SDL_Surface*    saLogo;

        SDL_Surface*    playIcon;
        SDL_Surface*    exitIcon;
        SDL_Surface*    elMenuIcon;

        SDL_Surface*    atomIcons[ATOMS_TYPE_AMOUNT];

        SDL_Surface*    atomIconTemplate;
        SDL_Surface*    moleculeIconTemplate;

        TTF_Font        *font;


        Button          menuButtons[NUM_MENU_BUTTONS];
        Button          elMenuButton;

        std::vector<Atom*>          atoms;
        std::vector<Molecule*>      molecules;

        int             gameState;

        void            setAtomDemo();
        bool            checkCollision(int xA, int yA, int xB, int yB, bool aMol, bool bMol);

        void            createMolecule(int i, int numI, int e, int numE);
        void            checkReaction(int positive, int negative);

        void            bNonPolarCovalent(int i, int e);
        void            bPolarCovalent(int i, int e);
        void            bIonic(int i, int e);

        bool            elMenuOpened;

        /*
            Switches of Simulation
        */

        bool            preciseCollision;


    public:
        SimulAtomMain();

        int OnExecute();

        bool OnInit();

        void Reset();

        void OnEvent(SDL_Event* Event);

        void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnLButtonDown(int mX, int mY);

        void OnRButtonDown(int mX, int mY);

};

#endif
