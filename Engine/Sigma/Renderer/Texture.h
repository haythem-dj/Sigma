#pragma once

namespace Sigma
{
	class Texture
	{
	public:
		Texture();
		Texture(const char* path, int target, int slot, int pixelType);
		~Texture();

		void Load(const char* path, int target, int slot, int pixelType);

		void Bind() const;
		void Unbind() const;
		void Delete();

	private:
		unsigned int mID = 0;
		int mTarget = 0;
		int mSlot = 0;
		
	};
}
