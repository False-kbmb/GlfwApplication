#include <stdio.h>
#include <Windows.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "RenderUtils.hpp"

#define iIiIiIiiIiIIiIiIIiIllIl main
using namespace std;

void KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
void MouseEvent(GLFWwindow* window, int button, int action, int mods);
boolean isInWindow(int mouseX, int mouseY, int windowX, int windowY, int windowWidth, int windowHeight);

bool isPressed = false;

int iIiIiIiiIiIIiIiIIiIllIl() {
	GLFWwindow* window;
	GLFWerrorfun errCallBack = NULL;
	double mouseX = NULL, mouseY = NULL;
	int winX = NULL, winY = NULL;
	int begin_mouse_posX = NULL, begin_mouse_posY = NULL, begin_window_posX = NULL, begin_window_posY = NULL;
	int deltaX = 0, deltaY = 0;

	if (!glfwInit())
	{
		throw "Glfw failed initialize";
		return -1;
	}

	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

	int width = 500, height = 500;
	float opacity = 255;
	window = glfwCreateWindow(width, height, "Sample", NULL, NULL);
	glfwSetWindowOpacity(window, opacity / 255);

	// 绑定事件
	glfwSetErrorCallback(errCallBack);
	glfwSetKeyCallback(window, KeyEvent);
	glfwSetMouseButtonCallback(window, MouseEvent);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	for (; !glfwWindowShouldClose(window);)
	{
		// Print mouse pos
		glfwGetCursorPos(window, &mouseX, &mouseY);
		glfwGetWindowPos(window, &winX, &winY);

		// 最难写的部分，透明窗口拖动判定
		if (!isPressed)
		{
			begin_mouse_posX = (int)mouseX + winX;
			begin_mouse_posY = (int)mouseY + winY;
			begin_window_posX = winX;
			begin_window_posY = winY;
		}

		deltaX = ((int)mouseX + winX - begin_mouse_posX);
		deltaY = ((int)mouseY + winY - begin_mouse_posY);

		if (isInWindow((int)mouseX + winX, (int)mouseY + winY, winX, winY, width, height) && isPressed && glfwGetWindowAttrib(window, GLFW_FOCUSED) == 1)
		{
			glfwSetWindowPos(window, begin_window_posX + deltaX, begin_window_posY + deltaY);
		}

		// Begin render
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();

		drawSineGraph(-10, 20, 255, 255, 255, 255);

		glPopMatrix();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void MouseEvent(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1) {
		isPressed = action == GLFW_PRESS;
		printf("Press!");
	}
}

boolean isInWindow(int mouseX, int mouseY, int windowX, int windowY, int windowWidth, int windowHeight) {
	// System.out.println("mouseX: " + mouseX + " mouseY: " + mouseY + " windowX: " + windowX + " windowY: " + windowY + " winWidth: " + windowWidth + " winHeight: " + windowHeight);
	return (((windowX < mouseX) && (mouseX < windowX + windowWidth)) && ((windowY < mouseY) && (mouseY < windowY + windowHeight)));
}
