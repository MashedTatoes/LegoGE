#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION

#include "stb/stb_image.h"

namespace LGE
{


	Texture::Texture() : m_textureID(0), m_filePath(""), m_buffer(nullptr), m_width(0), m_height(0), m_BPP(0)
	{

		m_settings = m_settings | ImageSettings::LinearFilter;

		glGenTextures(1, &m_textureID);
		stbi_set_flip_vertically_on_load(1);
		Bind();


	}

	Texture::Texture(const std::string& path) : Texture()
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		Load(path);
		Unbind();

		if (m_buffer)
		{

			stbi_image_free(m_buffer);
		}

	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_textureID);

	}

	void Texture::Load(const std::string& path)
	{

		if ((m_settings & ImageSettings::LinearFilter) == ImageSettings::LinearFilter)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		}



		m_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer);


	}

	void Texture::Bind(unsigned int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		m_slot = slot;
		glBindTexture(GL_TEXTURE_2D, m_textureID);

	}

	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);

	}

	void Texture::Reload()
	{
		Bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		Load(m_filePath);
		Unbind();

		if (m_buffer)
		{

			stbi_image_free(m_buffer);
		}
	}

	void Texture::ToggleFlag(ImageSettings setting)
	{

		m_settings = m_settings ^ setting;

	}

}
