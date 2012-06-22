#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <vector>

#include "CEvent.h"
#include "CSurface.h"
#include "Constants.h"
#include "Button.h"

#include "Atom.h"
#include "Molecule.h"

class SimulAtomMain : public CEvent {

    private:
        bool            Running;
        SDL_Surface*    screen;

        SDL_Surface*    background;
        SDL_Surface*    saLogo;

        SDL_Surface*    playIcon;
        SDL_Surface*    exitIcon;

        SDL_Surface*    atomIcon;
        SDL_Surface*    moleculeIcon;

        Button          menuButtons[NUM_MENU_BUTTONS];

        std::vector<Atom*>          atoms;
        std::vector<Molecule*>      molecules;

        int             gameState;

        void            setAtomDemo();
        bool            checkCollision(int xA, int yA, int xB, int yB);
        void            createMolecule(int i, int numI, int e, int numE);
        void            checkReaction(int positive, int negative, bool posIsI);
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

};

#endif
