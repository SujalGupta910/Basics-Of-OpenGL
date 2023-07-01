#version 330 core
out vec4 FragColor;

in vec3 currPos;
in vec3 Normal;
in vec2 texCoord;

uniform sampler2D diffuse0;
uniform sampler2D specular0;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;


void main()
{
	float ambient = 0.2f;

	vec3 normal = normalize(Normal);
	vec3 lightDir = normalize(lightPos - currPos);
	float diffuse = max(dot(normal,lightDir),0.0f);

	float specularLight = 0.50f;
	vec3 viewDir = normalize(camPos - currPos);
	vec3 reflectionDir = reflect(-lightDir,normal);
	float specAmount = pow(max(dot(viewDir,reflectionDir),0.0f),16);
	float specular = specAmount * specularLight;

	FragColor = texture(diffuse0,texCoord) * lightColor * (diffuse + ambient) + texture(specular0,texCoord).r * specular;
}