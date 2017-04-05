#pragma region Headers includes
#include "stdafx.h"
#include <Windows.h>
#pragma endregion

/*
 * Library dynamic linkage.
 *
 * Prerequisites:
 * (1) File: @"..\Debug\WButtonDynamicDLL.dll".
 * (2) Ordinal name of the specified function from the DLL (mangled/decorated or defined).
 *
 */

#pragma region ::dll
namespace dll
{
typedef void (*Demo)(HWND owner);

#pragma region UseDemoFromLibrary() : void
void UseDemoFromLibrary()
{
HMODULE libraryModule = LoadLibrary( L"WButtonDynamicDLL.dll" );

if ( libraryModule != nullptr ) {
    FARPROC functionAddress = GetProcAddress( libraryModule, "Demo" );
    Demo demo = (Demo)( functionAddress );

    if ( demo != nullptr ) {
        demo( NULL );
        }

    FreeLibrary( libraryModule );
    }
}
#pragma endregion
}
#pragma endregion

#pragma region main()
int main()
{
dll::UseDemoFromLibrary();
return 0;
}
#pragma endregion
