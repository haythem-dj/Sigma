#version 330 core

layout(location = 0) in vec3 iPos;
layout(location = 1) in vec3 iNormal;
layout(location = 2) in vec2 iTexCoords;

out vec3 Normal;
out vec2 TexCoords;
out vec3 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	Normal = iNormal;
	TexCoords = iTexCoords;
	Position = vec3(model * vec4(iPos, 1.0));
	gl_Position = proj * view * vec4(Position, 1.0);
}