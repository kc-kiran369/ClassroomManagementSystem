#include"Data/Image.h"

cms::Data::Image::Image(const char* path)
{
	Load(path);
}

void cms::Data::Image::Load(const char* path)
{
	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	BYTE* data = stbi_load(path, (int*)&m_Width, (int*)&m_Height, (int*)&m_Channel, 0);

	glTexImage2D(GL_TEXTURE_2D, 0, (m_Channel == 3 ? GL_RGB : GL_RGBA), m_Width, m_Height, 0, (m_Channel == 3 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, data);

	if (data)
		stbi_image_free(data);
	else
		cms::Windows::PromptBox::Open("Image didn't open", MB_OK | MB_ICONEXCLAMATION);
}

UINT cms::Data::Image::GetWidth()
{
	return m_Width;
}

UINT cms::Data::Image::GetHeight()
{
	return m_Height;
}

UINT cms::Data::Image::GetChannel()
{
	return m_Channel;
}

UINT cms::Data::Image::GetID()
{
	return m_Texture;
}
