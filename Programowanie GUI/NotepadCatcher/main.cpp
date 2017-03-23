#pragma region PreprocessorDirectives
#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WINVER
#define WINVER 0x0A00
#endif

#define _WIN32_WINNT_NT4                    0x0400		// Windows NT 4.0 
#define _WIN32_WINNT_WIN2K                  0x0500		// Windows 2000 
#define _WIN32_WINNT_WINXP                  0x0501		// Windows XP 
#define _WIN32_WINNT_WS03                   0x0502		// Windows Server 2003 
#define _WIN32_WINNT_WIN6                   0x0600		// Windows Vista 
#define _WIN32_WINNT_VISTA                  0x0600		// Windows Vista 
#define _WIN32_WINNT_WS08                   0x0600		// Windows Server 2008 
#define _WIN32_WINNT_LONGHORN               0x0600		// Windows Vista 
#define _WIN32_WINNT_WIN7                   0x0601		// Windows 7 
#define _WIN32_WINNT_WIN8                   0x0602		// Windows 8 
#define _WIN32_WINNT_WINBLUE                0x0603		// Windows 8.1 
#define _WIN32_WINNT_WINTHRESHOLD           0x0A00		// Windows 10 
#define _WIN32_WINNT_WIN10                  0x0A00		// Windows 10 

#include <iostream>
#include <Windows.h>
#include <cstddef>
#include <string>
#include <cwchar>
#include <cstdbool>
#include <cctype>
#include <ios>
#pragma endregion

namespace keystroke
{
#pragma region PressAndReleaseKey(...) : void
void PressAndReleaseTheKey( WORD vk_Key, const UINT numberOfInputs )
{
static INPUT input;
input.type = INPUT_KEYBOARD;
input.ki.wScan = 0;
input.ki.time = 0;
input.ki.dwExtraInfo = 0;
input.ki.wVk = vk_Key;

for ( UINT i=0; i<numberOfInputs; i++ ) {
    input.ki.dwFlags = 0;
    SendInput( 1, &input, sizeof(input) );
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput( 1, &input, sizeof(input) );
    }
}
#pragma endregion

#pragma region GetUpperCaseLetter(...) : int
int GetUpperCaseLetter( int character )
{
if ( character >= 0x61 && character <= 0x7A ) {
    return std::toupper( character );
    }

return character;
}
#pragma endregion

#pragma region IsAlphaNumeric(...) : bool
bool IsAlphaNumeric( int ch )
{
if ( (ch >= 0x61 && ch <= 0x7A) || (ch >= 0x41 && ch <= 0x5A) || (ch >= 0x30 && ch <= 0x39) ) {
    return ( std::isalnum( ch ) != 0 );
    }

return false;
}
#pragma endregion
}

