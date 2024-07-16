#version 330 core

in vec3 Normal;
in vec2 TexCoords;
in vec3 Position;

out vec4 FragColor;

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

uniform Material material;

void main()
{
	FragColor = texture(material.diffuse, TexCoords);
}
