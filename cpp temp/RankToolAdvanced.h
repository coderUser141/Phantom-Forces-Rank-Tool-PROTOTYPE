#pragma once
#include "Resource.h"



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  FUNCTION DECLARATIONS
//
//
//

//how many bools are there? too many

//gets weapon data, ands sets rankReturn, nameReturn, categoryReturn to the gun rank, name, and category, respectfully
inline void weaponDataGetSetter(std::string weapon);


inline long weaponCost(std::string weapon, long initial);

//creates menus
void WinMenu(HWND);
//changes according to state of minimizeWindow (1 = minimize, 0 = hide, -1 = normal)
void windowDisplay(HWND);
//hides unneeded windows
void hideWindows(bool, bool, bool, bool, bool, bool, bool);
//opens/saves files
//void file(HWND, bool);
//draws
//void draw(HWND);


//REGISTER FUNCTIONS

namespace _rankUnlocks {

    //registers second window class
    void registerDialogClass(HINSTANCE);
    //displays second window class
    void displayRankUnlocks(HWND);
    //creates second window's menus
    void RUMenu(HWND);
    //displays the lists of gun unlocks 
    void rankUnlocksList(HWND, std::string[32], std::string[32], std::string[32], char, int, int [] );

    //void hideWindows(bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);

}

namespace _changelog {

    //registers third window class
    void registerChangelogClass(HINSTANCE);
    //displays third window class
    void displayChangelog(HWND);
    //create third window's menu
    void CLMenu(HWND);
}

namespace _farm {

    //registers fourth window class
    void registerFarmingClass(HINSTANCE);
    //displays fourth window class
    void displayFarm(HWND);

}

namespace _extra {

    //displays rank to cred summation window
    void registerRtCClass(HINSTANCE);
    //displays extra window
    void displayExtra(HWND);
    //calculates
    void calculateExtra(LPCWSTR);

}

namespace _weaponBuy {

    //registers fifth window class
    void registerWeaponClass(HINSTANCE);
    //displays fifth window class
    void displayWeaponCost(HWND);
    //testing menu
    void weaponMenu(HWND);

}

//unused
namespace _debug {

    //displays debug window
    void displayDebug(HWND);
    //registers debug window
    void registerDebugClass(HINSTANCE);
    //debug menus
    void debug(std::wstring, int, long, bool);

}

//multiwindow functions

namespace _multiwindow {

    //hides windows on multiple windows
    bool hideWindows(bool, bool, bool, bool, bool, bool);

}

//unused
namespace _changelog {

    // secondary window hiding functions
    void hideWindows(bool, bool, bool, bool, bool, bool, bool, bool);

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CLASSES
//
//
//

//changelog position class
typedef struct _Cl {

    int CBSWM;
    int CTSWM;
    _Cl(int);

} changelog;

_Cl::_Cl(int antiposition) {

    CBSWM = antiposition * 120 + 70;
    CTSWM = antiposition * 120 + 50;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  HANDLER DECLARATIONS
//
//
//


// Forward declarations of functions included in this code module:

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);

//windows
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

namespace _rankUnlocks {

    LRESULT CALLBACK    rankUnlocksProcedure(HWND, UINT, WPARAM, LPARAM);

}

//unused
namespace _changelog {

    LRESULT CALLBACK    olderChangelogProcedure(HWND, UINT, WPARAM, LPARAM);

}

//unused
namespace _debug {

    LRESULT CALLBACK    debugProcedure(HWND, UINT, WPARAM, LPARAM);

}

namespace _extra {

    LRESULT CALLBACK    extraProcedure(HWND, UINT, WPARAM, LPARAM);

}

namespace _weaponBuy {

    LRESULT CALLBACK    weaponProcedure(HWND, UINT, WPARAM, LPARAM);

}

namespace _farm {

