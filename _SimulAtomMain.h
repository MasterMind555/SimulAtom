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

        SDL_Surface*    playIcon;
        SDL_Surface*    exitIcon;

        Button          menuButtons[NUM_MENU_BUTTONS];
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

        void OnLButtonDown(int mX, int mY);

};

#endif
