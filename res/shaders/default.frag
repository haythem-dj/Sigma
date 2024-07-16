#version 330 core

in vec3 Normal;
in vec2 TexCoords;
in vec3 Position;

out vec4 FragColor;

#define MAX_LIGHTS 128

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct DirLight
{
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight
{
	vec3 position;

	float a, b, c;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct SpotLight
{
	vec3 position;
	vec3 direction;

	float a, b, c;

	float cutOff;
	float outerCutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform int numDirLight;
uniform int numPointLight;
uniform int numSpotLight;

uniform DirLight[MAX_LIGHTS] dirLights;
uniform PointLight[MAX_LIGHTS] pointLights;
uniform SpotLight[MAX_LIGHTS] spotLights;

uniform vec3 view_pos;
uniform Material material;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewDir);

void main()
{
	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(view_pos - Position);

	vec3 result = vec3(0.0);

	for (int i = 0; i < numDirLight; i++)
		result += CalcDirLight(dirLights[i], norm, viewDir);

	for (int i = 0; i < numPointLight; i++)
		result += CalcPointLight(pointLights[i], norm, viewDir);

	for (int i = 0; i < numSpotLight; i++)
		result += CalcSpotLight(spotLights[i], norm, viewDir);

	FragColor = vec4(result, 1.0);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDirection = normalize(-light.direction);

	float diff = max(dot(normal, lightDirection), 0.0);

	vec3 reflectDir = reflect(-lightDirection, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

	return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDirection = normalize(light.position - Position);

	float diff = max(dot(normal, lightDirection), 0.0);

	vec3 reflectDir = reflect(-lightDirection, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	float distance = length(light.position - Position);
	float attenuation = 1.0/ (light.a * distance * distance + light.b * distance + light.c);

	vec3 ambient = attenuation * light.ambient * vec3(texture(material.diffuse, TexCoords));
	vec3 diffuse = attenuation * light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	vec3 specular = attenuation * light.specular * spec * vec3(texture(material.specular, TexCoords));

	return (ambient, diffuse, specular);
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDirection = normalize(light.position - Position);

	float theta = dot(lightDirection, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intencity = clamp((theta - light.outerCutOff)/epsilon, 0.0, 1.0);

	float diff = max(dot(normal, lightDirection), 0.0);

	vec3 reflectDir = reflect(-lightDirection, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	float distance = length(light.position - Position);
	float attenuation = 1.0/ (light.a * distance * distance + light.b * distance + light.c);

	vec3 ambient = attenuation * light.ambient * vec3(texture(material.diffuse, TexCoords));
	vec3 diffuse = intencity * attenuation * light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	vec3 specular = intencity * attenuation * light.specular * spec * vec3(texture(material.specular, TexCoords));

	return (ambient + diffuse + specular);
}