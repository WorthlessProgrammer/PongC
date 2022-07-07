#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGTH 200

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: Could not load GLFW3\n");
		return -1;
	}
	return 0;
}

