OUTNAME=SimulAtom
CC=g++
CC_OPTS=-c -pipe -Wall -Wno-switch -ggdb -g3 
CC_SDL=-I/usr/local/include/SDL -D_REENTRANT 
LN_SDL=`sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image

all: Compile

Compile: _SimulAtomMain.o Atom.o Button.o CEvent.o CSurface.o Molecule.o _OnCleanup.o _OnEvent.o _OnInit.o _OnLoop.o _OnRender.o 
	${CC} -o ${OUTNAME} _SimulAtomMain.o Atom.o Button.o CEvent.o CSurface.o Molecule.o _OnCleanup.o _OnEvent.o _OnInit.o _OnLoop.o _OnRender.o ${LN_SDL}

_SimulAtomMain.o: _SimulAtomMain.cpp _SimulAtomMain.h CEvent.h CSurface.h Constants.h Button.h
	${CC} ${CC_OPTS} _SimulAtomMain.cpp ${CC_SDL} -o _SimulAtomMain.o

Atom.o: Atom.cpp Atom.h
	${CC} ${CC_OPTS} Atom.cpp ${CC_SDL} -o Atom.o

Button.o: Button.cpp Button.h
	${CC} ${CC_OPTS} Button.cpp ${CC_SDL} -o Button.o

CEvent.o: CEvent.cpp CEvent.h
	${CC} ${CC_OPTS} CEvent.cpp ${CC_SDL} -o CEvent.o

CSurface.o: CSurface.cpp CSurface.h
	${CC} ${CC_OPTS} CSurface.cpp ${CC_SDL} -o CSurface.o

Molecule.o: Molecule.cpp Molecule.h
	${CC} ${CC_OPTS} Molecule.cpp ${CC_SDL} -o Molecule.o

_OnCleanup.o: _OnCleanup.cpp _SimulAtomMain.h
	${CC} ${CC_OPTS} _OnCleanup.cpp ${CC_SDL} -o _OnCleanup.o

_OnEvent.o: _OnEvent.cpp _SimulAtomMain.h
	${CC} ${CC_OPTS} _OnEvent.cpp ${CC_SDL} -o _OnEvent.o

_OnInit.o: _OnInit.cpp _SimulAtomMain.h
	${CC} ${CC_OPTS} _OnInit.cpp ${CC_SDL} -o _OnInit.o

_OnLoop.o: _OnLoop.cpp _SimulAtomMain.h
	${CC} ${CC_OPTS} _OnLoop.cpp ${CC_SDL} -o _OnLoop.o

_OnRender.o: _OnRender.cpp _SimulAtomMain.h
	${CC} ${CC_OPTS} _OnRender.cpp ${CC_SDL} -o _OnRender.o




