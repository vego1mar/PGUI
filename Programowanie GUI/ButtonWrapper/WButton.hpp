#ifndef WINAPI_BUTTON_HPP
#define WINAPI_BUTTON_HPP

#pragma region Headers includes
#include <Windows.h>
#include <string>
#pragma endregion

#pragma region ::wrapper
namespace wrapper
{
#pragma region WButton
class WButton
    {

    #pragma region Members
    private :
        HWND m_ButtonHandler;
        DWORD m_ExtendedButtonStyle;
        LPCWSTR m_ButtonText;
        DWORD m_ButtonStyle;
        int m_PositionOfX;
        int m_PositionOfY;
        int m_Width;
        int m_Height;
        HWND m_ButtonOwnerWindow;
        HMENU m_MenuIdentifier;
        HINSTANCE m_ModuleInstanceHandler;
        LPVOID m_CreateStructureParameter;
    #pragma endregion

    #pragma region Class construction
    public :
        WButton( HWND owner );
        virtual ~WButton() = default;

    private :
        WButton() = default;
        WButton( const WButton & rhs ) = default;
        WButton & operator= ( const WButton & rhs ) = default;
    #pragma endregion

    #pragma region Interface
    public :
        void Create();
        bool IsCreated();
        void SetStyle( DWORD style );
        DWORD GetStyle();
        void SetText( LPCWSTR text );
        void SetText( const char * text, bool isMultiByte );
        LPCWSTR GetText();
        void SetPosition( int x, int y );
        POINT GetPosition();
        void SetSize( int width, int height );
        SIZE GetSize();
        void SetOwner( HWND owner );
        HWND GetOwner();
        HINSTANCE GetModuleInstanceHandler();
        void SetAdditionalParameterOfCreation( LPVOID parameter );
        LPVOID GetAdditionalParameterOfCreation();
        void SetMenuIdentifier( HMENU identifier );
        HMENU GetMenuIdentifier();
        void SetExtendedStyle( DWORD extendedStyle );
        DWORD GetExtendedStyle();
        BOOL Refresh();
        static void Demo( HWND window );

    private :
        void ApplyDefaultSettings();
        std::wstring ConvertStringToWideString( const std::string & string );
    #pragma endregion

    };
#pragma endregion
}
#pragma endregion

#endif // ! WINAPI_BUTTON_HPP
