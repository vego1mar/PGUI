#ifndef W_BUTTON_WRAPPER_HPP
#define W_BUTTON_WRAPPER_HPP

#pragma region Headers includes
#include "WButtonInvokableInterface.hpp"
#pragma endregion

#pragma region ::dll
namespace dll
{
#pragma region Constants
const LPCWSTR LIBRARY_FILE_NAME = TEXT( "WButtonDynamicDLL.dll" );
const LPCSTR DECORATED_NAME_OF_FUNCTION_CONSTRUCT = "?Construct@WButtonWrapper@dll@@QAEPAVWButtonInvokableInterface@2@XZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_DESTRUCT = "?Destruct@WButtonWrapper@dll@@QAEXPAVWButtonInvokableInterface@2@@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_CREATE = "?Create@WButton@wrapper@@QAEXXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_ADDITIONAL_PARAMETER_OF_CREATION = "?GetAdditionalParameterOfCreation@WButton@wrapper@@QAEPAXXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_EXTENDED_STYLE = "?GetExtendedStyle@WButton@wrapper@@QAEKXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_MENU_IDENTIFIER = "?GetMenuIdentifier@WButton@wrapper@@QAEPAUHMENU__@@XZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_MODULE_INSTANCE_HANDLER = "?GetModuleInstanceHandler@WButton@wrapper@@QAEPAUHINSTANCE__@@XZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_OWNER = "?GetOwner@WButton@wrapper@@QAEPAUHWND__@@XZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_POSITION = "?GetPosition@WButton@wrapper@@QAE?AUtagPOINT@@XZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_SIZE = "?GetSize@WButton@wrapper@@QAE?AUtagSIZE@@XZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_STYLE = "?GetStyle@WButton@wrapper@@QAEKXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_GET_TEXT = "?GetText@WButton@wrapper@@QAEPB_WXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_IS_CREATED = "?IsCreated@WButton@wrapper@@QAE_NXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_REFRESH = "?Refresh@WButton@wrapper@@QAEHXZ";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_ADDITIONAL_PARAMETER_OF_CREATION = "?SetAdditionalParameterOfCreation@WButton@wrapper@@QAEXPAX@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_EXTENDED_STYLE = "?SetExtendedStyle@WButton@wrapper@@QAEXK@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_MENU_IDENTIFIER = "?SetMenuIdentifier@WButton@wrapper@@QAEXPAUHMENU__@@@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_OWNER = "?SetOwner@WButton@wrapper@@QAEXPAUHWND__@@@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_POSITION = "?SetPosition@WButton@wrapper@@QAEXHH@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_SIZE = "?SetSize@WButton@wrapper@@QAEXHH@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_STYLE = "?SetStyle@WButton@wrapper@@QAEXK@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_TEXT_1 = "?SetText@WButton@wrapper@@QAEXPBD_N@Z";
const LPCSTR DECORATED_NAME_OF_FUNCTION_SET_TEXT_2 = "?SetText@WButton@wrapper@@QAEXPB_W@Z";
#pragma endregion

#pragma region
class WButtonWrapper : public WButtonInvokableInterface
    {
    #pragma region Constructors
    public :
        WButtonWrapper() = default;
        ~WButtonWrapper() = default;

    private :
        WButtonWrapper( const WButtonWrapper & rhs ) = default;
        WButtonWrapper & operator= ( const WButtonWrapper & rhs ) = default;
    #pragma endregion

    #pragma region Interface
    public :
        WButtonInvokableInterface * Construct();
        void Destruct( WButtonInvokableInterface * instance );
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
    #pragma endregion

    };
#pragma endregion
}
#pragma endregion

#endif // ! W_BUTTON_WRAPPER_HPP
