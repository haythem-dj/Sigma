#pragma once

#include "Sigma/Core/Base.h"
#include "Sigma/Core/Log.h"
#include "Sigma/Core/Application.h"
#include "Sigma/Core/Window.h"

#include "Sigma/Input/KeyCodes.h"
#include "Sigma/Input/MouseButtons.h"
#include "Sigma/Input/Input.h"

#include "Sigma/ECS/Components.h"
#include "Sigma/ECS/Entity.h"
#include "Sigma/ECS/Scene.h"

#include "Sigma/Renderer/ShaderProgram.h"
#include "Sigma/Renderer/Texture.h"
#include "Sigma/Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtx/rotate_vector.hpp>
#include <GLM/gtc/type_ptr.hpp>