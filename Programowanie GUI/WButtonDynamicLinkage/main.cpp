#pragma region Headers includes
#include "WButtonWrapper.hpp"
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

#pragma region main()
int main()
{
dll::WButtonWrapper buttonWrapper;
dll::WButtonInvokableInterface * buttonInterface = buttonWrapper.Construct();
buttonWrapper.SetOwner( reinterpret_cast<HWND>( 23 ) );
buttonWrapper.SetText( TEXT("Text") );
buttonWrapper.SetPosition( 100, 100 );
buttonWrapper.SetSize( 120, 30 );
buttonWrapper.Create();

if ( buttonWrapper.IsCreated() ) {
    buttonWrapper.Destruct( buttonInterface );
    return 1;
    }

buttonWrapper.Destruct( buttonInterface );
return 0;
}
#pragma endregion
