#ifndef WINAPI_BUTTON_HPP
#define WINAPI_BUTTON_HPP

#if defined WINAPI_BUTTON_HPP_DLL_EXPORT
#define EXPORT_OR_IMPORT __declspec( dllexport )
#else
#define EXPORT_OR_IMPORT __declspec( dllimport )
#endif

/*
 * Project properties | C/C++ | Preprocessor | PreprocessorDefinitions = %ORIGIN%,WINAPI_BUTTON_HPP_DLL_EXPORT
 * Project properties | Linker | Debugging | Generate Debug info = No
 */

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
        __declspec(dllexport) std::string operator()( std::string method );

    private :
        WButton() = default;
        WButton( const WButton & rhs ) = default;
        WButton & operator= ( const WButton & rhs ) = default;
    #pragma endregion

    #pragma region Interface
    public :
        void __declspec(dllexport) Create();
        bool __declspec(dllexport) IsCreated();
        void __declspec(dllexport) SetStyle( DWORD style );
        DWORD __declspec(dllexport) GetStyle();
        void __declspec(dllexport) SetText( LPCWSTR text );
        void __declspec(dllexport) SetText( const char * text, bool isMultiByte );
        LPCWSTR __declspec(dllexport) GetText();
        void __declspec(dllexport) SetPosition( int x, int y );
        POINT __declspec(dllexport) GetPosition();
        void __declspec(dllexport) SetSize( int width, int height );
        SIZE __declspec(dllexport) GetSize();
        void __declspec(dllexport) SetOwner( HWND owner );
        HWND __declspec(dllexport) GetOwner();
        HINSTANCE __declspec(dllexport) GetModuleInstanceHandler();
        void __declspec(dllexport) SetAdditionalParameterOfCreation( LPVOID parameter );
        LPVOID __declspec(dllexport) GetAdditionalParameterOfCreation();
        void __declspec(dllexport) SetMenuIdentifier( HMENU identifier );
        HMENU __declspec(dllexport) GetMenuIdentifier();
        void __declspec(dllexport) SetExtendedStyle( DWORD extendedStyle );
        DWORD __declspec(dllexport) GetExtendedStyle();
        BOOL __declspec(dllexport) Refresh();
        static EXPORT_OR_IMPORT void Demo( HWND window );

    private :
        void ApplyDefaultSettings();
        std::wstring ConvertStringToWideString( const std::string & string );
    #pragma endregion

    };
#pragma endregion
}
#pragma endregion

#endif // ! WINAPI_BUTTON_HPP