namespace catcher
{
#pragma region TypeDefinitions
enum userOptions { EXIT_PROGRAM = 1, 
                   FIND_EDITOR_BY_NAME = 2, 
                   FIND_EDITOR_BY_CLASS = 3,
                   HIDE_EDITOR = 4,
                   SHOW_EDITOR = 5,
                   SET_TEXT_TO_EDITOR = 6,
                   SAVE_EDITOR_CONTENT = 7,
                   SAVE_AS_EDITOR_CONTENT = 8,
                   SHOW_CAPTURED_INFO = 9
                   };
#pragma endregion

#pragma region Constants
const std::size_t USER_TEXT_SIZE = 64;
const std::size_t USER_TEXT_WIDE_SIZE = 1024;
const std::streamsize FILE_NAME_FROM_USER_SIZE = 1024;
const userOptions USER_OPTIONS = userOptions();
const std::string ENTER_THE_TEXT = "Wprowad\xAB" " tekst: ";
const std::string ENTER_THE_NAME = "Wprowad\xAB" " nazw\xA9" ": ";
const std::string CLOSING_THE_PROGRAM = "Zamykanie programu.";
const std::string NO_OPTION_HAS_BEEN_SELECT = "Nie wybrano \xBE" "adnej opcji.";
const std::string SUCCESS = "Sukces!";
const std::string FAIL = "Pora\xBE" "ka!";
const std::string SAVE_AS_DIALOG_HANDLE = "Uchwyt okna 'Zapisywanie jako...': ";
const std::string MAIN_WINDOW_HANDLE = "Uchwyt okna g\x88" "\xA2" "wnego: ";
const std::string EDIT_WINDOW_HANDLE = "Uchwyt podokna Edit: ";
const std::string FILE_NAME = "Nazwa pliku: ";
#pragma endregion

#pragma region PrintStartTextWithOptions() : void
void PrintStartTextWithOptions()
{
const std::string VISUAL_SEPARATOR = "********************************************";
std::cout << VISUAL_SEPARATOR << std::endl
    << "* Opcje:" << std::endl
    << "* 1. Koniec." << std::endl
    << "* 2. Znajd\xAB" " edytor po nazwie." << std::endl
    << "* 3. Znajd\xAB" " edytor po klasie." << std::endl
    << "* 4. Ukryj edytor." << std::endl
    << "* 5. Poka\xBE" " edytor." << std::endl
    << "* 6. Wpisz tekst do edytora." << std::endl
    << "* 7. Zapisz." << std::endl
    << "* 8. Zapisz jako." << std::endl
    << "* 9. Poka\xBE" " przechwycone informacje." << std::endl
    << VISUAL_SEPARATOR << std::endl
    << "Tw\xA2" "j wyb\xA2" "r: ";
}
#pragma endregion

#pragma region GetUserChoise() : int
int GetUserChoise()
{
char userText[ USER_TEXT_SIZE ];
int userChoise = 0;
std::cin >> userChoise;
std::cin.ignore();
std::cin.getline( userText, catcher::USER_TEXT_SIZE );
return userChoise;
}
#pragma endregion

#pragma region FindEditorByName(...) : void
void FindEditorByName( HWND & mainWindow )
{
wchar_t userTextWide[ USER_TEXT_WIDE_SIZE ];
std::cout << ENTER_THE_NAME;
std::wcin.getline( userTextWide, catcher::USER_TEXT_SIZE );
std::wcout << userTextWide << std::endl;
mainWindow = FindWindow( NULL, userTextWide );
std::cout << (mainWindow ? SUCCESS : FAIL) << std::endl;
}
#pragma endregion

#pragma region FindEditorByClass(...) : void
void FindEditorByClass( HWND & mainWindow, HWND & editWindow )
{
mainWindow = FindWindowEx( NULL, NULL, L"Notepad", NULL );
std::cout << (mainWindow ? SUCCESS : FAIL) << std::endl;
editWindow = FindWindowEx( mainWindow, NULL, L"Edit", NULL );
std::cout << (editWindow ? SUCCESS : FAIL) << std::endl;
std::cout << MAIN_WINDOW_HANDLE << std::hex << mainWindow << std::endl;
std::cout << EDIT_WINDOW_HANDLE << std::hex << editWindow << std::endl;
}
#pragma endregion

#pragma region SetTextToEditor(...) : void
void SetTextToEditor( HWND & editWindow )
{
if ( editWindow != NULL ) {
    wchar_t userTextWide[ catcher::USER_TEXT_WIDE_SIZE ];
    std::cout << ENTER_THE_TEXT;
    std::wcin.getline( userTextWide, catcher::USER_TEXT_WIDE_SIZE );
    SendMessage( editWindow, WM_SETTEXT, 0, reinterpret_cast<LPARAM>( userTextWide ) );
    return;
    }

std::cout << "Wprowadz tekst: ";
std::cout << "Edit window is a NULL." << std::endl;
}
#pragma endregion

#pragma region GetFileNameFromUser() : std::string
std::string GetFileNameFromUser()
{
char fileNameFromUser [ FILE_NAME_FROM_USER_SIZE ];
std::memset( fileNameFromUser, NULL, FILE_NAME_FROM_USER_SIZE * sizeof(char) );
std::cout << "[" << std::to_string( FILE_NAME_FROM_USER_SIZE ) << "] " << FILE_NAME;
std::cin.getline( fileNameFromUser, FILE_NAME_FROM_USER_SIZE );
return std::string( fileNameFromUser );
}
#pragma endregion

#pragma region InvokeSaveAsDialog(...) : LRESULT
LRESULT InvokeSaveAsDialog( HWND & parentWindow )
{
LRESULT result = PostMessage( parentWindow, WM_COMMAND, 4, NULL );
Sleep( 1000 );
return result;
}
#pragma endregion

#pragma region GetEditComponentFromSaveAsDialog(...) : HWND
HWND GetEditComponentFromSaveAsDialog( HWND & saveAsDialogParent )
{
HWND saveAsDialog_0 = FindWindow( NULL, L"Zapisywanie jako" );
HWND saveAsDialog_1 = FindWindowEx( saveAsDialog_0, NULL, L"DUIViewWndClassName", NULL );
HWND saveAsDialog_2 = FindWindowEx( saveAsDialog_1, NULL, L"DirectUIHWND", NULL );
HWND saveAsDialog_3 = FindWindowEx( saveAsDialog_2, NULL, L"FloatNotifySink", NULL );
HWND saveAsDialog_4 = FindWindowEx( saveAsDialog_3, NULL, L"ComboBox", NULL );
HWND saveAsDialog_5 = FindWindowEx( saveAsDialog_4, NULL, L"Edit", NULL );
return saveAsDialog_5;
}
#pragma endregion

#pragma region KeystrokeAlphaNumericText(...) : void
void KeystrokeAlphaNumericText( const std::string & text )
{
for ( std::size_t i=0; i<text.size(); i++ ) {
    if ( keystroke::IsAlphaNumeric( text[i] ) ) {
        WORD currentKey = static_cast<WORD>( keystroke::GetUpperCaseLetter( text[i] ) );
        keystroke::PressAndReleaseTheKey( currentKey, 1 );
        }
    }
}
#pragma endregion

#pragma region SaveAsEditorContent(...) : void
void SaveAsEditorContent( HWND & mainWindow )
{
const std::string fileNameFromUser = GetFileNameFromUser();
InvokeSaveAsDialog( mainWindow );
HWND saveAsDialogEdit = GetEditComponentFromSaveAsDialog( mainWindow );

std::cout << (saveAsDialogEdit ? SUCCESS : FAIL) << std::endl;
std::cout << SAVE_AS_DIALOG_HANDLE << std::hex << saveAsDialogEdit << std::endl;

keystroke::PressAndReleaseTheKey( VK_DELETE, 1 );
KeystrokeAlphaNumericText( fileNameFromUser );
keystroke::PressAndReleaseTheKey( VK_RETURN, 1 );
}
#pragma endregion

#pragma region ShowNotepadCatcherInfo() : void
void ShowNotepadCatcherInfo( const HWND & mainWindow, const HWND & editWindow )
{
std::cout << std::endl << MAIN_WINDOW_HANDLE << std::hex << mainWindow << std::endl;
std::cout << std::endl << EDIT_WINDOW_HANDLE << std::hex << editWindow << std::endl;
}
#pragma endregion
}

