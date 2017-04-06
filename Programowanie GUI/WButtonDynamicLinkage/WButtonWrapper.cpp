#pragma region Headers includes
#include "WButtonWrapper.hpp"
#include <cstddef>
#pragma endregion

#pragma region Construct() : WButtonInvokableInterface
dll::WButtonInvokableInterface * dll::WButtonWrapper::Construct()
{
return new dll::WButtonWrapper();
}
#pragma endregion

#pragma region Destruct(...) : void
void dll::WButtonWrapper::Destruct( WButtonInvokableInterface * instance )
{
delete instance;
}
#pragma endregion

#pragma region Create() : void
void dll::WButtonWrapper::Create()
{
typedef void (WINAPI * Create)();
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_CREATE );
    Create function = reinterpret_cast<Create>( functionAddress );

    if ( function != nullptr ) {
        function();
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region IsCreated() : bool
bool dll::WButtonWrapper::IsCreated()
{
typedef bool (WINAPI * IsCreated)();
bool result = nullptr;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_IS_CREATED );
    IsCreated function = reinterpret_cast<IsCreated>( functionAddress );

    if ( function != nullptr ) {
        bool resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetStyle(...) : void
void dll::WButtonWrapper::SetStyle( DWORD style )
{
typedef void (WINAPI * SetStyle)(DWORD style);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_STYLE );
    SetStyle function = reinterpret_cast<SetStyle>( functionAddress );

    if ( function != nullptr ) {
        function( style );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetStyle() : DWORD
DWORD dll::WButtonWrapper::GetStyle()
{
typedef DWORD (WINAPI * GetStyle)();
DWORD result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_STYLE );
    GetStyle function = reinterpret_cast<GetStyle>( functionAddress );

    if ( function != nullptr ) {
        DWORD resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetText(...) : void
void dll::WButtonWrapper::SetText( LPCWSTR text )
{
typedef void (WINAPI * SetText)(LPCWSTR text);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_TEXT_2 );
    SetText function = reinterpret_cast<SetText>( functionAddress );

    if ( function != nullptr ) {
        function( text );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region SetText(...) : void
void dll::WButtonWrapper::SetText( const char * text, bool isMultiByte )
{
typedef void (WINAPI * SetText)(const char * text, bool isMultiByte);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_TEXT_1 );
    SetText function = reinterpret_cast<SetText>( functionAddress );

    if ( function != nullptr ) {
        function( text, isMultiByte );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetText() : LPCWSTR
LPCWSTR dll::WButtonWrapper::GetText()
{
typedef LPCWSTR (WINAPI * GetText)();
LPCWSTR result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_TEXT );
    GetText function = reinterpret_cast<GetText>( functionAddress );

    if ( function != nullptr ) {
        LPCWSTR resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetPosition(...) : void
void dll::WButtonWrapper::SetPosition( int x, int y )
{
typedef void (WINAPI * SetPosition)(int x, int y);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_POSITION );
    SetPosition function = reinterpret_cast<SetPosition>( functionAddress );

    if ( function != nullptr ) {
        function( x, y );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetPosition() : POINT
POINT dll::WButtonWrapper::GetPosition()
{
typedef POINT (WINAPI * GetPosition)();
POINT result;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_POSITION );
    GetPosition function = reinterpret_cast<GetPosition>( functionAddress );

    if ( function != nullptr ) {
        POINT resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetSize(...) : void
void dll::WButtonWrapper::SetSize( int width, int height )
{
typedef void (WINAPI * SetSize)(int width, int height);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_SIZE );
    SetSize function = reinterpret_cast<SetSize>( functionAddress );

    if ( function != nullptr ) {
        function( width, height );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetSize() : SIZE
SIZE dll::WButtonWrapper::GetSize()
{
typedef SIZE (WINAPI * GetSize)();
SIZE result;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_SIZE );
    GetSize function = reinterpret_cast<GetSize>( functionAddress );

    if ( function != nullptr ) {
        SIZE resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetOwner(...) : void
void dll::WButtonWrapper::SetOwner( HWND owner )
{
typedef void (WINAPI * SetOwner)(HWND owner);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_OWNER );
    SetOwner function = reinterpret_cast<SetOwner>( functionAddress );

    if ( function != nullptr ) {
        function( owner );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetOwner() : HWND
HWND dll::WButtonWrapper::GetOwner()
{
typedef HWND (WINAPI * GetOwner)();
HWND copyOfOwner = nullptr;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_OWNER );
    GetOwner function = reinterpret_cast<GetOwner>( functionAddress );

    if ( function != nullptr ) {
        HWND returnedOwner = function();
        copyOfOwner = returnedOwner;
        }

    FreeLibrary( libraryModule );
    }

return copyOfOwner;
}
#pragma endregion

#pragma region GetModuleInstanceHandler() : HINSTANCE
HINSTANCE dll::WButtonWrapper::GetModuleInstanceHandler()
{
typedef HINSTANCE (WINAPI * GetModuleInstanceHandler)();
HINSTANCE result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_MODULE_INSTANCE_HANDLER );
    GetModuleInstanceHandler function = reinterpret_cast<GetModuleInstanceHandler>( functionAddress );

    if ( function != nullptr ) {
        HINSTANCE resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetAdditionalParameterOfCreation(...) : void
void dll::WButtonWrapper::SetAdditionalParameterOfCreation( LPVOID parameter )
{
typedef void (WINAPI * SetAdditionalParameterOfCreation)(LPVOID parameter);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_ADDITIONAL_PARAMETER_OF_CREATION );
    SetAdditionalParameterOfCreation function = reinterpret_cast<SetAdditionalParameterOfCreation>( functionAddress );

    if ( function != nullptr ) {
        function( parameter );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetAdditionalParameterOfCreation() : LPVOID
LPVOID dll::WButtonWrapper::GetAdditionalParameterOfCreation()
{
typedef LPVOID (WINAPI * GetAdditionalParameterOfCreation)();
LPVOID result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_ADDITIONAL_PARAMETER_OF_CREATION );
    GetAdditionalParameterOfCreation function = reinterpret_cast<GetAdditionalParameterOfCreation>( functionAddress );

    if ( function != nullptr ) {
        LPVOID resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetMenuIdentifier(...) : void
void dll::WButtonWrapper::SetMenuIdentifier( HMENU identifier )
{
typedef void (WINAPI * SetMenuIdentifier)(HMENU identifier);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_MENU_IDENTIFIER );
    SetMenuIdentifier function = reinterpret_cast<SetMenuIdentifier>( functionAddress );

    if ( function != nullptr ) {
        function( identifier );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetMenuIdentifier() : HMENU
HMENU dll::WButtonWrapper::GetMenuIdentifier()
{
typedef HMENU (WINAPI * GetMenuIdentifier)();
HMENU result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_MENU_IDENTIFIER );
    GetMenuIdentifier function = reinterpret_cast<GetMenuIdentifier>( functionAddress );

    if ( function != nullptr ) {
        HMENU resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region SetExtendedStyle(...) : void
void dll::WButtonWrapper::SetExtendedStyle( DWORD extendedStyle )
{
typedef void (WINAPI * SetExtendedStyle)(DWORD extendedStyle);
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_SET_EXTENDED_STYLE );
    SetExtendedStyle function = reinterpret_cast<SetExtendedStyle>( functionAddress );

    if ( function != nullptr ) {
        function( extendedStyle );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion

#pragma region GetExtendedStyle() : DWORD
DWORD dll::WButtonWrapper::GetExtendedStyle()
{
typedef DWORD (WINAPI * GetExtendedStyle)();
DWORD result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_GET_EXTENDED_STYLE );
    GetExtendedStyle function = reinterpret_cast<GetExtendedStyle>( functionAddress );

    if ( function != nullptr ) {
        DWORD resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion

#pragma region Refresh() : BOOL
BOOL dll::WButtonWrapper::Refresh()
{
typedef BOOL (WINAPI * Refresh)();
BOOL result = NULL;
HMODULE libraryModule = LoadLibrary( LIBRARY_FILE_NAME );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, DECORATED_NAME_OF_FUNCTION_REFRESH );
    Refresh function = reinterpret_cast<Refresh>( functionAddress );

    if ( function != nullptr ) {
        BOOL resultFromBlock = function();
        result = resultFromBlock;
        }

    FreeLibrary( libraryModule );
    }

return result;
}
#pragma endregion
