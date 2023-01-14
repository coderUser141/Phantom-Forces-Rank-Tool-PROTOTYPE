// RankToolAdvanced.cpp : Defines the entry point for the application.

//include necessary(?) libraries
#include <iostream>
#include <string>
#include <locale>

//include preset headers
#include "framework.h"
#include "RankToolAdvanced.h"

#include "_RANKTOOLFUNCTIONS/_RANKTOOLFUNCTIONS.h"

#ifdef WIN32_LEAN_AND_MEAN
//include necessary commdlg header
#define _COMMDLG
#include <commdlg.h>
#endif

#include <wchar.h>
#include <cwchar>
#include <wctype.h>
#include <cwctype>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          
//   _____ _____ _____ _____ _____ _____ _____    _____ _____ _____ _____ _____ 
//  |  _  | __  |     |   __| __  |  _  |     |  |   __|_   _|  _  | __  |_   _|
//  |   __|    -|  |  |  |  |    -|     | | | |  |__   | | | |     |    -| | |  
//  |__|  |__|__|_____|_____|__|__|__|__|_|_|_|  |_____| |_| |__|__|__|__| |_|  
//
//
//

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR szTitle[MAX_LOADSTRING];                  // The title bar texts
TCHAR szWindowClass2[MAX_LOADSTRING];            // the main window class name
const TCHAR RUClass[] = (L"RankUnlock");
//const TCHAR CLClass[] = ("Changelog");
const TCHAR FClass[] = (L"Farm");
const TCHAR EClass[] = (L"Extra");
const TCHAR WBClass[] = (L"WeaponCost");
//const TCHAR debugClass[] = ("Debug");

