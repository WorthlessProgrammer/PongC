#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGTH 600

//check OpenGL ERROR code.
void cglec(int code)
{
	if (code < 0)
	{
		fprintf(stderr, "ERROR");
		exit(1);
	}
}

//check OpenGL pointer.
void *cglp(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "ERROR");
		exit(1);
	}
	return ptr;
}

int main(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Queremos OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: Could not load GLFW3\n");
		exit(1);
	}

	GLFWwindow* window;
	window = cglp(glfwCreateWindow(WIDTH, HEIGTH, "PongC", NULL, NULL));
	
	glfwMakeContextCurrent(window);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	bool quit = false;
	while(!quit)
	{
		glfwSwapBuffers(window);
		glfwPollEvents();

		quit = glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS; 
	}

	glfwTerminate();
	return 0;
}
