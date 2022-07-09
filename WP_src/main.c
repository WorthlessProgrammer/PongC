#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <GL/gl.h>
#include <GL/freeglut.h>   
#include <GL/freeglut_std.h>

#define WIDTH 800
#define HEIGHT 600

#define WIN_POS_X 100
#define WIN_POS_Y 100

#define RECT_OFFSET 0.05
#define RECT_TOP_LEFT_X (RECT_OFFSET - 1)
#define RECT_TOP_LEFT_Y 1
#define RECT_WIDTH 0.075
#define RECT_LENGTH 0.5

typedef struct {
	float x;
	float y;
	float width;
	float length;
} Rectangle;

Rectangle make_rect(float tl_x, float tl_y)
{
	Rectangle r = {
		.x = tl_x,  
		.y = tl_y,
		.width = RECT_WIDTH,
		.length = RECT_LENGTH
	};
	
	return r;
}

void keyboard_handler(unsigned char key, int x, int y)
{
	(void) x;
	(void) y;

	switch (key) 
	{
		case 113: {exit(0); break;} //q
		case 115: {exit(0); break;} //w
		case 119: {exit(0); break;} //s
		default: break;
	}
}

void render_rect_uniform_color(Rectangle rect)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0); // green
	glVertex2f(rect.x, rect.y);
    glVertex2f(rect.x + rect.width, rect.y);
	glVertex2f(rect.x + rect.width, rect.y - rect.length);
	glVertex2f(rect.x, rect.y - rect.length); 
	glEnd(); 
}

void display() 
{ 
    glClearColor(0, 0, 0, 1);  
    glClear(GL_COLOR_BUFFER_BIT);

	Rectangle r = make_rect(RECT_TOP_LEFT_X, RECT_TOP_LEFT_Y);
	Rectangle l = make_rect(-1.0f*RECT_TOP_LEFT_X - RECT_WIDTH, RECT_TOP_LEFT_Y); 
    
	render_rect_uniform_color(r);
	render_rect_uniform_color(l);

	glutSwapBuffers(); 
}

int main(int argc, char** argv) 
{										  
    glutInit(&argc, argv);				            // Initialize GLUT and
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(WIDTH, HEIGHT);			    // Size of display area, in pixels.
    glutInitWindowPosition(WIN_POS_X, WIN_POS_Y);   // Location of window in screen coordinates.
    glutCreateWindow("PongC");						// Parameter is window title. 
	glutDisplayFunc(display);						// Called when the window needs to be redrawn.
	glutKeyboardFunc(keyboard_handler);

	glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
	return 0;
}

