#include"Windows/MessageBox.h"

int cms::Windows::MessageBox::Open(const char* description, const char* title, unsigned int type)
{
	int result = MessageBoxA(GetActiveWindow(), description, title, type);
	return result;
}

///		How To Use
/// Header File : #include<WinUser.h>
/// Additional Includes : #include <Windows.h>
/// 
/// Function : MessageBoxA
///		First Parameter : Parent window of the message box
///			GetActiveWindow()
///			- Retrieves the window handle to the active window attached to the calling thread's message queue.
///		Second Parameter : The message to be displayed
///		Third Parameter : The title of the prompt dialog
///		Fourth Parameter : TYPE 
///					1) MB_ABORTRETRYIGNORE 
///					2) MB_CANCELTRYCONTINUE
///					3) MB_HELP
///					4) MB_OK
///					5) MB_OKCANCEL
///					6) MB_RETRYCANCEL
///					7) MB_YESNO
///					8) MB_YESNOCANCEL
///				
///				Icons
///					1) MB_ICONERROR
///					2) MB_ICONQUESTION
///					3) MB_ICONWARNING
///					4) MB_ICONINFORMATION