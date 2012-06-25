#include "_SimulAtomMain.h"

void SimulAtomMain::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

void SimulAtomMain::OnExit() {
    running = false;
}
