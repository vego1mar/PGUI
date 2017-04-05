#pragma region Headers includes
#include "stdafx.h"
#include "..\ButtonWrapper\WButton.hpp"
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
wrapper::WButton::Demo( NULL );
return 0;
}
#pragma endregion
