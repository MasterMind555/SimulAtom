#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CEvent.h"
#include "CSurface.h"
#include "Constants.h"
#include "Button.h"
#include "Atom.h"

class SimulAtomMain : public CEvent {

    private:
        bool            Running;
        SDL_Surface*    screen;

        SDL_Surface*    background;
        SDL_Surface*    saLogo;

        SDL_Surface*    playIcon;
        SDL_Surface*    exitIcon;

        SDL_Surface*    atomIcon;

        Button          menuButtons[NUM_MENU_BUTTONS];
        Atom*           atoms[32];
        int             gameState;
        void            setAtomDemo();
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
