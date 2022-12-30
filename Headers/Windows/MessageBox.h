#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <Windows.h>
#include<WinUser.h>

namespace cms::Windows
{
	class MessageBox
	{
	public:
		static int Open(const char* description, const char* title, unsigned int type);
	};
}
#endif