    LRESULT CALLBACK    farmProcedure(HWND, UINT, WPARAM, LPARAM);

}


//dialogs

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Attribution(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    VERSION_100(HWND, UINT, WPARAM, LPARAM);

//handlers
namespace _handle {

    namespace _subWindows { //subwindows

        //calculating windows MUST be global! They are tranferred through the display procedures (invoked by the main window) through to the actual window procedure
        HWND RUWND, CWND, FWND, WBWND, debug; //2nd [_hRUWND], 3rd [_hCWND], 4th [_hFWND], 5th [_hWBWND], 6th (debug) window handles
        HWND extra;

    }

    namespace _subWindowMenu { //subwindow menus

        //main window menus MUST be global! They are used by the window classes
        HMENU WCM, RUM, CLM; //weaponCost, rankUnlock, changelog

    }

    namespace _mainMenu {

        HMENU M; //main window menu

    }

    //NOTE: static and button control handlers can be local, but not edit controls; they are passed through for calculations

    namespace _farm { //farm window

        //4th window handlers
        HWND E1; //team 1
        HWND E2; //team 2
        HWND E3; //team 3

    }

    namespace _weaponBuy {

        //fifth window handlers
        HWND E1; //inital rank
        HWND E2; //target gun
        HWND S3; //output
        HWND B; //button

    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // main windows handler declarations
    //
    namespace _m {
        //NOTE: are global handlers to allow to hide using the hideWindows() function

        //rankToCred definitions
        HWND ERTC3; //edit control for ranktocred
        HWND SRTC1; //static control 1 for ranktocred
        HWND SRTC2; //static control 2 for ranktocred (output)
        HWND BRTC; //button control for ranktocred (calc)

        //rankToXP definitions
        HWND BRTX1; //edit control 1 for ranktoxp (initial rank)
        HWND SRTX1; // static control 1 for ranktoxp (initial rank)
        HWND ERTX2; //edit control 2 for ranktoxp (target rank)
        HWND SRTX2; // static control 2 for ranktoxp (target rank)
        HWND ERTX3; //edit control 3 for ranktoxp (leftovers)
        HWND SRTX3; // static control 3 for ranktoxp (leftovers)
        HWND SRTX4; //static control for ranktoxp (output)
        HWND BRTX; //button control for ranktoxp (calc)

        //XPToRank definitions
        HWND SXTR1; //static control for xptorank
        HWND EXTR; //edit control for xptorank
        HWND BXTR; //button control for xptorank (calc)
        HWND SXTR2; //static control for xptorank (output) 

        //credToRank definitions
        HWND SCTR1; //static control for credtorank
        HWND ECTR; //edit control for credtorank
        HWND BCTR; //button control for credtorank
        HWND SCTR2; //static control for credtorank (output)

        HWND MBU; //universal button control to minimize windows (experimental)
        HWND CV0100_1; //unused?
        HWND CV0100_2; //unused?
        HWND CV0110_1; //_Cl window static control for version 0.1.1.0; title
        HWND CV0110_2; //_Cl window static control for version 0.1.1.0; body
        HWND CV0120_1; //_Cl window static control for version 0.1.2.0; title
        HWND CV0120_2; //_Cl window static control for version 0.1.2.0; body
        HWND CV0121_1; //_Cl window static control for version 0.1.2.1; title
        HWND CV0121_2; //_Cl window static control for version 0.1.2.1; body
        HWND CV0200_1; //_Cl window static control for version 0.2.0.0; title
        HWND CV0200_2; //_Cl window static control for version 0.2.0.0; body
        HWND CV0210_1; //version 0.2.1.0; title
        HWND CV0210_2; //version 0.2.1.0 body
        HWND OC; //third window opener

    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // _Cl window handler declarations
    //

    namespace _changelog {

        HWND V0100S; //version 0.1.0.0 changelog
        HWND V0110S; //version 0.1.1.0 changelog

    }

    namespace _debug {

        HWND edit;

    }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  MISCELLANEOUS
//
//
//

namespace misc {

    std::string str; //string convert
    char* cstr; //char array convert 
    int minimizeWindow = -1;//1 minimizes, 0 hides, -1 normalizes
    int attributionBoxErrorCatch = -1; //attribution error catch (global)

}
