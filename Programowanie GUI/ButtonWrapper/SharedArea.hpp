#ifndef SHARED_AREA_HPP
#define SHARED_AREA_HPP

#pragma region Headers includes
#include <Windows.h>
#include <string>
#pragma endregion

#pragma region ::shared
namespace shared
{
#pragma region Constants
const std::size_t TITLE_BAR_SIZE = 100;
const std::size_t MAIN_WINDOW_CLASS_NAME_SIZE = 100;
#pragma endregion

#pragma region Common variables
HINSTANCE mainWindowInstance = nullptr;
WCHAR titleBarText[ TITLE_BAR_SIZE ] = { 0 };
WCHAR mainWindowClassName[ MAIN_WINDOW_CLASS_NAME_SIZE ] = { 0 };
#pragma endregion
}
#pragma endregion

#endif // ! SHARED_AREA_HPP
