#include"Mesh.h"


using namespace std;
using namespace glm;

const unsigned int width = 800;
const unsigned int height = 800;



Vertex vertices[] =
{
	//front face							/normals			 //texture coords
	Vertex{vec3(-0.5f,-0.5f,  0.5f), vec3(0.0f, 0.0f, 1.0f) , vec2(0.0f,0.0f)},   // 0
	Vertex{vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 1.0f) , vec2(1.0f,0.0f)}, //1
	Vertex{vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 1.0f) , vec2(1.0f,1.0f)}, //2
	Vertex{vec3(-0.5f, 0.5f,  0.5f), vec3(0.0f, 0.0f, 1.0f) , vec2(0.0f,1.0f)}, //3
	//back face
	Vertex{vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, -1.0f) , vec2(1.0f,0.0f)}, //4
	Vertex{vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, -1.0f) , vec2(0.0f,0.0f)}, //5
	Vertex{vec3(0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, -1.0f) , vec2(0.0f,1.0f)}, //6
	Vertex{vec3(-0.5f, 0.5f, -0.5f), vec3(0.0f, 0.0f, -1.0f) , vec2(1.0f,1.0f)}, //7
	//left face
	Vertex{vec3(-0.5f,  -0.5f,  -0.5f), vec3(-1.0f, 0.0f,  0.0f),  vec2(0.0f,0.0f)},  //8
	Vertex{vec3(-0.5f, -0.5f,  0.5f),   vec3(-1.0f, 0.0f,  0.0f),  vec2(1.0f,0.0f)},  //9
	Vertex{vec3(-0.5f,  0.5f,  0.5f),   vec3(-1.0f, 0.0f,  0.0f),  vec2(1.0f,1.0f)},  //10
	Vertex{vec3(-0.5f,   0.5f,  -0.5f), vec3(-1.0f, 0.0f,  0.0f),  vec2(0.0f,1.0f)},  //11
	//right face
	Vertex{vec3(0.5f,  -0.5f,  -0.5f),  vec3(1.0f, 0.0f,  0.0f) ,vec2(0.0f,0.0f)},  //12
	Vertex{vec3(0.5f, -0.5f,  0.5f), vec3(1.0f, 0.0f,  0.0f) ,	   vec2(1.0f,0.0f)},  //13
	Vertex{vec3(0.5f, 0.5f,  0.5f), vec3(1.0f, 0.0f,  0.0f) , vec2(1.0f,1.0f)},  //14
	Vertex{vec3(0.5f,   0.5f,  -0.5f), vec3(1.0f, 0.0f,  0.0f) ,  vec2(0.0f,1.0f)},  //15
	//top face
	Vertex{vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f, 1.0f, 0.0f) ,vec2(0.0f,1.0f)},   //16
	Vertex{vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 1.0f, 0.0f) ,vec2(1.0f,1.0f)},   //17
	Vertex{vec3(0.5f,   0.5f,  -0.5f),  vec3(0.0f, 1.0f, 0.0f) ,vec2(1.0f,0.0f)},   //18
	Vertex{vec3(-0.5f,   0.5f,  -0.5f),  vec3(0.0f, 1.0f, 0.0f) ,vec2(0.0f,0.0f)},   //19
	//bottom face
	Vertex{vec3(-0.5f,  -0.5f,  -0.5f), vec3(0.0f, -1.0f, 0.0f),vec2(0.0f,1.0f)},   //20
	Vertex{vec3(0.5f,  -0.5f,  -0.5f), vec3(0.0f, -1.0f, 0.0f),vec2(1.0f,1.0f)},   //21
	Vertex{vec3(0.5f, -0.5f,  0.5f),vec3(0.0f, -1.0f, 0.0f),vec2(1.0f,0.0f)},   //22
	Vertex{vec3(-0.5f, -0.5f,  0.5f),vec3(0.0f, -1.0f, 0.0f),vec2(0.0f,0.0f)}    //23
};


GLuint indices[] = {
	// Front face
	0, 1, 2,
	2, 3, 0,
	// Back face
	4, 5, 6,
	6, 7, 4,
	// Left face
	8, 9, 10,
	10, 11, 8,
	// Right face
	12, 13, 14,
	14, 15, 12,
	// Top face
	16,17,18,
	18,19,16,
	// Bottom face
	20,21,22,
	22,23,20
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{vec3(-0.3f,-0.3f,0.3f)},
	Vertex{vec3(-0.3f,-0.3f,-0.3f)},
	Vertex{vec3(0.3f,-0.3f,-0.3f)},
	Vertex{vec3(0.3f,-0.3f,0.3f)},
	Vertex{vec3(-0.3f,0.3f,0.3f)},
	Vertex{vec3(-0.3f,0.3f,-0.3f)},
	Vertex{vec3(0.3f,0.3f,-0.3f)},
	Vertex{vec3(0.3f,0.3f,0.3f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};


int main()
{
	//findNormals();
	//initialising glfw
	glfwInit();

	
	//creates a window named opengl
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);

	//providing opengl version hints to gl(glfwCreateWindow returns null when it is before the createwindow line smh)

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//error checking
	if (window == NULL)
	{
		cout << "Failed to make a window\n";
		glfwTerminate();
		return -1;
	}
	//need this to use the window we created
	glfwMakeContextCurrent(window);

	//used for coloring
	gladLoadGL();

	glViewport(0, 0, width, height); //from bottom left of the screen to the top right

	Texture textures[] =
	{
		Texture("planks.png","diffuse",0,GL_RGBA,GL_UNSIGNED_BYTE),
		Texture("planksSpec.png","specular",1,GL_RED,GL_UNSIGNED_BYTE)
	};

	Shader shaderProgram("default.vert", "default.frag");

	vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

	Mesh floor(verts, ind, tex);

	Shader lightShader("light.vert", "light.frag");
	vector<Vertex> lightverts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));

	Mesh light(lightverts, lightInd, tex);

	vec4 lightColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	vec3 lightPos = vec3(0.0,0.0f,0.0f);
	mat4 lightModel = mat4(1.0f);
	lightModel = translate(lightModel, lightPos);
	lightModel = scale(lightModel, vec3(0.5f, 0.5f, 0.5f));


	vec3 objectPos = vec3(0.0f, 0.0f, 0.0f);
	mat4 objectModel = mat4(1.0f);
	objectModel = translate(objectModel, objectPos);
	objectModel = scale(objectModel, vec3(2.0f, 2.0f, 2.0f));

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	
	
	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height, vec3(0.0f, 0.0f, 2.0f));

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);
		
		floor.Draw(shaderProgram,camera);
		light.Draw(lightShader,camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();
	lightShader.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}