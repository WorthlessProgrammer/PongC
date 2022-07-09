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

Rectangle make_left_rect()
{
	Rectangle r = {
		.x = RECT_TOP_LEFT_X,  
		.y = RECT_TOP_LEFT_Y,
		.width = RECT_WIDTH,
		.length = RECT_LENGTH
	};
	
	return r;
}

Rectangle make_right_rect()
{
	Rectangle r = {
		.x = -1.0f*RECT_TOP_LEFT_X - RECT_WIDTH,   
		.y = RECT_TOP_LEFT_Y,
		.width = RECT_WIDTH,
		.length = RECT_LENGTH
	};
	
	return r;
}

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

	Rectangle r = make_left_rect();
	Rectangle l = make_right_rect(); 

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); // red 
    glVertex2f(r.x, r.y);
    glColor3f(0, 1, 0); // green
    glVertex2f(r.x + r.width, r.y);
    glColor3f(0, 0, 1); // blue
	glVertex2f(r.x + r.width, r.y - r.length);
    glColor3f(1, 1, 1); // all
	glVertex2f(r.x, r.y - r.length); 
	glEnd(); 
	printf("%f\n", l.x);

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); // red 
    glVertex2f(l.x, l.y);
    glColor3f(0, 1, 0); // green
    glVertex2f(l.x + l.width, l.y);
    glColor3f(0, 0, 1); // blue
	glVertex2f(l.x + l.width, l.y - l.length);
    glColor3f(1, 1, 1); // all
	glVertex2f(l.x, l.y - l.length); 
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

