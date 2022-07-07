#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGTH 200

int main(void)
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: Could not load GLFW3\n");
		return -1;
	}

	GLFWwindow* window;
	window = glfwCreateWindow(WIDTH, HEIGTH, "PongC", NULL, NULL);

	glfwMakeContextCurrent(window);
	

	while(true)
	{
		glfwSwapBuffers(window);
	}

	return 0;
}

