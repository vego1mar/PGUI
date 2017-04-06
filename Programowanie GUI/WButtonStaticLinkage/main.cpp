#pragma region Headers includes
#include "..\ButtonWrapper\WButton.hpp"
#include <cstddef>
#include <Windows.h>
#pragma endregion

/*
 * Library static linkage.
 *
 * Prerequisites:
 * (1) Header file: @"..\ButtonWrapper\WButton.hpp"
 * (2) Project reference: @"..\Debug\WButtonStaticDLL.lib" or @"..\WButtonStaticDLL\WButtonStaticDLL.vcxproj"
 * (3) No precompiled headers native usage.
 */

#pragma region main()
int main()
{
wrapper::WButton button( NULL );
button.SetPosition( 101, 11 );
POINT position = button.GetPosition();
button.Create();

if ( button.IsCreated() ) {
    return 1;
    }

return 0;
}
#pragma endregion
