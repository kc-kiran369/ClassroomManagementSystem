#ifndef CMS_IMAGE_H
#define CMS_IMAGE_H

#include<Windows.h>
#include<glfw/glfw3.h>
#include<fstream>

#include "stb_image.h"
#include "Windows/MessageBox.h"

namespace cms::Data
{
	class Image
	{
	private:
		UINT m_Texture;
		UINT m_Width, m_Height, m_Channel;
	public:
		Image(const char* path);
		void Load(const char* path);

		UINT GetWidth();
		UINT GetHeight();
		UINT GetChannel();
		UINT GetID();
	};
}

#endif