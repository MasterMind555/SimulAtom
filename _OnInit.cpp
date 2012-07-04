#include "_SimulAtomMain.h"
#include "CSurface.h"
#include "Constants.h"

bool SimulAtomMain::OnInit() {

    //Redirects stdout and stderr output to the debug console
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if( TTF_Init() == -1 ) {
		return false;
	}

    SDL_WM_SetCaption( "SimulAtom", NULL );

    if((screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((saLogo = CSurface::onLoadPng("img/logo.png")) == NULL) {
        printf("Can't find SimulAtom Logo");
        return false;
    }

    if((background = CSurface::onLoadPng("img/background.png")) == NULL) {
        printf("Can't find background");
        return false;
    }

    if((playIcon = CSurface::onLoadPng("img/play.png")) == NULL) {
        printf("Can't find play icon");
        return false;
    }

    if((exitIcon = CSurface::onLoadPng("img/exit.png")) == NULL) {
        printf("Can't find exit icon");
        return false;
    }

    int i;
    for(i = 0; i < ATOMS_TYPE_AMOUNT; i++)
    {
        if((atomIcons[i] = CSurface::onLoadPng("img/atom.png")) == NULL) {
            printf("Can't find atom icon");
            return false;
        }
    }
    if((moleculeIcon = CSurface::onLoadPng("img/h2.png")) == NULL) {
        printf("Can't find atom icon");
        return false;
    }
    if((elMenuIcon = CSurface::onLoadPng("img/menuslide.png")) == NULL) {
        printf("Can't find element menu icon");
        return false;
    }

    if((font = TTF_OpenFont("LUCON.ttf", 12 )) == NULL) {
        printf("Can't find the font");
        return false;
    }

    menuButtons[PLAY_BUTTON].setIcon(&playIcon);
    menuButtons[EXIT_BUTTON].setIcon(&exitIcon);
    elMenuButton.setIcon(&elMenuIcon);

    if(menuButtons[EXIT_BUTTON].checkIfValid() == false)
        printf("Problem while initializing the %dth button", EXIT_BUTTON);
    if(menuButtons[PLAY_BUTTON].checkIfValid() == false)
        printf("Problem while initializing the %dth button", PLAY_BUTTON);
    if(elMenuButton.checkIfValid() == false)
        printf("Problem while initializing the open menu button");

    int w, h;
    for(i = 1; i < ATOMS_TYPE_AMOUNT; i++)
    {

        if(TTF_SizeText(font, TAtoms[i].symbol, &w, &h)){
            printf("%s", TTF_GetError());
        }

        CSurface::onDraw(atomIcons[i],
                         TTF_RenderText_Solid(font, TAtoms[i].symbol, textColor),
                         (ATOM_ICON_WIDTH / 2) - (w / 2),
                         (ATOM_ICON_HEIGHT / 2) - (h / 2),
                         NULL);

    }
    return true;
}
