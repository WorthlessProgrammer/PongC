#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#define WIDTH 800
#define HEIGTH 200

int main(int argc, char **argv)
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: Could not load GLFW3");
	}
	return 0;
}