HWND hMain; //main window handler

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_RANKTOOLADVANCED, szWindowClass2, MAX_LOADSTRING);
    MyRegisterClass(hInstance); //Generates an instance of a window class

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }


    HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RANKTOOLADVANCED));

    MSG msg;



    // Main message loop:
    BOOL bRet;

    while ((bRet = GetMessageW(&msg, NULL , 0, 0)) != 0)
    { 

        if (bRet == -1){
        // handle the error and possibly exit
            break;
        }else {
            if (!TranslateAccelerator(hMain, hAccel, &msg)) //for accelerator tables
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

    }

    return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)//Class properties of the window
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc; //assigns a window to the instance of the class
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance; //creates an instance
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RANKTOOLADVANCED));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); //defines a type of cursor (arrow, help, cross, etc.)
    //wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); 
    wcex.hbrBackground  = CreateSolidBrush(RGB(0,0,0));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_RANKTOOLADVANCED);
    wcex.lpszClassName  = szWindowClass2;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{//initializes instance of window class (invocation)
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowEx(WS_EX_LTRREADING, szWindowClass2, (L"Phantom Forces Rank Tool"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 900, 600, nullptr, _handle::_mainMenu::M, hInstance, nullptr);


   _rankUnlocks::registerDialogClass(hInstance); //registers second window
   //_changelog::registerChangelogClass(hInstance); //registers third window
   _farm::registerFarmingClass(hInstance); //registers fourth window
   _weaponBuy::registerWeaponClass(hInstance); //registers fifth window class
   _extra::registerRtCClass(hInstance);
   //_debug::registerDebugClass(hInstance);//registers debug class

   hMain = hWnd;
   if (!hWnd)
   {
      return false;
   }


   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return true;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    std::string units, out;
    std::string creditUnits = " Credits";
    std::string rankUnits = "Rank ";
    std::string XPUnits = " XP";
    HBRUSH hbrBkgnd = 0;
    

    switch (message)
    {

        case WM_COMMAND:
        {


            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {

                case IDM_ABOUT:
                {
                
                    //standard about
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
                
                }


                case FILE_MENU_DESTROY:
                {

                    //quits
                    DestroyWindow(hWnd);
                    break;

                }


                case FILE_MENU_NEW:
                {

                    MessageBox(hWnd, (L"your mom lol"), (L"get rekt xd"), MB_OK);
                    break;

                }


                case FILE_MENU_ABOUT:
                {   

                    //custom about
                    DialogBox(hInst, MAKEINTRESOURCE(ATTRIBUTION), hWnd, Attribution);
                    if(misc::attributionBoxErrorCatch == -1)MessageBox(hWnd, (L"Made by Kyviro (Can be reached at Kyviro#5659)"), (L"Credits"), MB_OK);
                    break;

                }


                case RANK_CRED:
                {

                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    _extra::displayExtra(hWnd);

                    /*
            
                    RANK TO CRED GUI GENERATION
            
                    */
                    //shows ranktocred calc gui
                    ShowWindow(_handle::_m::MBU, 0);
                    _handle::_m::SRTC1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Enter rank here: "), WS_VISIBLE | WS_CHILD | SS_CENTER, 400, 100, 100, 50, hWnd, NULL, NULL, NULL);
                    _handle::_m::BRTC = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Calculate"), WS_VISIBLE | WS_CHILD, 400, 190, 100, 25, hWnd, (HMENU)RANK_CRED_CALC, NULL, NULL);
                    _handle::_m::ERTC3 = CreateWindowExA(NULL, ("edit"), ("..."), WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_CENTER, 400, 155, 100, 25, hWnd, NULL, NULL, NULL);
                    _handle::_m::MBU = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Minimize"), WS_CHILD | WS_VISIBLE, 400, 400, 100, 50, hWnd, (HMENU)MINIMIZE, NULL, NULL);
                    //rid leftover windows
                    ::hideWindows(false, true, true, true, true, false, false);
                    break;

                }


                case RANK_CRED_CALC:
                {

                    /*
            
                    RANK TO CRED CALCULATION, GENERATION AND OUTPUT
            
                    */


                    ShowWindow(_handle::_m::SRTC2, 0);//clear output to prevent layering
                    //shows the calculation
                    //input

                    TCHAR rankToCred[50];
                    _handle::_m::SRTC2 = CreateWindowEx(WS_EX_LTRREADING, (L"Static"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 300, 300, 300, 100, hWnd, NULL, NULL, NULL);
                    GetWindowText(_handle::_m::ERTC3, rankToCred, 50);

                    wchar_t* pEnd;

                    //calculation
                    unsigned long long int rankToCredOut = RANKTOOLFUNCTIONS::rankCreditEarnings(wcstoull(rankToCred, &pEnd, 10));
                    unsigned long long int summatedCredits = 0;
                    for (int i = 0; i < wcstoull(rankToCred, &pEnd, 10); i++) {

                        summatedCredits += RANKTOOLFUNCTIONS::rankCreditEarnings(wcstoull(rankToCred, &pEnd, 10));

                    }


                    if (rankToCredOut == -1) {

                        SetWindowText(_handle::_m::SRTC2, (L"Error"));

                    } else {

                        //convert from unsigned long long int to wstring
                        std::wstring stemp = std::to_wstring(rankToCredOut);
                        std::wstring stemp2 = std::to_wstring(summatedCredits);

                        std::wstring suffix = L" Credits";
                        stemp += suffix;

                        //convert wstring to LPCWSTR
                        LPCWSTR result = stemp.c_str();
                        LPCWSTR result2 = stemp2.c_str();

                        //give text
                        SetWindowText(_handle::_m::SRTC2, result);
                        _extra::calculateExtra(result2);

                    }

                    break;

                }


                case RANK_XP:
                {

                    /*
            
                    RANK TO XP GUI GENERATION
            
                    */
                    ShowWindow(_handle::_m::MBU, 0);
                    //shows ranktoxp gui
                    _handle::_m::SRTX1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Enter initial rank here: "), WS_VISIBLE | WS_CHILD | SS_CENTER, 200, 100, 100, 50, hWnd, NULL, NULL, NULL);
                    _handle::_m::BRTX1 = CreateWindowExA(NULL, ("edit"), ("..."), WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_CENTER, 200, 155, 100, 25, hWnd, NULL, NULL, NULL);

                    _handle::_m::SRTX2 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Enter target rank here: "), WS_VISIBLE | WS_CHILD | SS_CENTER, 400, 100, 100, 50, hWnd, NULL, NULL, NULL);
                    _handle::_m::ERTX2 = CreateWindowExA(NULL, ("edit"), ("..."), WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_CENTER, 400, 155, 100, 25, hWnd, NULL, NULL, NULL);

                    _handle::_m::SRTX3 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Enter rank's earnings here: "), WS_VISIBLE | WS_CHILD | SS_CENTER, 600, 100, 100, 50, hWnd, NULL, NULL, NULL);
                    _handle::_m::ERTX3 = CreateWindowExA(NULL, ("edit"), ("..."), WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_CENTER, 600, 155, 100, 25, hWnd, NULL, NULL, NULL);

                    _handle::_m::BRTX = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Calculate"), WS_VISIBLE | WS_CHILD, 400, 190, 100, 25, hWnd, (HMENU)RANK_XP_CALC, NULL, NULL);
                    _handle::_m::MBU = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Minimize"), WS_CHILD | WS_VISIBLE, 400, 400, 100, 50, hWnd, (HMENU)MINIMIZE, NULL, NULL);
                    //rid leftover windows

                    ::hideWindows(true, true, false, true, true, false, false);
                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    break;

                }


                case RANK_XP_CALC:
                {

                    /*
            
                    RANK TO XP CALCULATION, GENERATION AND OUTPUT
            
                    */

                    ShowWindow(_handle::_m::SRTX4, 0); //clears window
                    //shows the calculation
                    _handle::_m::SRTX4 = CreateWindowEx(WS_EX_LTRREADING,(L"Static"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 300, 300, 300, 100, hWnd, NULL, NULL, NULL);

                    //initial get
                    TCHAR rankToXPInitial[50];
                    GetWindowText(_handle::_m::BRTX1, rankToXPInitial, 50);

                    //target get
                    TCHAR rankToXPTarget[50];
                    GetWindowText(_handle::_m::ERTX2, rankToXPTarget, 50);

                    //leftovers get
                    TCHAR rankToXPLeftovers[50];
                    GetWindowText(_handle::_m::ERTX3, rankToXPLeftovers, 50);

                    /**
                    //Calculation
                    unsigned long long rankToXPOut = RANKTOOLFUNCTIONS::rankXPRequirement(RANKTOOLFUNCTIONS::charToUnsignedLongLong(rankToXPInitial), RANKTOOLFUNCTIONS::charToUnsignedLongLong(rankToXPTarget), RANKTOOLFUNCTIONS::charToUnsignedLongLong(rankToXPLeftovers)); //calculates the input (ranktoxp)

                    if (rankToXPOut == -1) {

                        SetWindowTextW(_handle::_m::SRTX4, ("Error"));

                    }else {

                        //convert long to string

                        units = XPUnits;

                        misc::str = std::to_string(rankToXPOut) + units;

                        //convert string to char array
                        misc::cstr = new char[misc::str.size() + 1];
                        misc::str.copy(misc::cstr, misc::str.size() + 1);
                        misc::cstr[misc::str.size()] = '\0';

                        //display
                        SetWindowTextA(_handle::_m::SRTX4, misc::cstr);
                        memset(misc::cstr, 0, sizeof(misc::cstr));

                    }
*/

                    wchar_t* pEnd;

                    //calculation
                    unsigned long long int rankToXPOut = RANKTOOLFUNCTIONS::rankXPRequirement(wcstoull(rankToXPInitial, &pEnd, 10), wcstoull(rankToXPTarget, &pEnd, 10), wcstoull(rankToXPLeftovers, &pEnd, 10));


                    if (rankToXPOut == -1) {

                        SetWindowText(_handle::_m::SRTX4, (L"Error"));

                    } else {

                        //convert from unsigned long long int to wstring
                        std::wstring stemp = std::to_wstring(rankToXPOut);

                        std::wstring suffix = L" XP";
                        stemp += suffix;
                        //convert wstring to LPCWSTR
                        LPCWSTR result = stemp.c_str();

                        //give text
                        SetWindowText(_handle::_m::SRTX4, result);

                    }

                    break;

                }


                case XP_RANK:
                {

                    /*
            
                    XP TO RANK GUI GENERATION
            
                    */
                    ShowWindow(_handle::_m::MBU, 0);
                    _handle::_m::SXTR1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Enter XP amount here (must be less than 5 000 050 000 000): "), WS_VISIBLE | WS_CHILD | SS_CENTER, 300, 100, 260, 50, hWnd, NULL, NULL, NULL);
                    _handle::_m::BXTR = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Calculate"), WS_VISIBLE | WS_CHILD, 400, 190, 100, 25, hWnd, (HMENU)XP_RANK_CALC, NULL, NULL);
                    _handle::_m::EXTR = CreateWindowExA(NULL, ("edit"), ("..."), WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_CENTER, 400, 155, 100, 25, hWnd, NULL, NULL, NULL);
                    _handle::_m::MBU = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Minimize"), WS_CHILD | WS_VISIBLE, 400, 400, 100, 50, hWnd, (HMENU)MINIMIZE, NULL, NULL);

                    //rid leftover windows
                    ::hideWindows(true, true, true, false, true, false, false);
                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    break;

                }


                case XP_RANK_CALC:
                {

                    /*
            
                    XP TO RANK CALCULATION, GENERATION AND OUTPUT
            
                    */
                    ShowWindow(_handle::_m::SXTR2, 0);//clears window
                    //shows the calculation
                    TCHAR XPToRank[50];
                    _handle::_m::SXTR2 = CreateWindowEx(WS_EX_LTRREADING, (L"Static"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 300, 300, 300, 100, hWnd, NULL, NULL, NULL);
                    GetWindowText(_handle::_m::EXTR, XPToRank, 50);


                    wchar_t* pEnd;

                    //calculation
                    unsigned long long int XPToRankOut = RANKTOOLFUNCTIONS::XPRankRequirement(wcstoull(XPToRank, &pEnd, 10));


                    if (XPToRankOut == -1) {

                        SetWindowText(_handle::_m::SXTR2, (L"Error"));

                    } else {

                        //convert from unsigned long long int to wstring
                        std::wstring stemp = std::to_wstring(XPToRankOut);


                        std::wstring suffix = L"Rank ";
                        stemp = suffix + stemp;

                        //convert wstring to LPCWSTR
                        LPCWSTR result = stemp.c_str();

                        //give text
                        SetWindowText(_handle::_m::SXTR2, result);

                    }

                    break;

                }


                case CRED_RANK :
                {

                    /*
            
                    CREDIT TO RANK GUI GENERATION
            
                    */
                    ShowWindow(_handle::_m::MBU, 0);
                    _handle::_m::SCTR1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Enter credits amount here (must be a multiple of 5 and greater than 200): "), WS_VISIBLE | WS_CHILD | SS_CENTER, 300, 100, 300, 50, hWnd, NULL, NULL, NULL);
                    _handle::_m::BCTR = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Calculate"), WS_VISIBLE | WS_CHILD, 400, 190, 100, 25, hWnd, (HMENU)CRED_RANK_CALC, NULL, NULL);
                    _handle::_m::ECTR = CreateWindowExA(NULL, ("edit"), ("..."), WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_CENTER, 400, 155, 100, 25, hWnd, NULL, NULL, NULL);
                    _handle::_m::MBU = CreateWindowExA(WS_EX_LTRREADING, ("Button"), ("Minimize"), WS_CHILD | WS_VISIBLE, 400, 400, 100, 50, hWnd, (HMENU)MINIMIZE, NULL, NULL);

                    //rid leftover windows
                    ::hideWindows(true, false, true, true, true, false, false);
                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    break;
 
                }


                case CRED_RANK_CALC:
                {

                    /*
            
                    CREDIT TO RANK CALCULATION, GENERATION AND OUTPUT

                    */

                    ShowWindow(_handle::_m::SCTR2, 0);//clear window
                    TCHAR credToRank[50];
                    _handle::_m::SCTR2 = CreateWindowEx(WS_EX_LTRREADING, (L"Static"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 300, 300, 300, 100, hWnd, NULL, NULL, NULL);
                    GetWindowText(_handle::_m::ECTR, credToRank, 50);

                    wchar_t* pEnd;

                    //calculation
                    unsigned long long int credToRankOut = RANKTOOLFUNCTIONS::creditRankEarnings(wcstoull(credToRank, &pEnd, 10));


                    if (credToRankOut == -1) {

                        SetWindowText(_handle::_m::SCTR2, (L"Error"));

                    } else {

                        //convert from unsigned long long int to wstring
                        std::wstring stemp = std::to_wstring(credToRankOut);

                        std::wstring suffix = L"Rank ";
                        stemp = suffix + stemp;


                        //convert wstring to LPCWSTR
                        LPCWSTR result = stemp.c_str();

                        //give text
                        SetWindowText(_handle::_m::SCTR2, result);

                    }

                    break;
                
                }


                case CLEAR: //clears all visible windows
                {
                    
                    if (misc::minimizeWindow == -1) {
                        ::hideWindows(true, true, true, true, true, true, true);
                    }
                    break;

                }


                case TUTORIAL:
                {
                    

                    MessageBox(hWnd, (L"\n\
                        About Box: ALT + / \n\
                        Quit: CTRL + ALT + DEL \n\
                        Attribution: ALT + A \n\
                        Rank to Credits: ALT + R \n\
                        Rank to Credits Calculation: F1 \n\
                        Rank to XP: SHIFT + ALT + R \n\
                        Rank to XP Calculation: F2 \n\
                        XP to Rank: ALT + X \n\
                        XP to Rank Calculation: F3 \n\
                        Credits to Rank: ALT + C \n\
                        Credits to Rank Calculation: F4 \n\
                        Minimize: ALT + M \n\
                        Clear all windows: CTRL + C \n\
                        Clear all Minimized windows: CTRL + ALT + C \n\
                        Tutorial: ALT + T \n\
                        Changelog: CTRL + SHIFT + C \n\
                        Debug window: CTRL + SHIFT + D \n\
                        Rank Unlock window: CTRL + SHIFT + R \n\
                        Old Changelog window: CTRL + SHIFT + O \n\
                        Farm window: CTRL + SHIFT + F \n\
                        Weapon Cost: CTRL + SHIFT + W \n\
                        Open File: CTRL + O \n\
                        Save File: CTRL + S \n\
                        "), (L"Keybinds"), MB_OK | MB_ICONINFORMATION);
                    break;

                }


                case CLEAR2: //clears minimized windows
                {

                    if (misc::minimizeWindow == 1) {
                        ::hideWindows(true, true, true, true, true, true, true);
                    }
                    break;

                }


                case MINIMIZE: //minimizes output windows
                {

                    if (misc::minimizeWindow == -1) {

                        misc::minimizeWindow = 1;
                        windowDisplay(_handle::_m::SCTR2);
                        windowDisplay(_handle::_m::SRTX4);
                        windowDisplay(_handle::_m::SRTC2);
                        windowDisplay(_handle::_m::SXTR2);
                        //_hSRTX4, _hSRTC2, _hSXTR2

                    }else if (misc::minimizeWindow == 1) {

                        misc::minimizeWindow = -1;
                        windowDisplay(_handle::_m::SCTR2);
                        windowDisplay(_handle::_m::SRTX4);
                        windowDisplay(_handle::_m::SRTC2);
                        windowDisplay(_handle::_m::SXTR2);

                    }
                    break;

                }


                case CHANGELOG: //_Cl gui generation
                {

                    //_Cl version100(4);
                    //_Cl version110(4);
                    _Cl version120(3);
                    _Cl version121(2);
                    _Cl version200(1);
                    _Cl version210(0);

                    //past version 1.0.0
                    //_hCV100_1 = CreateWindowExW(WS_EX_LTRREADING, ("Static"), ("Version 1.0.0"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, version100.CTSWM, 100, 20, hWnd, NULL, NULL, NULL);
                    //_hCV100_2 = CreateWindowExW(WS_EX_LTRREADING, ("Static"), ("Application made, added rank, xp & credit calculation, and calculation & help menus added."), WS_VISIBLE | WS_CHILD | SS_NOPREFIX, 50, version100.CBSWM, 600, 100, hWnd, NULL, NULL, NULL);

                    //_handle::_m::CV0110_1 = CreateWindowExW(WS_EX_LTRREADING, ("Static"), ("Version 0.1.1.0"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, version110.CTSWM, 100, 20, hWnd, NULL, NULL, NULL);
                    //_handle::_m::CV0110_2 = CreateWindowExW(WS_EX_LTRREADING, ("Static"), ("Added logo, debug menu, & welcome text. Changed int to unsigned long long, in order to add more space."), WS_VISIBLE | WS_CHILD | SS_NOPREFIX, 50, version110.CBSWM, 600, 100, hWnd, NULL, NULL, NULL);
           
                    _handle::_m::CV0120_1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Version 0.1.2.0"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, version120.CTSWM, 100, 20, hWnd, NULL, NULL, NULL);
                    _handle::_m::CV0120_2 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Added minimization, changelog, more (debug) clearing options."), WS_VISIBLE | WS_CHILD, 50, version120.CBSWM, 600, 100, hWnd, NULL, NULL, NULL);

                    _handle::_m::CV0121_1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Version 0.1.2.1"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, version121.CTSWM, 100, 20, hWnd, NULL, NULL, NULL);
                    _handle::_m::CV0121_2 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Fixed several bugs with the minimize button & 'permanant' windows. Added joke menu for jokes."), WS_VISIBLE | WS_CHILD | SS_NOPREFIX, 50, version121.CBSWM, 600, 100, hWnd, NULL, NULL, NULL);
            
                    _handle::_m::CV0200_1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Version 0.2.0.0"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, version200.CTSWM, 100, 20, hWnd, NULL, NULL, NULL);
                    _handle::_m::CV0200_2 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Added new popout windows (farming, weapon unlock, weapon cost and old changelog). Added functionality to the farm window whilst weapon unlock and cost windows are just windows :/. New old changelog means that version 1.0.0 changelog update is going there. Goodbye 1.0.0!"), WS_VISIBLE | WS_CHILD | SS_NOPREFIX, 50, version200.CBSWM, 600, 100, hWnd, NULL, NULL, NULL);

                    _handle::_m::CV0210_1 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Version 0.2.1.0"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, version210.CTSWM, 100, 20, hWnd, NULL, NULL, NULL);
                    _handle::_m::CV0210_2 = CreateWindowExA(WS_EX_LTRREADING, ("Static"), ("Added colour! Makes the application look less basic and adds more character."), WS_VISIBLE | WS_CHILD, 50, version210.CBSWM, 600, 100, hWnd, NULL, NULL, NULL);

                    //rid leftover windows

                    ::hideWindows(true, true, true, true, false, true, true);
                    break;

                }

                //unused
                case DEBUG:
                {

                    //_debug::displayDebug(hWnd);
                    break;

                }


                case RANK_UNLOCK:
                {

                    _rankUnlocks::displayRankUnlocks(hWnd);
                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    break;

                }

                //unused
                case OLD_CHANGELOG:
                {

                    //_changelog::displayChangelog(hWnd);
                    break;
                
                }
                
                
                case FARM: 
                {
                
                    _farm::displayFarm(hWnd);
                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    break;
                
                }
                
                
                case CLEARF:
                {
                
                    _multiwindow::hideWindows(true, NULL, NULL, NULL, NULL, NULL);
                    break;
                
                }
                
                //unused
                case CLEARC:
                {
                
                    //_multiwindow::hideWindows(NULL, true, NULL, NULL, NULL);
                    break;
                
                }
                
                
                case CLEARRU:
                {
                
                    _multiwindow::hideWindows(NULL, NULL, true ,NULL, NULL, NULL);
                    break;
                
                }
                
                //unused
                case CLEARDE:
                {

                    //_multiwindow::hideWindows(NULL, NULL, NULL, NULL, true);
                    break;

                }


                case CLEARWB:
                {

                    _multiwindow::hideWindows(NULL, NULL, NULL, true, NULL, NULL);
                    break;

                }

                
                case CLEAR3:
                {
                
                    _multiwindow::hideWindows(true, true, true, true, true, true);
                    break;
                
                }
                
                
                case WEAPON_COST:
                {
                
                    _weaponBuy::displayWeaponCost(hWnd);
                    _multiwindow::hideWindows(NULL, NULL, NULL, NULL, NULL, true);
                    break;
                
                }
                
                /*
                case OPEN_FILE:
                {

                    file(hWnd, true);
                    break;

                }


                case SAVE_FILE:
                {

                    file(hWnd, false);
                    break;

                }

                break;*/

            }

            break;
        
        }

        
        case WM_CREATE:
        {

            HWND welcome = CreateWindowA(("Static"), ("Welcome to rank tool!"), WS_VISIBLE | WS_CHILD, 375, 10, 150, 18, hWnd, NULL, NULL, NULL);
            //loadImages();
            WinMenu(hWnd);
            break;
        
        }
        
        
        case WM_PAINT:
        {
        
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            break;
            
        }


        case WM_DESTROY:
        {

            PostQuitMessage(0);
            break;
        
        }
        
        
        case WM_MOVE:
        {
        
            //SetFocus(hWnd);
            SetActiveWindow(hWnd);
            break;
        
        }
        
        
        case WM_CTLCOLORSTATIC:
        {

            HDC hdcStatic = (HDC)wParam;
            SetTextColor(hdcStatic, RGB(204, 153, 255));
            SetBkColor(hdcStatic, RGB(0, 0, 0));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }


        case WM_CTLCOLOREDIT:
        {

            HDC hdcEdit = (HDC)wParam;
            SetTextColor(hdcEdit, RGB(0,0,0));
            SetBkColor(hdcEdit, RGB(243, 230, 255));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }

        case WM_CTLCOLORBTN:
        {

            HDC hdcButton = (HDC)wParam;
            SetTextColor(hdcButton, RGB(0, 0, 0));
            SetBkColor(hdcButton, RGB(255, 255, 255));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }


        default:
        {
        
            return DefWindowProc(hWnd, message, wParam, lParam);
        
        }

    }

    return 0;

}

//creates menu
void WinMenu(HWND hWnd) {

    
    HMENU _hFM, _hSM1, _hSM2, _hAM, _hDM, _hCM, _hJM, _hCSM, _hFAM; //main menu instances (main [_hM], file [_hFM], submenu1 [_hSM1], submenu2 [_hSM2], about [_hAM], debug [_hDM], clear [_hCM], joke [_hJM], clear submenu [_hCSM])

    _handle::_mainMenu::M = CreateMenu();
    _hFM = CreateMenu();
    _hSM1 = CreateMenu();
    _hSM2 = CreateMenu();

    //_hFAM = CreateMenu();

    _hAM = CreateMenu();

    _hDM = CreateMenu();
    _hCM = CreateMenu();

    _hCSM = CreateMenu();

    _hJM = CreateMenu();

    AppendMenuA(_handle::_mainMenu::M, MF_POPUP, (UINT_PTR)_hFM,("Calculations")); //popups up submenu of _hFM

        AppendMenuA(_hFM, MF_POPUP, (UINT_PTR)_hSM1,("Points...")); //option that popups submenu of _hSM1
                //XP Calculations
            AppendMenuA(_hSM1, MF_STRING, RANK_XP,("Rank -> XP")); //displays sets of buttons that
            AppendMenuA(_hSM1, MF_STRING, XP_RANK,("XP -> Rank"));


        AppendMenuA(_hFM, MF_POPUP, (UINT_PTR)_hSM2,("Credits...")); //option that popups submenu of _hSM1
            //Credit Calculations
            AppendMenuA(_hSM2, MF_STRING, RANK_CRED,("Rank -> Cred"));
            AppendMenuA(_hSM2, MF_STRING, CRED_RANK,("Cred -> Rank"));

        AppendMenuA(_hFM, MF_SEPARATOR, NULL, NULL);
        AppendMenuA(_hFM, MF_STRING, FARM,("Farm"));
        AppendMenuA(_hFM, MF_SEPARATOR, NULL, NULL);
        AppendMenuA(_hFM, MF_STRING, WEAPON_COST,("Weapon Cost"));
        AppendMenuA(_hFM, MF_STRING, RANK_UNLOCK,("Rank Unlocks"));
        /*
    AppendMenu(_handle::_mainMenu::M, MF_POPUP, (UINT_PTR)_hFAM,("File"));
        AppendMenu(_hFAM, MF_STRING, OPEN_FILE,("Open..."));
        AppendMenu(_hFAM, MF_STRING, SAVE_FILE,("Save..."));
        */
    AppendMenuA(_handle::_mainMenu::M, MF_POPUP, (UINT_PTR)_hAM,("Help")); //popups up submenu of _hFM
        AppendMenuA(_hAM, MF_STRING, IDM_ABOUT,("About"));
        AppendMenuA(_hAM, MF_STRING, FILE_MENU_ABOUT,("Attribution"));
        AppendMenuA(_hAM, MF_STRING, TUTORIAL,("How to use"));
        AppendMenuA(_hAM, MF_SEPARATOR, NULL, NULL); // separator
        AppendMenuA(_hAM, MF_STRING, FILE_MENU_DESTROY,("Exit")); // option 

    AppendMenuA(_handle::_mainMenu::M, MF_POPUP, (UINT_PTR)_hDM,("Debug"));
        AppendMenuA(_hDM, MF_POPUP, (UINT_PTR)_hCM,("Clear..."));
            AppendMenuA(_hCM, MF_STRING, CLEAR,("Clear all windows"));
            AppendMenuA(_hCM, MF_STRING, CLEAR2,("Clear all minimized windows"));
            AppendMenuA(_hCM, MF_SEPARATOR, NULL, NULL);
            AppendMenuA(_hCM, MF_POPUP, (UINT_PTR)_hCSM,("Clear secondary windows..."));
                AppendMenuA(_hCSM, MF_STRING, CLEARF,("Clear farming window"));
                //AppendMenu(_hCSM, MF_STRING, CLEARC,("Clear old changelog window"));
                AppendMenuA(_hCSM, MF_STRING, CLEARRU,("Clear rank unlock window"));
                AppendMenuA(_hCSM, MF_STRING, CLEARWB,("Clear weapon cost window"));
                //AppendMenu(_hCSM, MF_STRING, CLEARDE,("Clear debug window"));
                AppendMenuA(_hCSM, MF_STRING, CLEAR3,("Clear all"));
        //AppendMenu(_hDM, MF_SEPARATOR, NULL, NULL);
        //AppendMenu(_hDM, MF_STRING, CHANGELOG,("Changelog"));
        //AppendMenu(_hDM, MF_SEPARATOR, NULL, NULL);
        //AppendMenu(_hDM, MF_STRING, DEBUG,("Debug Window..."));

    AppendMenuA(_handle::_mainMenu::M, MF_POPUP, (UINT_PTR)_hJM,("Funny"));
        AppendMenuA(_hJM, MF_STRING, FILE_MENU_NEW,("lmao"));

    SetMenu(hWnd, _handle::_mainMenu::M);

    DrawMenuBar(hWnd);
    
}

//minimize window function
void windowDisplay(HWND handler) {
    
    if (misc::minimizeWindow == 1) {

        ShowWindow(handler, SW_MINIMIZE); //minimizes
    
    }else if (misc::minimizeWindow == 0) {
    
        ShowWindow(handler, SW_HIDE); //hides
    
    }else if (misc::minimizeWindow == -1) {
    
        ShowWindow(handler, SW_SHOWNORMAL); //normal
    }

}

//hides main window's child windows
void hideWindows(bool RANKTOCRED, bool CREDTORANK, bool RANKTOXP, bool XPTORANK, bool _Cl, bool button, bool outputExceptions) {
    
    if (RANKTOXP) {
    
        //ranktoxp windows
        ShowWindow(_handle::_m::SRTX1, 0);
        ShowWindow(_handle::_m::SRTX2, 0);
        ShowWindow(_handle::_m::SRTX3, 0);
        if (misc::minimizeWindow != 1)ShowWindow(_handle::_m::SRTX4, 0);
        ShowWindow(_handle::_m::BRTX1, 0);
        ShowWindow(_handle::_m::ERTX2, 0);
        ShowWindow(_handle::_m::ERTX3, 0);
        ShowWindow(_handle::_m::BRTX, 0);
    
    }
    
    if (RANKTOCRED) {
       
        //ranktocred windows
        ShowWindow(_handle::_m::SRTC1, 0);
        ShowWindow(_handle::_m::ERTC3, 0);
        ShowWindow(_handle::_m::BRTC, 0);
        if (misc::minimizeWindow != 1)ShowWindow(_handle::_m::SRTC2, 0);
    
    }
    
    if (XPTORANK) {
    
        //xptorank windows
        ShowWindow(_handle::_m::SXTR1, 0);
        if (misc::minimizeWindow != 1)ShowWindow(_handle::_m::SXTR2, 0);
        ShowWindow(_handle::_m::BXTR, 0);
        ShowWindow(_handle::_m::EXTR, 0);
    
    }
    
    if (CREDTORANK) {

        //credtorank windows
        ShowWindow(_handle::_m::SCTR1, 0);
        if (misc::minimizeWindow != 1)ShowWindow(_handle::_m::SCTR2, 0);
        ShowWindow(_handle::_m::BCTR, 0);
        ShowWindow(_handle::_m::ECTR, 0);

    }

    if (_Cl) {

        //ShowWindow(_hCV100_1, 0);
        //ShowWindow(_hCV100_2, 0);
        ShowWindow(_handle::_m::CV0110_1, 0);
        ShowWindow(_handle::_m::CV0110_2, 0);
        ShowWindow(_handle::_m::CV0120_1, 0);
        ShowWindow(_handle::_m::CV0120_2, 0);
        ShowWindow(_handle::_m::CV0121_1, 0);
        ShowWindow(_handle::_m::CV0121_2, 0);
        ShowWindow(_handle::_m::CV0200_1, 0);
        ShowWindow(_handle::_m::CV0200_2, 0);
        ShowWindow(_handle::_m::CV0210_1, 0);
        ShowWindow(_handle::_m::CV0210_2, 0);
        ShowWindow(_handle::_m::OC, 0);

    }

    if (button)ShowWindow(_handle::_m::MBU, 0);

    if (outputExceptions) {

        ShowWindow(_handle::_m::SXTR2, 0);
        ShowWindow(_handle::_m::SCTR2, 0);
        ShowWindow(_handle::_m::SRTC2, 0);
        ShowWindow(_handle::_m::SRTX4, 0);

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RANKUNLOCK WINDOW CLASS
//
//
//

namespace _rankUnlocks {

    const int arrSize = 32;

    HWND BattleRiflesName[sizeof(categories::BattleRifles) / sizeof(std::string) + 1], BattleRiflesRank[sizeof(categories::BattleRifles) / sizeof(std::string) + 1], BattleRiflesCategory[sizeof(categories::BattleRifles) / sizeof(std::string) + 1];
    HWND DesignatedMarksmanRiflesName[sizeof(categories::DesignatedMarksmanRifles) / sizeof(std::string) + 1], DesignatedMarksmanRiflesRank[sizeof(categories::DesignatedMarksmanRifles) / sizeof(std::string) + 1], DesignatedMarksmanRiflesCategory[sizeof(categories::DesignatedMarksmanRifles) / sizeof(std::string) + 1];
    HWND SniperRiflesName[sizeof(categories::SniperRifles) / sizeof(std::string) + 1], SniperRiflesRank[sizeof(categories::SniperRifles) / sizeof(std::string) + 1], SniperRiflesCategory[sizeof(categories::SniperRifles) / sizeof(std::string) + 1];
    HWND CarbinesName[sizeof(categories::Carbines) / sizeof(std::string) + 1], CarbinesRank[sizeof(categories::Carbines) / sizeof(std::string) + 1], CarbinesCategory[sizeof(categories::Carbines) / sizeof(std::string) + 1];
    HWND PersonalDefenseWeaponsName[sizeof(categories::PersonalDefenseWeapons) / sizeof(std::string) + 1], PersonalDefenseWeaponsRank[sizeof(categories::PersonalDefenseWeapons) / sizeof(std::string) + 1], PersonalDefenseWeaponsCategory[sizeof(categories::PersonalDefenseWeapons) / sizeof(std::string) + 1];
    HWND LightMachineGunsName[sizeof(categories::LightMachineGuns) / sizeof(std::string) + 1], LightMachineGunsRank[sizeof(categories::LightMachineGuns) / sizeof(std::string) + 1], LightMachineGunsCategory[sizeof(categories::LightMachineGuns) / sizeof(std::string) + 1];
    HWND AssaultRiflesName[sizeof(categories::AssaultRifles) / sizeof(std::string) + 1], AssaultRiflesRank[sizeof(categories::AssaultRifles) / sizeof(std::string) + 1], AssaultRiflesCategory[sizeof(categories::AssaultRifles) / sizeof(std::string) + 1];
    HWND ShotgunsName[sizeof(categories::Shotguns) / sizeof(std::string) + 1], ShotgunsRank[sizeof(categories::Shotguns) / sizeof(std::string) + 1], ShotgunsCategory[sizeof(categories::Shotguns) / sizeof(std::string) + 1];

    HWND PistolsName[sizeof(categories::Pistols) / sizeof(std::string) + 1], PistolsRank[sizeof(categories::Pistols) / sizeof(std::string) + 1], PistolsCategory[sizeof(categories::Pistols) / sizeof(std::string) + 1];
    HWND MachinePistolsName[sizeof(categories::MachinePistols) / sizeof(std::string) + 1], MachinePistolsRank[sizeof(categories::MachinePistols) / sizeof(std::string) + 1], MachinePistolsCategory[sizeof(categories::MachinePistols) / sizeof(std::string) + 1];
    HWND RevolversName[sizeof(categories::Revolvers) / sizeof(std::string) + 1], RevolversRank[sizeof(categories::Revolvers) / sizeof(std::string) + 1], RevolversCategory[sizeof(categories::Revolvers) / sizeof(std::string) + 1];
    HWND OtherName[sizeof(categories::Other) / sizeof(std::string) + 1], OtherRank[sizeof(categories::Other) / sizeof(std::string) + 1], OtherCategory[sizeof(categories::Other) / sizeof(std::string) + 1];

    HWND RankedMeleesName[sizeof(categories::RankedMelees) / sizeof(std::string) + 1], RankedMeleesRank[sizeof(categories::RankedMelees) / sizeof(std::string) + 1], RankedMeleesCategory[sizeof(categories::RankedMelees) / sizeof(std::string) + 1];
    HWND UnrankedMeleesName[sizeof(categories::UnrankedMelees) / sizeof(std::string) + 1], UnrankedMeleesRank[sizeof(categories::UnrankedMelees) / sizeof(std::string) + 1], UnrankedMeleesCategory[sizeof(categories::UnrankedMelees) / sizeof(std::string) + 1];


    //registers window class
    void registerDialogClass(HINSTANCE hInst) {

        WNDCLASSW rankUnlocks = { };

        rankUnlocks.hbrBackground = CreateSolidBrush(RGB(0,0,0));
        rankUnlocks.hCursor = LoadCursor(NULL, IDC_ARROW);
        rankUnlocks.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_RANKTOOLADVANCED));
        rankUnlocks.hInstance = hInst;
        rankUnlocks.lpszClassName = RUClass;
        rankUnlocks.lpfnWndProc = rankUnlocksProcedure;

        RegisterClassW(&rankUnlocks);

    }

    int counter = 0;

    void rankUnlocksList(HWND hWnd, std::string rankArray[], std::string nameArray[], std::string categoryArray[], 
                         char control,
                         int sizeY, int sizeX[]){
        misc::nameReturn = ("");
        misc::rankReturn = ("");
        misc::categoryReturn = ("");
        HWND gunCategory[arrSize], gunName[arrSize], gunRank[arrSize];
        int posArray[32]; //Y-Position per item

        //clear all windows

        //AR
        for (unsigned int i = 0; i < std::size(categories::AssaultRifles); i++) {
            ShowWindow(AssaultRiflesName[i], 0);
            ShowWindow(AssaultRiflesRank[i], 0);
            ShowWindow(AssaultRiflesCategory[i], 0);
        }
        //BR
        for (unsigned int i = 0; i < std::size(categories::BattleRifles); i++) {
            ShowWindow(BattleRiflesName[i], 0);
            ShowWindow(BattleRiflesRank[i], 0);
            ShowWindow(BattleRiflesCategory[i], 0);
        }
        //DMR
        for (unsigned int i = 0; i < std::size(categories::DesignatedMarksmanRifles); i++) {
            ShowWindow(DesignatedMarksmanRiflesName[i], 0);
            ShowWindow(DesignatedMarksmanRiflesRank[i], 0);
            ShowWindow(DesignatedMarksmanRiflesCategory[i], 0);
        }
        //LMG
        for (unsigned int i = 0; i < std::size(categories::LightMachineGuns); i++) {
            ShowWindow(LightMachineGunsName[i], 0);
            ShowWindow(LightMachineGunsRank[i], 0);
            ShowWindow(LightMachineGunsCategory[i], 0);
        }
        //SHO
        for (unsigned int i = 0; i < std::size(categories::Shotguns); i++) {
            ShowWindow(ShotgunsName[i], 0);
            ShowWindow(ShotgunsRank[i], 0);
            ShowWindow(ShotgunsCategory[i], 0);
        }
        //SR
        for (unsigned int i = 0; i < std::size(categories::SniperRifles); i++) {
            ShowWindow(SniperRiflesName[i], 0);
            ShowWindow(SniperRiflesRank[i], 0);
            ShowWindow(SniperRiflesCategory[i], 0);
        }
        //PDW
        for (unsigned int i = 0; i < std::size(categories::PersonalDefenseWeapons); i++) {
            ShowWindow(PersonalDefenseWeaponsName[i], 0);
            ShowWindow(PersonalDefenseWeaponsRank[i], 0);
            ShowWindow(PersonalDefenseWeaponsCategory[i], 0);
        }
        //CAR
        for (unsigned int i = 0; i < std::size(categories::Carbines); i++) {
            ShowWindow(CarbinesName[i], 0);
            ShowWindow(CarbinesRank[i], 0);
            ShowWindow(CarbinesCategory[i], 0);
        }
        //PIS
        for (unsigned int i = 0; i < std::size(categories::Pistols); i++) {
            ShowWindow(PistolsName[i], 0);
            ShowWindow(PistolsRank[i], 0);
            ShowWindow(PistolsCategory[i], 0);
        }
        //MP
        for (unsigned int i = 0; i < std::size(categories::MachinePistols); i++) {
            ShowWindow(MachinePistolsName[i], 0);
            ShowWindow(MachinePistolsRank[i], 0);
            ShowWindow(MachinePistolsCategory[i], 0);
        }
        //REV
        for (unsigned int i = 0; i < std::size(categories::Revolvers); i++) {
            ShowWindow(RevolversName[i], 0);
            ShowWindow(RevolversRank[i], 0);
            ShowWindow(RevolversCategory[i], 0);
        }
        //OTH
        for (unsigned int i = 0; i < std::size(categories::Other); i++) {
            ShowWindow(OtherName[i], 0);
            ShowWindow(OtherRank[i], 0);
            ShowWindow(OtherCategory[i], 0);
        }
        //RM
        for (unsigned int i = 0; i < std::size(categories::RankedMelees); i++) {
            ShowWindow(RankedMeleesName[i], 0);
            ShowWindow(RankedMeleesRank[i], 0);
            ShowWindow(RankedMeleesCategory[i], 0);
        }
        //URM
        for (unsigned int i = 0; i < std::size(categories::UnrankedMelees); i++) {
            ShowWindow(UnrankedMeleesName[i], 0);
            ShowWindow(UnrankedMeleesRank[i], 0);
            ShowWindow(UnrankedMeleesCategory[i], 0);
        }

        switch (control) {
            case 'A': {//ARs
                for (unsigned int i = 0; i < std::size(categories::AssaultRifles); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = AssaultRiflesCategory[i];
                    gunRank[i] = AssaultRiflesRank[i];
                    gunName[i] = AssaultRiflesName[i];
                    weaponDataGetSetter(categories::AssaultRifles[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'B': {//BRs
                for (unsigned int i = 0; i < std::size(categories::BattleRifles); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = BattleRiflesCategory[i];
                    gunRank[i] = BattleRiflesRank[i];
                    gunName[i] = BattleRiflesName[i];
                    weaponDataGetSetter(categories::BattleRifles[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'C': {//Carbines
                for (unsigned int i = 0; i < std::size(categories::Carbines); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = CarbinesCategory[i];
                    gunRank[i] = CarbinesRank[i];
                    gunName[i] = CarbinesName[i];
                    weaponDataGetSetter(categories::Carbines[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'D': {//DMRs
                for (unsigned int i = 0; i < std::size(categories::DesignatedMarksmanRifles); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = DesignatedMarksmanRiflesCategory[i];
                    gunRank[i] = DesignatedMarksmanRiflesRank[i];
                    gunName[i] = DesignatedMarksmanRiflesName[i];
                    weaponDataGetSetter(categories::DesignatedMarksmanRifles[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'E': {//Sniper Rifles
                for (unsigned int i = 0; i < std::size(categories::SniperRifles); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = SniperRiflesCategory[i];
                    gunRank[i] = SniperRiflesRank[i];
                    gunName[i] = SniperRiflesName[i];
                    weaponDataGetSetter(categories::SniperRifles[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'F': {//urm
                for (unsigned int i = 0; i < std::size(categories::UnrankedMelees); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = UnrankedMeleesCategory[i];
                    gunRank[i] = UnrankedMeleesRank[i];
                    gunName[i] = UnrankedMeleesName[i];
                    weaponDataGetSetter(categories::UnrankedMelees[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'G': {//rm
                for (unsigned int i = 0; i < std::size(categories::RankedMelees); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = RankedMeleesCategory[i];
                    gunRank[i] = RankedMeleesRank[i];
                    gunName[i] = RankedMeleesName[i];
                    weaponDataGetSetter(categories::RankedMelees[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'L': {//LMGs
                for (unsigned int i = 0; i < std::size(categories::LightMachineGuns); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = LightMachineGunsCategory[i];
                    gunRank[i] = LightMachineGunsRank[i];
                    gunName[i] = LightMachineGunsName[i];
                    weaponDataGetSetter(categories::LightMachineGuns[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }
            
            case 'M': {//Machine Pistols
                for (unsigned int i = 0; i < std::size(categories::MachinePistols); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = MachinePistolsCategory[i];
                    gunRank[i] = MachinePistolsRank[i];
                    gunName[i] = MachinePistolsName[i];
                    weaponDataGetSetter(categories::MachinePistols[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'O': {//Other
                for (unsigned int i = 0; i < std::size(categories::Other); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = OtherCategory[i];
                    gunRank[i] = OtherRank[i];
                    gunName[i] = OtherName[i];
                    weaponDataGetSetter(categories::Other[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'P': {//pistols
                for (unsigned int i = 0; i < std::size(categories::Pistols); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = PistolsCategory[i];
                    gunRank[i] = PistolsRank[i];
                    gunName[i] = PistolsName[i];
                    weaponDataGetSetter(categories::Pistols[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'R': {//revolvers
                for (unsigned int i = 0; i < std::size(categories::Revolvers); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = RevolversCategory[i];
                    gunRank[i] = RevolversRank[i];
                    gunName[i] = RevolversName[i];
                    weaponDataGetSetter(categories::Revolvers[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'S': {//shotguns
                for (unsigned int i = 0; i < std::size(categories::Shotguns); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = ShotgunsCategory[i];
                    gunRank[i] = ShotgunsRank[i];
                    gunName[i] = ShotgunsName[i];
                    weaponDataGetSetter(categories::Shotguns[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            case 'W': {//PDWs
                for (unsigned int i = 0; i < std::size(categories::PersonalDefenseWeapons); i++) {
                    misc::nameReturn = ("");
                    misc::rankReturn = ("");
                    misc::categoryReturn = ("");
                    gunCategory[i] = NULL;
                    gunRank[i] = NULL;
                    gunName[i] = NULL;

                    gunCategory[i] = PersonalDefenseWeaponsCategory[i];
                    gunRank[i] = PersonalDefenseWeaponsRank[i];
                    gunName[i] = PersonalDefenseWeaponsName[i];
                    weaponDataGetSetter(categories::PersonalDefenseWeapons[i]);

                    memset(nameArray, 0, sizeof(nameArray));
                    memset(rankArray, 0, sizeof(rankArray));
                    memset(categoryArray, 0, sizeof(categoryArray));

                    nameArray[i] = misc::nameReturn; //name
                    rankArray[i] = ("Rank: ") + misc::rankReturn; //rank
                    categoryArray[i] = ("Category: ") + misc::categoryReturn; //category
                }
                break;
            }

            default: {
                for (unsigned int i = 0; i < arrSize; i++) {
                    gunCategory[i] = 0;
                    gunRank[i] = 0;
                    gunName[i] = 0;
                }
            }

        }

        for (unsigned int i = 0; i < std::size(gunCategory); i++) {

            posArray[i] = i * sizeY;

            gunCategory[i] = CreateWindowA(("Static"), categoryArray[i].c_str(), WS_VISIBLE | WS_CHILD, sizeX[4], posArray[i], sizeX[5], sizeY, hWnd, NULL, NULL, NULL);
            gunRank[i] = CreateWindowA(("Static"), rankArray[i].c_str(), WS_VISIBLE | WS_CHILD, sizeX[2], posArray[i], sizeX[3], sizeY, hWnd, NULL, NULL, NULL);
            gunName[i] = CreateWindowA(("Static"), nameArray[i].c_str(), WS_VISIBLE | WS_CHILD, sizeX[0], posArray[i], sizeX[1], sizeY, hWnd, NULL, NULL, NULL);

        }


    }

    //procedure for the window and messages (see if suitable SCBS -> DCBS conversion exists
    LRESULT CALLBACK rankUnlocksProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

        HBRUSH hbrBkgnd = 0;

        int posArray[32]; //Y-Position per item
        int size = 18; //Y-Size for all name, rank, category windows

        int namePos = 0; //X-Position for names
        int nameSize = 150; //X-Size for names

        int rankPos = 150; //X-Position for ranks
        int rankSize = 100; //X-Size for ranks

        int categoryPos = 250; //X-Position for category
        int categorySize = 350; //X-Size for category

        int sizeX[6] = { namePos, nameSize, rankPos, rankSize, categoryPos, categorySize };


        std::string rankStringArray[arrSize], nameStringArray[arrSize], categoryStringArray[arrSize]; //puts into 3 columns, for neatness

        //arrays to save lines

        switch (Msg) {

            case WM_COMMAND:
            {

                int wmId = LOWORD(wParam);
                // Parse the menu selections:
                switch (wmId)
                {


                    case AR:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'A', size, sizeX);
                        break;

                    }

                    
                    case PDW:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'W', size, sizeX);
                        break;

                    }


                    case CAR:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'C', size, sizeX);
                        break;

                    }
                    

                    case LMG:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'L', size, sizeX);
                        break;

                    }


                    case SR:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'E', size, sizeX);
                        break;

                    }


                    case DMR:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'D', size, sizeX);
                        break;

                    }


                    case BR:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'B', size, sizeX);
                        break;

                    }


                    case SHO:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'S', size, sizeX);
                        break;

                    }


                    case PIS:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'P', size, sizeX);
                        break;

                    }


                    case MPI:
                    {


                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'M', size, sizeX);
                        break;

                    }


                    case REV:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'R', size, sizeX);
                        break;

                    }


                    case OTH:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'O', size, sizeX);
                        break;

                    }


                    case RM:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'G', size, sizeX);
                        break;

                    }


                    case URM:
                    {

                        rankUnlocksList(hWnd, rankStringArray, nameStringArray, categoryStringArray, 'F', size, sizeX);
                        break;

                    }
                    
                    //////END OF WEAPON CASES

                    case EXIT:
                    {

                        ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
                        //DestroyWindow(hWnd);
                        break;

                    }

                    break;

                }
                break;

            }

            case WM_CREATE:
            {

                ShowWindow(hWnd, SW_SHOW); //reveals again
                _rankUnlocks::RUMenu(hWnd);
                break;

            }


            case WM_CLOSE:
            {

                //DestroyWindow(hWnd);
                ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
                break;

            }

            case WM_CTLCOLORSTATIC:
            {

                HDC hdcStatic = (HDC)wParam;
                SetTextColor(hdcStatic, RGB(255, 255, 255));
                SetBkColor(hdcStatic, RGB(0, 0, 0));

                if (hbrBkgnd == NULL)
                {
                    hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
                }

                return (INT_PTR)hbrBkgnd;
                break;

            }


            default:

                return DefWindowProcW(hWnd, Msg, wParam, lParam);

        }
    }

    //displays rank unlocks window
    void displayRankUnlocks(HWND hWnd) {

        _handle::_subWindows::RUWND = CreateWindow(RUClass, (L"Rank Unlocks"), WS_VISIBLE | WS_OVERLAPPEDWINDOW, 30, 30, 600, 558, hWnd, _handle::_subWindowMenu::RUM, NULL, NULL);

    }



        //menu
    void RUMenu(HWND hWnd) {

            HMENU _hRUSM1, _hRUSM2; //second window menu instances( main [_hRUM], submenu1 [_hRUSM1], submenu2 [hRUSM2])

            _handle::_subWindowMenu::RUM = CreateMenu();
            _hRUSM1 = CreateMenu();
            _hRUSM2 = CreateMenu();

            AppendMenuA(_handle::_subWindowMenu::RUM, MF_POPUP, (UINT_PTR)_hRUSM1, ("Classes"));
            AppendMenuA(_hRUSM1, MF_STRING, AR, ("Assault Rifles"));
            AppendMenuA(_hRUSM1, MF_STRING, PDW, ("Personal Defense Weapons"));
            AppendMenuA(_hRUSM1, MF_STRING, LMG, ("Light Machine Guns"));
            AppendMenuA(_hRUSM1, MF_STRING, SR, ("Sniper Rifles"));
            AppendMenuA(_hRUSM1, MF_STRING, DMR, ("Designated Marksman Rifles"));
            AppendMenuA(_hRUSM1, MF_STRING, CAR, ("Carbines"));
            AppendMenuA(_hRUSM1, MF_STRING, BR, ("Battle Rifles"));
            AppendMenuA(_hRUSM1, MF_STRING, SHO, ("Shotguns"));
            AppendMenuA(_hRUSM1, MF_SEPARATOR, NULL, NULL);
            AppendMenuA(_hRUSM1, MF_STRING, PIS, ("Pistols"));
            AppendMenuA(_hRUSM1, MF_STRING, MPI, ("Machine Pistols"));
            AppendMenuA(_hRUSM1, MF_STRING, REV, ("Revolvers"));
            AppendMenuA(_hRUSM1, MF_STRING, OTH, ("Other Secondaries"));
            AppendMenuA(_hRUSM1, MF_SEPARATOR, NULL, NULL);
            AppendMenuA(_hRUSM1, MF_STRING, RM, ("Ranked Melees"));
            AppendMenuA(_hRUSM1, MF_STRING, URM, ("Unranked Melees"));
            AppendMenuA(_handle::_subWindowMenu::RUM, MF_POPUP, (UINT_PTR)_hRUSM2, ("Help"));
            AppendMenuA(_hRUSM2, MF_STRING, EXIT, ("Exit"));


            SetMenu(hWnd, _handle::_subWindowMenu::RUM);
            DrawMenuBar(hWnd);

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  EXTRA WINDOW CLASS
//
//
//
namespace _extra {
    void registerRtCClass(HINSTANCE hInst) {

        WNDCLASSW extra = { };

        extra.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        extra.hCursor = LoadCursor(NULL, IDC_CROSS);
        extra.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_RANKTOOLADVANCED));
        extra.hInstance = hInst;
        extra.lpszClassName = EClass;
        extra.lpfnWndProc = extraProcedure;

        RegisterClassW(&extra);

    }

    LRESULT CALLBACK extraProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

        switch (Msg) {

            case WM_COMMAND:
            {

                break;

            }

            case WM_CREATE:
            {

                ShowWindow(hWnd, SW_SHOW);
                //MessageBeep(0xFFFFFFFF);
                break;

            }


            case WM_CLOSE:
            {

                //DestroyWindow(hWnd);
                ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
                break;

            }


            default:
            {

                return DefWindowProcW(hWnd, Msg, wParam, lParam);

            }



        }

    }

    void displayExtra(HWND hWnd) {


        _handle::_subWindows::extra = CreateWindow(EClass, (L""), WS_VISIBLE | WS_OVERLAPPEDWINDOW, 30, 30, 300, 100, hWnd, NULL, NULL, NULL);

        CreateWindowA(("Static"), ("Summation: "), WS_VISIBLE | WS_CHILD, 0, 0, 90, 20, _handle::_subWindows::extra, NULL, NULL, NULL);
        
        //MessageBeep(0xFFFFFFFF);

    }

    void calculateExtra(LPCWSTR str) {

        HWND text;
        text = CreateWindow((L"Static"), str, WS_VISIBLE | WS_CHILD, 90, 0, 210, 20, _handle::_subWindows::extra, NULL, NULL, NULL);
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  FARM WINDOW CLASS
//
//
//

namespace _farm {

    //registers farm window class
    void registerFarmingClass(HINSTANCE hInst) {

        WNDCLASSW farm = { };

        farm.hbrBackground = CreateSolidBrush(RGB(0,0,0));
        farm.hCursor = LoadCursor(NULL, IDC_ARROW);
        farm.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_RANKTOOLADVANCED));
        farm.hInstance = hInst;
        farm.lpszClassName = FClass;
        farm.lpfnWndProc = farmProcedure;

        RegisterClassW(&farm);

    }

    //processes messages for the farm window
    LRESULT CALLBACK farmProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

        HBRUSH hbrBkgnd = NULL;

        HWND _hFS4 = NULL;  //output

        switch (Msg) {

        case WM_COMMAND:
        {

            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {

                case EXIT:
                {

                    //DestroyWindow(hWnd);
                    ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
                    break;

                }


                case FARM_CALC:
                {

                    if (_hFS4 != NULL)ShowWindow(_hFS4, 0);//clear output to prevent layering
                    //shows the calculation
                    //input
                    TCHAR team1[50], team2[50], delay[50];
                    _hFS4 = CreateWindowEx(WS_EX_LTRREADING, (L"Static"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 250, 200, 70, hWnd, NULL, NULL, NULL);
                    GetWindowText(_handle::_farm::E1, team1, 50);
                    GetWindowText(_handle::_farm::E2, team2, 50);
                    GetWindowText(_handle::_farm::E3, delay, 50);

                    wchar_t* pEnd;

                    unsigned long long int farmCalcOut = RANKTOOLFUNCTIONS::XPFarmCalculator((long double)wcstoull(team1, &pEnd, 10), (long double)wcstoull(team2, &pEnd, 10), (long double)wcstoull(delay, &pEnd, 10));
                    if (farmCalcOut == -1) {

                        SetWindowText(_hFS4, (L"Error"));

                    } else {

                        std::wstring stemp = std::to_wstring(farmCalcOut);

                        std::wstring suffix = L" XP";
                        stemp += suffix;

                        LPCWSTR result = stemp.c_str();

                        SetWindowText(_hFS4, result);

                    }

                    break;

                }
                break;

            }
            break;

        }


        case WM_CTLCOLORSTATIC:
        {

            HDC hdcStatic = (HDC)wParam;
            SetTextColor(hdcStatic, RGB(204, 153, 255));
            SetBkColor(hdcStatic, RGB(0, 0, 0));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }


        case WM_CTLCOLOREDIT:
        {

            HDC hdcEdit = (HDC)wParam;
            SetTextColor(hdcEdit, RGB(0, 0, 0));
            SetBkColor(hdcEdit, RGB(243, 230, 255));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }

        case WM_CTLCOLORBTN:
        {

            HDC hdcButton = (HDC)wParam;
            SetTextColor(hdcButton, RGB(0, 0, 0));
            SetBkColor(hdcButton, RGB(255, 255, 255));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }


        case WM_CREATE:
        {

            ShowWindow(hWnd, SW_SHOW);
            break;

        }


        case WM_CLOSE:
        {

            //DestroyWindow(hWnd);
            ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
            break;

        }


        default:
        {

            return DefWindowProcW(hWnd, Msg, wParam, lParam);

        }

        }

    }

    //displays farm window
    void displayFarm(HWND hWnd) {


        HWND _hFS1; //team1 input text
        HWND _hFS2; //team2 input text
        HWND _hFS3; //delay input text
        HWND _hFB; //button

        _handle::_subWindows::FWND = CreateWindowW(FClass, (L"Farming Calculator"),WS_VISIBLE | WS_OVERLAPPEDWINDOW, 30, 30, 600, 400, hWnd, NULL, NULL, NULL);

        _hFS1 = CreateWindowA(("Static"),("Amount of people on team 1"),WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 30, 100, 60, _handle::_subWindows::FWND, NULL, NULL, NULL);
        _hFS2 = CreateWindowA(("Static"),("Amount of people on team 2"),WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 30, 100, 60, _handle::_subWindows::FWND, NULL, NULL, NULL);
        _hFS3 = CreateWindowA(("Static"),("Average delay of cycle (in seconds)"),WS_VISIBLE | WS_CHILD | SS_CENTER , 450, 30, 100, 60, _handle::_subWindows::FWND, NULL, NULL, NULL);

        _handle::_farm::E1 = CreateWindowA(("Edit"),("..."),WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, _handle::_subWindows::FWND, NULL, NULL, NULL);
        _handle::_farm::E2 = CreateWindowA(("Edit"),("..."),WS_VISIBLE | WS_CHILD, 250, 100, 100, 25, _handle::_subWindows::FWND, NULL, NULL, NULL);
        _handle::_farm::E3 = CreateWindowA(("Edit"),("..."),WS_VISIBLE | WS_CHILD, 450, 100, 100, 25, _handle::_subWindows::FWND, NULL, NULL, NULL);

        _hFB = CreateWindowA(("Button"),("Calculate"),WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 150, 200, 50, _handle::_subWindows::FWND, (HMENU)FARM_CALC, NULL, NULL);

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  WEAPON BUYING WINDOW CLASS
//
//
//

namespace _weaponBuy {

    void registerWeaponClass(HINSTANCE hInst) {

        WNDCLASSW weapon = { };

        weapon.hbrBackground = CreateSolidBrush(RGB(0,0,0));
        weapon.hCursor = LoadCursor(NULL, IDC_ARROW);
        weapon.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_RANKTOOLADVANCED));
        weapon.hInstance = hInst;
        weapon.lpszClassName = WBClass;
        weapon.lpfnWndProc = weaponProcedure;

        RegisterClassW(&weapon);

    }

    LRESULT CALLBACK weaponProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

        HBRUSH hbrBkgnd = NULL;

        switch (Msg) {

        case WM_COMMAND:
        {

            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {

                case EXIT:
                {

                    //DestroyWindow(hWnd);
                    ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
                    break;

                }


                case WEAPON_COST_CALC:
                {

                    ShowWindow(_handle::_weaponBuy::S3, 0);//clear output to prevent layering
                    //shows the calculation
                    //input
                    TCHAR initial[50];
                    char target[50];
                    _handle::_weaponBuy::S3 = CreateWindowEx(WS_EX_LTRREADING, (L"Static"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 250, 200, 70, hWnd, NULL, NULL, NULL);
                    GetWindowText(_handle::_weaponBuy::E1, initial, 50);
                    GetWindowTextA(_handle::_weaponBuy::E2, target, 50);

                    wchar_t* pEnd;
                    long int weaponCalc = ::weaponCost(target, wcstol(initial, &pEnd, 10));
                    std::wstring stemp = std::to_wstring(weaponCalc);
                    LPCWSTR result = stemp.c_str();
                    SetWindowText(_handle::_weaponBuy::S3, result);

                }

                break;

            }
            break;

        }


        case WM_CTLCOLORSTATIC:
        {

            HDC hdcStatic = (HDC)wParam;
            SetTextColor(hdcStatic, RGB(204, 153, 255));
            SetBkColor(hdcStatic, RGB(0, 0, 0));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }


        case WM_CTLCOLOREDIT:
        {

            HDC hdcEdit = (HDC)wParam;
            SetTextColor(hdcEdit, RGB(0, 0, 0));
            SetBkColor(hdcEdit, RGB(243, 230, 255));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }

        case WM_CTLCOLORBTN:
        {

            HDC hdcButton = (HDC)wParam;
            SetTextColor(hdcButton, RGB(0, 0, 0));
            SetBkColor(hdcButton, RGB(255, 255, 255));

            if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
            }

            return (INT_PTR)hbrBkgnd;
            break;

        }


        case WM_CREATE:
        {

            ShowWindow(hWnd, SW_SHOW);
            weaponMenu(hWnd);
            break;

        }


        case WM_CLOSE:
        {

            //DestroyWindow(hWnd);
            ShowWindow(hWnd, SW_HIDE); //hides it, able for second use
            break;

        }


        default:

            return DefWindowProcW(hWnd, Msg, wParam, lParam);
        }

    }

    //display weapon cost window
    void displayWeaponCost(HWND hWnd) {

        UpdateWindow(hWnd); // ?


        HWND _hWBS1; //inital rank text
        HWND _hWBS2; //target gun text

        _handle::_subWindows::WBWND = CreateWindow(WBClass, (L"Weapon Cost Calculator"),WS_VISIBLE | WS_OVERLAPPEDWINDOW, 30, 30, 600, 400, hWnd, _handle::_subWindowMenu::WCM, NULL, NULL);

        _hWBS1 = CreateWindowA(("Static"),("Initial rank"),WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 30, 150, 60, _handle::_subWindows::WBWND, NULL, NULL, NULL);
        _handle::_weaponBuy::E1 = CreateWindowA(("Edit"),("..."),WS_VISIBLE | WS_CHILD | SS_CENTER, 100, 100, 150, 25, _handle::_subWindows::WBWND, NULL, NULL, NULL);

        _hWBS2 = CreateWindowA(("Static"),("Target gun (use PF's name or colloquial name)"),WS_VISIBLE | WS_CHILD | SS_CENTER , 400, 30, 150, 60, _handle::_subWindows::WBWND, NULL, NULL, NULL);
        _handle::_weaponBuy::E2 = CreateWindowA(("Edit"),("..."),WS_VISIBLE | WS_CHILD | SS_CENTER, 400, 100, 150, 25, _handle::_subWindows::WBWND, NULL, NULL, NULL);
        
        _handle::_weaponBuy::B = CreateWindowA(("Button"),("Calculate"),WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 150, 200, 50, _handle::_subWindows::WBWND, (HMENU)WEAPON_COST_CALC, NULL, NULL);
    }

    void weaponMenu(HWND hWnd) {

        //test menu
        //HMENU hWCSubMenu;

        SetMenu(hWnd, _handle::_subWindowMenu::WCM);
        DrawMenuBar(hWnd);

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Dialog Boxes
//
//

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {

        case WM_INITDIALOG:
        {

            return (INT_PTR)TRUE;

        }


        case WM_COMMAND:
        {
            
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL){
            
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            
            }
            break;
        
        }

    }
    
    return (INT_PTR)FALSE;

}

//handles attribution box
INT_PTR CALLBACK Attribution(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
        
        case WM_INITDIALOG:
        {

            return (INT_PTR)TRUE;

        }


        case WM_COMMAND:
        {

            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {

                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;

            }
            break;

        }

    }

    misc::attributionBoxErrorCatch = 0;
    return (INT_PTR)FALSE;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// FUNCTIONALITY FUNCTIONS /////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//gets weapon data, ands sets rankReturn, nameReturn, categoryReturn to the gun rank, name, and category, respectfully
inline void weaponDataGetSetter(std::string weapon) {

    std::string inputString = RANKTOOLFUNCTIONS::discriminant(weapon); //goes through discriminating function

    std::size_t posRank = inputString.find(misc::sep1); //finds the separator between name and rank
    std::size_t posCategory = inputString.find(misc::sep2); //finds the separator between rank and category


    //example: G3'59`Battle Rifle
    misc::nameReturn = inputString.substr(0, posRank);
    //gets "G3" from ("G", position 0) to ("3", position 1) which is 2 characters (2 indices of inputString)
    misc::rankReturn = inputString.substr(posRank + 1, posCategory - posRank - 1);
    //gets "5" from adding 1 to the index of misc::sep1 ("'") and then calculates length by the difference of posRank and posCategory ("59`") then subtracting 1 to remove the "`"
    misc::categoryReturn = inputString.substr(posCategory + 1);
    //gets from "B" to the end of the string

}

//weapon costs ( uses classes)
inline long weaponCost(std::string weapon, long initial) {

    std::string inputString = RANKTOOLFUNCTIONS::discriminant(weapon); //goes through discriminating function

    std::size_t posRank = inputString.find(misc::sep1); //finds the separator between name and rank
    std::size_t posCategory = inputString.find(misc::sep2); //finds the separator between rank and category

    std::string rank;

    //example: G3'59`Battle Rifle
    //misc::nameReturn = inputString.substr(0, posRank);
    //gets "G3" from ("G", position 0) to ("3", position 1) which is 2 characters (2 indices of inputString)
    rank = inputString.substr(posRank + 1, posCategory - posRank - 1);
    //gets "5" from adding 1 to the index of misc::sep1 ("'") and then calculates length by the difference of posRank and posCategory ("59`") then subtracting 1 to remove the "`"
    //misc::categoryReturn = inputString.substr(posCategory + 1);
    //gets from "B" to the end of the string



    //std::cout << name << ", rank " << rank << ", category: " << category << ". \n";

    std::string::size_type sz;
    //gets output (int)
    long rankOutput = std::stol(rank, &sz);

    //checks for user error
    long compare = rankOutput - initial;

    if (compare < 0 || rankOutput == 0 || rankOutput == initial) {

        return 0;

    } else {

        long returnOut = (rankOutput - initial) * 140 + 700;
        return returnOut;

    }

}

namespace _multiwindow { //multi window specific function(s)

    //hides multiple window
    bool hideWindows(bool farm, bool changelog, bool rank_unlock, bool weapon_cost, bool debug, bool extra) {

        if (farm) {

            ShowWindow(_handle::_subWindows::FWND, 0);

        } /*else if (farm == false) {

            ShowWindow(_handle::_subWindows::FWND, 1);
        }*/

        if (changelog) {

            ShowWindow(_handle::_subWindows::CWND, 0);

        } /*else if (changelog == false) {

            ShowWindow(_handle::_subWindows::CWND, 1);

        }*/

        if (rank_unlock) {

            ShowWindow(_handle::_subWindows::RUWND, 0);

        } /*else if (rank_unlock == false) {

            ShowWindow(_handle::_subWindows::RUWND, 1);

        }*/

        if (weapon_cost) {

            ShowWindow(_handle::_subWindows::WBWND, 0);

        } /*else if (weapon_cost == false) {

            ShowWindow(_handle::_subWindows::WBWND, 1);

        }*/

        if (debug) {

            ShowWindow(_handle::_subWindows::debug, 0);

        } /*else if (debug == false) {

            ShowWindow(_handle::_subWindows::debug, 1);

        }*/

        if (extra) {

            ShowWindow(_handle::_subWindows::extra, 0);

        }

        return true;

    }

}
