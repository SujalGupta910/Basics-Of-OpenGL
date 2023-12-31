#include"Texture.h"

Texture::Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType)
{
	type = texType;


	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//float flatColor[] = { 1.0f,1.0f,1.0f,0.5f };
	//glTexParameterfv(GL_TEXTURE_2D,GL_TEXTURE_BORDER_COLOR,flatColor); 

	int widthImg, heightImg, numColCh;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* imgBytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	if (imgBytes)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, imgBytes);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "failed" << std::endl;
	}


	stbi_image_free(imgBytes);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID); 
}

void Texture::Unbind()
{ 
	glBindTexture(GL_TEXTURE_2D,0); 
}

void Texture::Delete()
{ 
	glDeleteTextures(1, &ID); 
}

