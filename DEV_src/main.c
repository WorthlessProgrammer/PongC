#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <GL/gl.h>
#include <GL/freeglut.h>   
#include <GL/freeglut_std.h>

#define WIDTH 960
#define HEIGHT 540

#define WIN_POS_X 250
#define WIN_POS_Y 250

#define RECT_OFFSET 0.03
#define RECT_TOP_LEFT_X RECT_OFFSET - 1
#define RECT_TOP_LEFT_Y 1
#define RECT_WIDTH 0.035
#define RECT_LENGTH 0.5
 
//float posX = RECT_TOP_LEFT_X + RECT_WIDTH/2, posY = RECT_TOP_LEFT_Y / RECT_LENGTH/2;
float posX = 0, posY = 0;
//posZ = 0;
float move_unit = 0.1f; //move

void keyboardown(int key, int x, int y)
{
	(void) x;
	(void) y;

    switch (key){
        case GLUT_KEY_UP:
			if (posY + 1 + move_unit <= 1)
				posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
			if (posY + RECT_LENGTH >= -1)
				posY-=move_unit;
        break;

        default:
         break;
    }
    glutPostRedisplay();
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

void rect()
{ 
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0); // green
    glVertex2f(RECT_TOP_LEFT_X, RECT_TOP_LEFT_Y);
    glVertex2f(RECT_TOP_LEFT_X + RECT_WIDTH, RECT_TOP_LEFT_Y);
	glVertex2f(RECT_TOP_LEFT_X + RECT_WIDTH, RECT_TOP_LEFT_Y - RECT_LENGTH);
	glVertex2f(RECT_TOP_LEFT_X, RECT_TOP_LEFT_Y - RECT_LENGTH); 
	glEnd(); 
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, 0);
	rect();
	glPopMatrix();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
}

int main(int argc, char** argv) 
{										  
    glutInit(&argc, argv);               // Initialize GLUT and
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(WIDTH, HEIGHT);   // Size of display area, in pixels.
    glutInitWindowPosition(WIN_POS_X, WIN_POS_Y);     // Location of window in screen coordinates.
    glutCreateWindow("PongC");           // Parameter is window title. 
	glutDisplayFunc(display);            // Called when the window needs to be redrawn.
	init();
	glutSpecialFunc(keyboardown);
	glutKeyboardFunc(keyboard_handler);
	glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
	return 0;
}

