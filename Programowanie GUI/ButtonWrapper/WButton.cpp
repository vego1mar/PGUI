#pragma region Headers includes
#include "stdafx.h"
#include "WButton.hpp"
#include <cwchar>
#pragma endregion

#pragma region Recommended constructor
wrapper::WButton::WButton( HWND owner )
{
ApplyDefaultSettings();
m_ButtonOwnerWindow = owner;
m_ModuleInstanceHandler = reinterpret_cast<HINSTANCE>( GetWindowLong(m_ButtonOwnerWindow, GWL_HINSTANCE) );
}
#pragma endregion

#pragma region Create() : void
void wrapper::WButton::Create()
{
m_ButtonHandler = CreateWindowEx( m_ExtendedButtonStyle, TEXT( "BUTTON" ), m_ButtonText, m_ButtonStyle, m_PositionOfX, m_PositionOfY, m_Width, m_Height, m_ButtonOwnerWindow, m_MenuIdentifier, m_ModuleInstanceHandler, m_CreateStructureParameter );
}
#pragma endregion

#pragma region ApplyDefaultSettings() : void
void wrapper::WButton::ApplyDefaultSettings()
{
m_ButtonHandler = nullptr;
m_ExtendedButtonStyle = WS_EX_CLIENTEDGE;
m_ButtonText = TEXT( "Text" );
m_ButtonStyle = WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON;
m_PositionOfX = CW_USEDEFAULT;
m_PositionOfY = CW_USEDEFAULT;
m_Width = CW_USEDEFAULT;
m_Height = CW_USEDEFAULT;
m_ButtonOwnerWindow = nullptr;
m_MenuIdentifier = nullptr;
m_ModuleInstanceHandler = reinterpret_cast<HINSTANCE>( GetWindowLong(m_ButtonOwnerWindow, GWL_HINSTANCE) );
m_CreateStructureParameter = nullptr;
}
#pragma endregion

#pragma region IsCreated() : bool
bool wrapper::WButton::IsCreated()
{
if ( m_ButtonHandler != nullptr ) {
    return true;
    }

return false;
}
#pragma endregion

#pragma region SetStyle(...) : void
void wrapper::WButton::SetStyle( DWORD style )
{
m_ButtonStyle = style;
}
#pragma endregion

#pragma region GetStyle() : DWORD
DWORD wrapper::WButton::GetStyle()
{
return m_ButtonStyle;
}
#pragma endregion

#pragma region SetText(...) : void
void wrapper::WButton::SetText( LPCWSTR text )
{
m_ButtonText = text;
}
#pragma endregion

#pragma region SetText(...) : void
void wrapper::WButton::SetText( const char * text, bool isMultiByte )
{
if ( isMultiByte ) {
    std::string stringText( text );
    std::wstring wideText = ConvertStringToWideString( stringText );
    const wchar_t * longText = wideText.c_str();
    LPCWSTR winapiText = reinterpret_cast<LPCWSTR>( longText );
    m_ButtonText = winapiText;
    }
else {
    m_ButtonText = reinterpret_cast<LPCWSTR>( text );
    }
}
#pragma endregion

#pragma region GetText() : LPCWSTR
LPCWSTR wrapper::WButton::GetText()
{
return m_ButtonText;
}
#pragma endregion

#pragma region SetPosition(...) : void
void wrapper::WButton::SetPosition( int x, int y )
{
m_PositionOfX = x;
m_PositionOfY = y;
}
#pragma endregion

#pragma region GetPosition() : POINT
POINT wrapper::WButton::GetPosition()
{
POINT position;
position.x = m_PositionOfX;
position.y = m_PositionOfY;
return position;
}
#pragma endregion

#pragma region SetSize(...) : void
void wrapper::WButton::SetSize( int width, int height )
{
m_Width = width;
m_Height = height;
}
#pragma endregion

#pragma region GetSize() : SIZE
SIZE wrapper::WButton::GetSize()
{
SIZE size;
size.cx = m_Width;
size.cy = m_Height;
return size;
}
#pragma endregion

#pragma region SetOwner(...) : void
void wrapper::WButton::SetOwner( HWND owner )
{
m_ButtonOwnerWindow = owner;
m_ModuleInstanceHandler = reinterpret_cast<HINSTANCE>( GetWindowLong(m_ButtonOwnerWindow, GWL_HINSTANCE) );
}
#pragma endregion

#pragma region GetOwner() : HWND
HWND wrapper::WButton::GetOwner()
{
return m_ButtonOwnerWindow;
}
#pragma endregion

#pragma region GetModuleInstanceHandler() : HINSTANCE
HINSTANCE wrapper::WButton::GetModuleInstanceHandler()
{
return m_ModuleInstanceHandler;
}
#pragma endregion

#pragma region SetAdditionalParameterOfCreation(...) : void
void wrapper::WButton::SetAdditionalParameterOfCreation( LPVOID parameter )
{
m_CreateStructureParameter = parameter;
}
#pragma endregion

#pragma region GetAdditionalParameterOfCreation() : LPVOID
LPVOID wrapper::WButton::GetAdditionalParameterOfCreation()
{
return m_CreateStructureParameter;
}
#pragma endregion

#pragma region SetMenuIdentifier(...) : void
void wrapper::WButton::SetMenuIdentifier( HMENU identifier )
{
m_MenuIdentifier = identifier;
}
#pragma endregion

#pragma region GetMenuIdentifier() : HMENU
HMENU wrapper::WButton::GetMenuIdentifier()
{
return m_MenuIdentifier;
}
#pragma endregion

#pragma region SetExtendedStyle(...) : void
void wrapper::WButton::SetExtendedStyle( DWORD extendedStyle )
{
m_ExtendedButtonStyle = extendedStyle;
}
#pragma endregion

#pragma region GetExtendedStyle() : DWORD
DWORD wrapper::WButton::GetExtendedStyle()
{
return m_ExtendedButtonStyle;
}
#pragma endregion

#pragma region Refresh() : BOOL
BOOL wrapper::WButton::Refresh()
{
return InvalidateRect( m_ButtonOwnerWindow, nullptr, TRUE );
}
#pragma endregion

#pragma region ConvertStringToWideString(...) : std::wstring
std::wstring wrapper::WButton::ConvertStringToWideString( const std::string & string )
{
int size = MultiByteToWideChar( CP_UTF8, NULL, &string[0], static_cast<int>( string.size() ), NULL, NULL );
std::wstring wideString( size, NULL );
MultiByteToWideChar( CP_UTF8, NULL, &string[0], static_cast<int>( string.size() ), &wideString[0], size );
return wideString;
}
#pragma endregion

#pragma region Demo() : void
void wrapper::WButton::Demo( HWND window )
{
WButton button( window );
button.SetPosition( 50, 50 );
button.SetSize( 300, 50 );
button.SetText( L"WButton" );
button.Create();
button.Refresh();
}
#pragma endregion
