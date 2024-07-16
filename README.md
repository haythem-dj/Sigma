# Sigma
The Sigma Engine is a 3D game engine with no editor.
# building
In order to build Sigma you need to have premake5 installed.
You can get it from [here](https://premake.github.io/)
Premake supports many IDEs and compilers ([look  here](https://premake.github.io/docs/Using-Premake))
You can generate project files for IDEs like Visual Studio or Makefiles for gcc or clang
### example(make)
```bash
premake5 gmake
make CC=gcc config=release
```
### example( Visual Studio)
```bash
premake5 vs2022
```
It will generate Visual Studio 2022 solution and project files
# Platforms
Currently Sigma supports only Windows x64
# Code example
``` c++
#include <sigma.h>
#include <Sigma/Core/EntryPoint.h>

class App : public Sigma::Application
{
public:
	App()
	{
		SetWidth(mWidth);
		SetHeight(mHeight);

		SetBackgroundColor({0.2f, 0.1f, 0.7f});
	}
	~App()
	{}

private:
	unsigned int mWidth = 1080;
	unsigned int mHeight = 608;

};

Sigma::Application* Sigma::CreateApplication()
{
	return new App();
}

```
