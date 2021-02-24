#pragma once
#include "common.h"
#include <type_traits>


namespace LGE
{
	enum class ImageSettings
	{
		LinearFilter = 1


	};

	inline ImageSettings operator | (ImageSettings a, ImageSettings b)
	{

		using T = std::underlying_type_t<ImageSettings>;
		return static_cast<ImageSettings>(static_cast<T>(a) | static_cast<T>(b));


	}

	inline ImageSettings operator & (ImageSettings a, ImageSettings b)
	{

		using T = std::underlying_type_t<ImageSettings>;
		return static_cast<ImageSettings>(static_cast<T>(a) & static_cast<T>(b));


	}

	inline ImageSettings operator ^ (ImageSettings a, ImageSettings b)
	{

		using T = std::underlying_type_t<ImageSettings>;
		return static_cast<ImageSettings>(static_cast<T>(a)^ static_cast<T>(b));


	}

	class Texture
	{

	public:
		

		

	private:
		unsigned int m_textureID;
		std::string m_filePath;
		unsigned char* m_buffer;
		int m_width, m_height, m_BPP;
		unsigned int m_slot;

		ImageSettings m_settings;

	public:



		Texture();
		Texture(const std::string& path);
		~Texture();
		void Load(const std::string& path);
		void Bind(unsigned int slot = 0);
		void Unbind();
		void Reload();
		unsigned int GetSlot()
		{
			return m_slot;
		}

		void ToggleFlag(ImageSettings setting);


	};


}

