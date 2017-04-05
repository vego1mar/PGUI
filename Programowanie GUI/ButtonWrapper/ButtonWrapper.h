#ifndef BUTTON_WRAPPER_HPP
#define BUTTON_WRAPPER_HPP

#pragma region Headers includes
#include "resource.h"
#pragma endregion

#pragma region ::init
namespace init
{
#pragma region Interface
ATOM RegisterMainClass( HINSTANCE instance );
BOOL InitializeInstance( HINSTANCE instance, int promptShow );
LRESULT CALLBACK MainWindowProcedure( HWND window, UINT message, WPARAM wParam, LPARAM lParam );
#pragma endregion
}
#pragma endregion

#endif // ! BUTTON_WRAPPER_HPP