namespace program
{
#pragma region GoToLoopWithUserOptions(...) : bool
bool GoToLoopWithUserOptions( HWND & mainWindow, HWND & editWindow )
{
switch ( catcher::GetUserChoise() ) {
    case catcher::EXIT_PROGRAM :
        std::cout << catcher::CLOSING_THE_PROGRAM << std::endl;
        return false;

    case catcher::FIND_EDITOR_BY_NAME :
        catcher::FindEditorByName( mainWindow );
        break;

    case catcher::FIND_EDITOR_BY_CLASS :
        catcher::FindEditorByClass( mainWindow, editWindow );
        break;

    case catcher::HIDE_EDITOR :
        ShowWindow( mainWindow, SW_HIDE );
        break;

    case catcher::SHOW_EDITOR :
        ShowWindow( mainWindow, SW_SHOW );
        break;

    case catcher::SET_TEXT_TO_EDITOR :
        catcher::SetTextToEditor( editWindow );
        break;

    case catcher::SAVE_EDITOR_CONTENT :
        SendMessage( mainWindow, WM_COMMAND, 3, 0 );
        break;

    case catcher::SAVE_AS_EDITOR_CONTENT :
        catcher::SaveAsEditorContent( mainWindow );
        break;

    case catcher::SHOW_CAPTURED_INFO :
        catcher::ShowNotepadCatcherInfo( mainWindow, editWindow );
        break;

    default :
        std::cout << catcher::NO_OPTION_HAS_BEEN_SELECT << std::endl;
    }

return true;
}
#pragma endregion

#pragma region RunNotepadCatcher() : void
void RunNotepadCatcher()
{
HWND notepadMainWindow = NULL;
HWND notepadEditWindow = NULL;
notepadMainWindow = FindWindow( NULL, L"1 — Notatnik" );

if ( notepadMainWindow == NULL ) {
    std::cout << "Notatnik nie zosta\x88" " znaleziony." << std::endl;
    }

std::cout << "Uchwyt okna: " << std::hex << notepadMainWindow << std::endl;
bool shouldLoopBeExecuting = true;

do {
    system( "cls" );
    catcher::PrintStartTextWithOptions();
    shouldLoopBeExecuting = GoToLoopWithUserOptions( notepadMainWindow, notepadEditWindow );
    std::getchar();
    }
while ( shouldLoopBeExecuting );

ShowWindow( notepadMainWindow, SW_HIDE );
ShowWindow( notepadMainWindow, SW_SHOW );
}
#pragma endregion
}

#pragma region main()
int main()
{
program::RunNotepadCatcher();
return 0;
}
#pragma endregion
