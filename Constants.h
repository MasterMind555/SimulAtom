#ifndef CONSTANTS_H_INCLUDED
    #define CONSTANTS_H_INCLUDED


/*
    Constants header, holds all the constants in the game to be able to modify them easily

    THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE").
    THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.
    ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

    BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.
    TO THE EXTENT THIS LICENSE MAY BE CONSIDERED TO BE A CONTRACT, THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
*/


    //The screen's dimensions

    #include <vector>


    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;

    //The size of the 'SimulAtom' Logo
    const int SA_LOGO_WIDTH = 566;
    const int SA_LOGO_HEIGHT = 439;


    //How many buttons we have in the menu

    const int ATOM_ICON_WIDTH = 21;
    const int ATOM_ICON_HEIGHT = 21;

    const int MOLECULE_ICON_WIDTH = 20;
    const int MOLECULE_ICON_HEIGHT = 20;

    const int NUM_MENU_BUTTONS = 2;

    const int MAX_FPS = 60;

    const int MAX_ATOMS = 256;
    const int MAX_MOLECULES = 128;

    //The order of the buttons
    enum {
        EXIT_BUTTON = 0,
        PLAY_BUTTON
    };



    //The possible states of the game
    enum{
        MAIN_MENU = 0,
        GAME_SCREEN
    };

    //All the elements of the periodic table

    enum {
        MINUS_EIGHT = 1,
        MINUS_SEVEN = 2,
        MINUS_SIX = 4,
        MINUS_FIVE = 8,
        MINUS_FOUR = 16,
        MINUS_THREE = 32,
        MINUS_TWO = 64,
        MINUS_ONE = 128,
        ZERO = 256,
        PLUS_ONE = 512,
        PLUS_TWO = 1024,
        PLUS_THREE = 2048,
        PLUS_FOUR = 4096,
        PLUS_FIVE = 8192,
        PLUS_SIX = 16384,
        PLUS_SEVEN = 32768,
        PLUS_EIGHT = 65536
    };


    struct AtomProp {
        int protons;
        int neutrons;
        int oxydationNumber;
        int valenceElectrons;

    };

    typedef AtomProp AtomTemplate;


    struct MoleculeProp {
        std::vector<AtomTemplate*> atoms;
    };

    typedef MoleculeProp MoleculeTemplate;


    enum {
	HYDROGEN = 1,
	HELIUM,
	LITHIUM,
	BERYLLIUM,
	BORON,
	CARBON,
	NITROGEN,
	OXYGEN,
	FLUORINE,
	NEON,
	SODIUM,
	MAGNESIUM,
	ALUMINUM,
	SILICON,
	PHOSPHORUS,
	SULFUR,
	CHLORINE,
	ARGON,
	POTASSIUM,
	CALCIUM,
	SCANDIUM,
	TITANIUM,
	VANADIUM,
	CHROMIUM,
	MANGANESE,
	IRON,
	COBALT,
	NICKEL,
	COPPER,
	ZINC,
	GALLIUM,
	GERMANIUM,
	ARSENIC,
	SELENIUM,
	BROMINE,
	KRYPTON,
	RUBIDIUM,
	STRONTIUM,
	YTTRIUM,
	ZIRCONIUM,
	NIOBIUM,
	MOLYBDENUM,
	TECHNETIUM,
	RUTHENIUM,
	RHODIUM,
	PALLADIUM,
	SILVER,
	CADMIUM,
	INDIUM,
	TIN,
	ANTIMONY,
	TELLURIUM,
	IODINE,
	XENON,
	CESIUM,
	BARIUM,
	LANTHANUM,
	CERIUM,
	PRASEODYMIUM,
	NEODYMIUM,
	PROMETHIUM,
	SAMARIUM,
	EUROPIUM,
	GADOLINIUM,
	TERBIUM,
	DYSPROSIUM,
	HOLMIUM,
	ERBIUM,
	THULIUM,
	YTTERBIUM,
	LUTETIUM,
	HAFNIUM,
	TANTALUM,
	TUNGSTEN,
	RHENIUM,
	OSMIUM,
	IRIDIUM,
	PLATINUM,
	GOLD,
	MERCURY,
	THALLIUM,
	LEAD,
	BISMUTH,
	POLONIUM,
	ASTATINE,
	RADON,
	FRANCIUM,
	RADIUM,
	ACTINIUM,
	THORIUM,
	PROTACTINIUM,
	URANIUM,
	NEPTUNIUM,
	PLUTONIUM,
	AMERICIUM,
	CURIUM,
	BERKELIUM,
	CALIFORNIUM,
	EINSTEINIUM,
	FERMIUM,
	MENDELEVIUM,
	NOBELIUM,
	LAWRENCIUM,
	RUTHERFORDIUM,
	DUBNIUM,
	SEABORGIUM,
	BOHRIUM,
	HASSIUM,
	MEITNERIUM,
	DARMSTADTIUM,
	ROENTGENIUM,
	UNUNBIUM,
	UNUNTRIUM,
	UNUNQUADIUM,
	UNUNPENTIUM,
	UNUNHEXIUM,
	UNUNSEPTIUM,
	UNUNOCTIUM
};

    const AtomTemplate THydrogen {
        HYDROGEN,
        1,
        MINUS_ONE + PLUS_ONE,
        1
    };


    const AtomTemplate THelium {
        HELIUM,
        2,
        ZERO,
        2
    };

    const AtomTemplate TLithium {
        LITHIUM,
        4,
        PLUS_ONE,
        1
    };

    const AtomTemplate TBeryllium {
        BERYLLIUM,
        5,
        PLUS_TWO,
        2
    };

    const AtomTemplate TBoron {
        BORON,
        6,
        PLUS_THREE,
        3
    };

    const AtomTemplate TCarbon {
        CARBON,
        6,
        PLUS_FOUR,
        2
    };

    const AtomTemplate TNitrogen{
        NITROGEN,
        7,
        PLUS_FIVE + MINUS_THREE,
        2
    };



    const MoleculeTemplate TDihydrogen{

    };


#endif // CONSTANTS_H_INCLUDED
