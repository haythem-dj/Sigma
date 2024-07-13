#include <Sigma.h>
#include <Core/EntryPoint.h>

#include "App.h"

Sigma::Application* Sigma::CreateApplication()
{
	return new App();
}
