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
#define RECT_TOP_LEFT_X RECT_OFFSET - 1
#define RECT_TOP_LEFT_Y 1
#define RECT_WIDTH 0.075
#define RECT_LENGTH 0.5
 
void keyboard_handler(unsigned char key, int x, int y)
{
	(void) x;
	(void) y;

    if (key == (unsigned char) 'q')
	{
        exit(0);
	}
}

void display() 
{ 
 
    glClearColor(0, 0, 0, 1);  // (In fact, this is the default.)
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); // red 
    glVertex2f(RECT_TOP_LEFT_X, RECT_TOP_LEFT_Y);
    glColor3f(0, 1, 0); // green
    glVertex2f(RECT_TOP_LEFT_X + RECT_WIDTH, RECT_TOP_LEFT_Y);
    glColor3f(0, 0, 1); // blue
	glVertex2f(RECT_TOP_LEFT_X + RECT_WIDTH, RECT_TOP_LEFT_Y - RECT_LENGTH);
    glColor3f(1, 1, 1); // all
	glVertex2f(RECT_TOP_LEFT_X, RECT_TOP_LEFT_Y - RECT_LENGTH); 
	glEnd(); 
    	
    glutSwapBuffers(); // Required to copy color buffer onto the screen.
}

int main(int argc, char** argv) 
{										  
    glutInit(&argc, argv);               // Initialize GLUT and
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(WIDTH, HEIGHT);   // Size of display area, in pixels.
    glutInitWindowPosition(WIN_POS_X, WIN_POS_Y);     // Location of window in screen coordinates.
    glutCreateWindow("PongC");           // Parameter is window title. 
	glutDisplayFunc(display);            // Called when the window needs to be redrawn.
	glutKeyboardFunc(keyboard_handler);

	glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
	return 0;
}

