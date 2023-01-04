#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <Windows.h>
#include<WinUser.h>
#include"Core/Serializer.h"

namespace cms::Windows
{
	class PromptBox
	{
	public:

		///<summary>
		///Opens the message window with the description &amp; title provided.
		///</summary>
		static int Open(const char* description, const char* title, unsigned int type);

		///<summary>
		///Opens the message window with the description provided but title is set same as application name.
		///</summary>
		static int Open(const char* description, unsigned int type);
	};
}
#endif