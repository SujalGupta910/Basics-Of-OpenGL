#include"Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Camera::position = position;

}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);
	camMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
	
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(camMatrix));
}

void Camera::Inputs(GLFWwindow* window)
{
	if (GLFW_PRESS==glfwGetKey(window, GLFW_KEY_UP))
	{
		position += speed * orientation;
	}
	if (GLFW_PRESS == glfwGetKey(window,GLFW_KEY_LEFT))
	{
		position += speed * -glm::normalize(glm::cross(orientation,up));
	}
	if (GLFW_PRESS == glfwGetKey(window,GLFW_KEY_DOWN))
	{
		position += speed * -orientation;
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_RIGHT))
	{
		position += speed * glm::normalize(glm::cross(orientation, up));
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_SPACE))
	{
		position += speed * up;
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT_CONTROL))
	{
		position += speed * -up;
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT_SHIFT))
	{
		speed = 0.04f;
	}
	else if (glfwGetKey(window, GLFW_KEY_SPACE)==GLFW_RELEASE)
	{
		speed = 0.01f;
	}

	//mouse controls

	if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);


		if(firstClick == true)
		{
			glfwSetCursorPos(window, (height / 2), (width / 2));
			firstClick = false;
		}

		double mouseX,mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));

		if (!(( glm::angle(newOrientation, up) <= glm::radians(5.0f) ) or ( glm::angle(newOrientation, -up) <= glm::radians(5.0f) )))
		{
			orientation = newOrientation;
		}
		orientation = glm::rotate(orientation, glm::radians(-rotY), up);

		glfwSetCursorPos(window, (height / 2), (width / 2));

	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}








}




















