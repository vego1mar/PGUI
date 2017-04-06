#ifndef W_BUTTON_INVOKABLE_INTERFACE_HPP
#define W_BUTTON_INVOKABLE_INTERFACE_HPP

#pragma region Headers includes
#include <Windows.h>
#pragma endregion

#pragma region ::dll
namespace dll
{
#pragma region WButtonInvokableInterface
class WButtonInvokableInterface
    {
    public :
        virtual void Create() = 0;
        virtual bool IsCreated() = 0;
        virtual void SetStyle( DWORD style ) = 0;
        virtual DWORD GetStyle() = 0;
        virtual void SetText( LPCWSTR text ) = 0;
        virtual void SetText( const char * text, bool isMultiByte ) = 0;
        virtual LPCWSTR GetText() = 0;
        virtual void SetPosition( int x, int y ) = 0;
        virtual POINT GetPosition() = 0;
        virtual void SetSize( int width, int height ) = 0;
        virtual SIZE GetSize() = 0;
        virtual void SetOwner( HWND owner ) = 0;
        virtual HWND GetOwner() = 0;
        virtual HINSTANCE GetModuleInstanceHandler() = 0;
        virtual void SetAdditionalParameterOfCreation( LPVOID parameter ) = 0;
        virtual LPVOID GetAdditionalParameterOfCreation() = 0;
        virtual void SetMenuIdentifier( HMENU identifier ) = 0;
        virtual HMENU GetMenuIdentifier() = 0;
        virtual void SetExtendedStyle( DWORD extendedStyle ) = 0;
        virtual DWORD GetExtendedStyle() = 0;
        virtual BOOL Refresh() = 0;
    };
#pragma endregion
}
#pragma endregion

#endif // ! W_BUTTON_INVOKABLE_INTERFACE_HPP
