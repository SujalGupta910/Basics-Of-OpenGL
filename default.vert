#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTex;

out vec3 currPos;
out vec3 Normal;
out vec2 texCoord;


//uniform float scale;
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 proj;

uniform mat4 camMatrix;
uniform mat4 model;

void main()
{	
	currPos = vec3(model * vec4(aPos,1.0f));

	//gl_Position = proj * view * model * vec4(aPos,1.0);
	Normal=aNormal;
	texCoord=aTex;
	gl_Position = camMatrix * vec4(currPos,1.0);


}