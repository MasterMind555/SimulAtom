#include "CApp.h"

CApp::CApp() {
    screen = NULL;
    Running = true;
}



int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}
