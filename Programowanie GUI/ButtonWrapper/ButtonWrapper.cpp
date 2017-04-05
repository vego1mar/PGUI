#pragma region Headers includes
#include "stdafx.h"
#include "ButtonWrapper.h"
#include "WindowsMessagesDispatchers.hpp"
#include "SharedArea.hpp"
#pragma endregion

#pragma region wWinMain(...) : int
int APIENTRY wWinMain( _In_ HINSTANCE instance, _In_opt_ HINSTANCE previousInstance, _In_ LPWSTR commandLine, _In_ int promptShow )
{
UNREFERENCED_PARAMETER( previousInstance );
UNREFERENCED_PARAMETER( commandLine );
LoadStringW( instance, IDS_APP_TITLE, shared::titleBarText, shared::TITLE_BAR_SIZE );
LoadStringW( instance, IDC_BUTTONWRAPPER, shared::mainWindowClassName, shared::MAIN_WINDOW_CLASS_NAME_SIZE );
init::RegisterMainClass( instance );

if ( init::InitializeInstance(instance, promptShow) == NULL ) {
    return FALSE;
    }

HACCEL acceleratorTable = LoadAccelerators( instance, MAKEINTRESOURCE(IDC_BUTTONWRAPPER) );
MSG message;

while ( GetMessage(&message, nullptr, 0, 0) ) {
    if ( TranslateAccelerator(message.hwnd, acceleratorTable, &message) == 0 ) {
        TranslateMessage( &message );
        DispatchMessage( &message );
        }
    }

return static_cast<int>( message.wParam );
}
#pragma endregion

#pragma region RegisterMainClass(...) : ATOM
/*
 * Registers the window class.
 */

ATOM init::RegisterMainClass( HINSTANCE instance )
{
WNDCLASSEXW windowClassExtended;
windowClassExtended.cbSize = sizeof( WNDCLASSEX );
windowClassExtended.style = CS_HREDRAW | CS_VREDRAW;
windowClassExtended.lpfnWndProc = MainWindowProcedure;
windowClassExtended.cbClsExtra = 0;
windowClassExtended.cbWndExtra = 0;
windowClassExtended.hInstance = instance;
windowClassExtended.hIcon = LoadIcon( instance, MAKEINTRESOURCE(IDI_BUTTONWRAPPER) );
windowClassExtended.hCursor = LoadCursor( nullptr, IDC_ARROW );
windowClassExtended.hbrBackground = reinterpret_cast<HBRUSH>( COLOR_WINDOW + 1 );
windowClassExtended.lpszMenuName = MAKEINTRESOURCEW( IDC_BUTTONWRAPPER );
windowClassExtended.lpszClassName = shared::mainWindowClassName;
windowClassExtended.hIconSm = LoadIcon( windowClassExtended.hInstance, MAKEINTRESOURCE(IDI_SMALL) );
return RegisterClassExW( & windowClassExtended );
}
#pragma endregion

#pragma region InitializeInstance(...) : BOOL
/*
 * Saves instance handle and creates main window.
 * In this function, we save the instance handle in a global variable and create and display the main program window.
 */

BOOL init::InitializeInstance( HINSTANCE instance, int promptShow )
{
shared::mainWindowInstance = instance;
HWND window = CreateWindowW( shared::mainWindowClassName, shared::titleBarText, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, instance, nullptr );

if ( window == NULL ) {
    return FALSE;
    }

ShowWindow( window, promptShow );
UpdateWindow( window );
return TRUE;
}
#pragma endregion

#pragma region MainWindowProcedure(...) : LRESULT
/*
 * Processes messages for the main window.
 *
 * WM_COMMAND    process the application menu
 * WM_PAINT      paint the main window
 * WM_DESTROY    post a quit message and return
 */

LRESULT CALLBACK init::MainWindowProcedure( HWND window, UINT message, WPARAM wParam, LPARAM lParam )
{
switch ( message ) {
    case WM_COMMAND :
        wmd::WMCommandDispatcher( window, message, wParam, lParam );
        break;

    case WM_PAINT :
        wmd::WMPaintDispatcher( window, message, wParam, lParam );
        break;

    case WM_DESTROY :
        PostQuitMessage( 0 );
        break;

    default :
        return DefWindowProc( window, message, wParam, lParam );
    }

return 0;
}
#pragma endregion
