#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CEvent.h"
#include "CSurface.h"
#include "Constants.h"
#include "Button.h"

class SimulAtomMain : public CEvent {

    private:
        bool            Running;
        SDL_Surface*    screen;

        SDL_Surface*    background;
        SDL_Surface*    saLogo;

        Button          menuButtons[2];
        int             gameState;
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

};

#endif
