#version 330 core

layout(location = 0) in vec3 iPos;
layout(location = 1) in vec3 iNormal;
layout(location = 2) in vec2 iTexCoords;

out vec3 Normal;
out vec2 TexCoords;
out vec3 Position;

uniform mat4 transform;
uniform mat4 proj_view;

void main()
{
	Normal = iNormal;
	TexCoords = iTexCoords;
	Position = vec3(transform * vec4(iPos, 1.0));
	gl_Position = proj_view * vec4(Position, 1.0);
}
