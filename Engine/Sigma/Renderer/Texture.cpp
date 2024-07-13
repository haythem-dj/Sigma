#include "Texture.h"

#include <iostream>

#include <glad/glad.h>
#include <stb_image.h>

namespace Sigma
{
	Texture::Texture()
	{
		
	}

	Texture::Texture(const char* path, int target, int slot, int pixelType)
	{
		Load(path, target, slot, pixelType);
	}

	Texture::~Texture()
	{}

	void Texture::Load(const char* path, int target, int slot, int pixelType)
	{
		mTarget = target;
		mSlot = slot;

		glGenTextures(1, &mID);
		Bind();

		glTexParameteri(mTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(mTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(mTarget, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(mTarget, GL_TEXTURE_WRAP_T, GL_REPEAT);

		int width, height, chanels;
		unsigned char* data = stbi_load(path, &width, &height, &chanels, 0);

		int format = (chanels == 3) ? GL_RGB : GL_RGBA;
		if(data)
			glTexImage2D(mTarget, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		else std::cout << "Faild to load image '" << path << "'" << std::endl;

		glGenerateMipmap(mTarget);

		stbi_image_free(data);

		Unbind();
	}

	void Texture::Bind() const
	{
		glActiveTexture(mSlot);
		glBindTexture(mTarget, mID);
	}

	void Texture::Unbind() const
	{
		glBindTexture(mTarget, 0);
	}

	void Texture::Delete()
	{
		glDeleteTextures(1, &mID);
	}
}
