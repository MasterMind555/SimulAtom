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

    #include <vector>
    #include <string>
    #include <SDL.h>

    //The screen's dimensions
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;

    //The size of the 'SimulAtom' Logo
    const int SA_LOGO_WIDTH = 566;
    const int SA_LOGO_HEIGHT = 439;

    const int ATOM_ICON_WIDTH = 21;
    const int ATOM_ICON_HEIGHT = 21;

    const int MOLECULE_ICON_WIDTH = 43;
    const int MOLECULE_ICON_HEIGHT = 43;

    //How many buttons we have in the menu
    const int NUM_MENU_BUTTONS = 2;

    const int ATOMS_TYPE_AMOUNT = 18;

    const int MAX_FPS = 60;

    const int MAX_ATOMS = 256;
    const int MAX_MOLECULES = 128;

    const int ATOM_SPEED_LOSS = -.5;

    const SDL_Color textColor = { 255, 255, 255 };
    //The order of the buttons
    enum {
        EXIT_BUTTON = 0,
        PLAY_BUTTON
    };

    //The possible states of the game
    enum {
        MAIN_MENU = 0,
        GAME_SCREEN
    };

    //Oxydation numbers
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
        const char* symbol;
        int protons;
        int neutrons;
        int oxydationNumber;
        int valenceElectrons;
        float en;//Electronegativity
        bool metal;//TODO: use a enum here for the category
    };

    typedef AtomProp AtomTemplate;


    struct MoleculeProp {
        std::vector<AtomTemplate*> atoms;
    };
    typedef MoleculeProp MoleculeTemplate;


    //All the elements of the periodic table
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

    /*


        The Oxydation Numbers below might not be correct, could be a significant source of misbehaviors


    */
    const AtomTemplate THydrogen {
        "H",
        HYDROGEN,
        1,
        MINUS_ONE + PLUS_ONE,
        1,
        2.20,
        false
    };


    const AtomTemplate THelium {
        "He",
        HELIUM,
        2,
        ZERO,
        2,
        99, //Unknown, no reactions implying this anyways
        false
    };

    const AtomTemplate TLithium {
        "Li",
        LITHIUM,
        4,
        PLUS_ONE,
        1,
        0.98,
        true
    };

    const AtomTemplate TBeryllium {
        "Be",
        BERYLLIUM,
        5,
        PLUS_TWO,
        2,
        1.57,
        false
    };

    const AtomTemplate TBoron {
        "B",
        BORON,
        6,
        PLUS_THREE,
        3,
        2.04,
        false
    };

    const AtomTemplate TCarbon {
        "C",
        CARBON,
        6,
        PLUS_FOUR + MINUS_TWO + MINUS_FOUR,
        2,
        2.55,
        false
    };

    const AtomTemplate TNitrogen {
        "N",
        NITROGEN,
        7,
        PLUS_FIVE + MINUS_THREE + PLUS_ONE + PLUS_TWO + PLUS_THREE + PLUS_FOUR,
        2,
        3.04,
        false
    };

    const AtomTemplate TOxygen {
        "O",
        OXYGEN,
        8,
        MINUS_TWO + PLUS_TWO + MINUS_ONE,//Not sure if correct or the engine requires that at this state
        6,
        3.44,
        false
    };

    const AtomTemplate TFluorine {
        "F",
        FLUORINE,
        10,
        MINUS_ONE,
        7,
        3.98,
        false
    };

    const AtomTemplate TNeon {
        "Ne",
        NEON,
        10,
        ZERO,
        8,
        99, //Unknown, no reactions implying this anyways
        false
    };

    const AtomTemplate TSodium {
        "Na",
        SODIUM,
        10,
        PLUS_ONE,
        1,
        0.93,
        true
    };

    const AtomTemplate TMagnesium {
        "Mg",
        MAGNESIUM,
        12,
        PLUS_TWO,
        2,
        1.31,
        false
    };

    const AtomTemplate TAluminum {
        "Al",
		ALUMINUM,
		14,
		PLUS_THREE,
		3,
		1.61,
		false
	};

    const AtomTemplate TSilicon {
        "Si",
		SILICON,
		14,
		PLUS_FOUR + MINUS_FOUR,
		4,
		1.90,
		false
	};

	const AtomTemplate TPhosphorus {
	    "P",
		PHOSPHORUS,
		16,
		PLUS_FIVE + PLUS_THREE + MINUS_THREE,
		5,
		2.19,
		false
	};

	const AtomTemplate TSulfur {
	    "S",
		SULFUR,
		16,
		PLUS_SIX + PLUS_FOUR + MINUS_TWO + PLUS_TWO,
		6,
		2.58,
		false
	};

    const AtomTemplate TChlorine {
        "Cl",
		CHLORINE,
        18,
        MINUS_ONE + PLUS_ONE + PLUS_THREE + PLUS_FOUR + PLUS_FIVE + PLUS_SIX + PLUS_SEVEN,
        7,
        3.16,
		false
	};

    const AtomTemplate TAtoms[ATOMS_TYPE_AMOUNT] = {
        THydrogen,//Nothing
        THydrogen,
        THelium,
        TLithium,
        TBeryllium,
        TBoron,
        TCarbon,
        TNitrogen,
        TOxygen,
        TFluorine,
        TNeon,
        TSodium,
        TMagnesium,
        TAluminum,
        TSilicon,
        TPhosphorus,
        TSulfur,
        TChlorine
    };

    const MoleculeTemplate TDihydrogen{

    };



#endif // CONSTANTS_H_INCLUDED
