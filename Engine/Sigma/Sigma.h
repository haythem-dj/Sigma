#pragma once

#ifndef GLM_ENABLE_EXPERIMENTAL
	#define GLM_ENABLE_EXPERIMENTAL
#endif

#ifndef STB_IMAGE_IMPLEMENTATION
	#define STB_IMAGE_IMPLEMENTATION
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtx/rotate_vector.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include "Core/Application.h"
#include "Core/Window.h"
#include "Core/Camera.h"

#include "Input/KeyCodes.h"
#include "Input/MouseButtons.h"
#include "Input/Input.h"

#include "ECS/Entity.h"
#include "ECS/Scene.h"

#include "Renderer/ShaderProgram.h"
#include "Renderer/Texture.h"
#include "Renderer/Renderer.h"
