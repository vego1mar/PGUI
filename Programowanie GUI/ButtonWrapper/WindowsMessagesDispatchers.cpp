#pragma region Headers includes
#include "stdafx.h"
#include "WindowsMessagesDispatchers.hpp"
#include "Resource.h"
#include "WButton.hpp"
#pragma endregion

#pragma region WMCommandDispatcher(...) : void
void wmd::WMCommandDispatcher( HWND window, UINT message, WPARAM wParam, LPARAM lParam )
{
int windowsMessageID = LOWORD( wParam );

switch ( windowsMessageID ) {
    case MENU_FILE_SHOW_WRAPPED_BUTTON :
        wrapper::WButton::Demo( window );
        break;

    case IDM_EXIT :
        DestroyWindow( window );
        break;

    default :
        DefWindowProc( window, message, wParam, lParam );
    }
}
#pragma endregion

#pragma region WMPaintDispatcher(...) : void
void wmd::WMPaintDispatcher( HWND window, UINT message, WPARAM wParam, LPARAM lParam )
{
PAINTSTRUCT painter;
HDC graphics = BeginPaint( window, &painter );
// Add any drawing code that uses graphics here.
EndPaint( window, &painter );
}
#pragma endregion
