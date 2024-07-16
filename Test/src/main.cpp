#include <Sigma.h>
#include <Sigma/Core/EntryPoint.h>

#include "App.h"

Sigma::Application* Sigma::CreateApplication()
{
	return new App();
}
