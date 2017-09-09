#include <glew\glew.h>
#include "Win.h"
#include  <iostream>
#include "RenderSystem.h"
namespace Basic {
	Win* Win::m_Inst(0);
	Win* Win::Inst() {
		if (!m_Inst)
			m_Inst = new Win();
		return m_Inst;
	}

	bool Win::createWindow(const int& width, const int& height, const char* name)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glViewport(0, 0, width, height);
		window = glfwCreateWindow(width, height, name, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(window);
		//初始化glew
		glewExperimental = GL_TRUE;
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL Error: " << error << std::endl;
		}
		GLenum glewinit = glewInit();
		if (glewinit != GLEW_OK) {
			std::cout << "Glew not okay! " << glewinit;
			exit(EXIT_FAILURE);
		}

		//glfwSetMouseButtonCallback(onMouseButton);
		//glfwSetMousePosCallback(onMouseMoveLeft);
		//glfwSetMouseButtonCallback(onMouseButtonRight);
		//glfwSetMousePosCallback(onMouseMoveRight);
		
		//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		//glfwSetCursorPosCallback(window, mouse_callback);
		//glfwSetScrollCallback(window, scroll_callback);
		return true;
	}
	//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	//{
	//	InputManager * in_manager = InputManager::get_instance();
	//	in_manager->handle_key_press(params)
	//}
	void Win::onMouseButton(int button, int action)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{

		}
		else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
		{

		}
		else
		{

		}
	}
	void Win::starup(RenderParams* params)
	{
		while (!glfwWindowShouldClose(window))
		{
			//我希望这里应该有个整个场景的update，加入场景中的entity必须重载update?
			float currentFrame = glfwGetTime();
			RenderSystem::RenderSystem::Inst()->beginRender();
			RenderSystem::RenderSystem::Inst()->render(params);
			RenderSystem::RenderSystem::Inst()->endRender();
			//deltaTime = currentFrame - lastFrame;
			//lastFrame = currentFrame;
		
			
			//processInput(window);
			
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

	}
}