#pragma once
#include "common.h"

class Texture
{
private:
	unsigned int m_textureID;
	std::string m_filePath;
	unsigned char* m_buffer;
	int m_width, m_height, m_BPP;
	unsigned int m_slot;
public:
	Texture();
	Texture(const std::string& path);
	~Texture();
	void Load(const std::string& path);
	void Bind(unsigned int slot = 0);
	void Unbind();
	unsigned int GetSlot()
	{
		return m_slot;
	}


};

