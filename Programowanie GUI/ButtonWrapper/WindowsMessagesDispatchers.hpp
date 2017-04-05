#ifndef WINDOWS_MESSAGES_DISPATCHERS_HPP
#define WINDOWS_MESSAGES_DISPATCHERS_HPP

#pragma region Headers includes
#include <Windows.h>
#pragma endregion

#pragma region ::wmd
namespace wmd
{
#pragma region Interface
void WMCommandDispatcher( HWND window, UINT message, WPARAM wParam, LPARAM lParam );
void WMPaintDispatcher( HWND window, UINT message, WPARAM wParam, LPARAM lParam );
#pragma endregion
}
#pragma endregion

#endif // ! WINDOWS_MESSAGES_DISPATCHERS_HPP

