#include <GL/freeglut_std.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <GL/gl.h>
#include <GL/freeglut.h>   

#define WIDTH 800
#define HEIGHT 600
 
void keyboard_handler(unsigned char key, int x, int y)
{
	(void) x;
	(void) y;

    if(key == (unsigned char) 'q')
	{
        exit(0);
	}
}

void display() {  
 
    glClearColor(0, 0, 0, 1);  // (In fact, this is the default.)
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0); // red
    glVertex2f(-0.8, -0.8);
    glColor3f(0, 1, 0); // green
    glVertex2f(0.8, -0.8);
    glColor3f(0, 0, 1); // blue
    glVertex2f(0, 0.9);
    glEnd(); 
    
    glutSwapBuffers(); // Required to copy color buffer onto the screen.
 
}


int main( int argc, char** argv ) {  // Initialize GLUT and 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(WIDTH, HEIGHT);   // Size of display area, in pixels.
    glutInitWindowPosition(100,100);     // Location of window in screen coordinates.
    glutCreateWindow("PongC");           // Parameter is window title.
    glutDisplayFunc(display);            // Called when the window needs to be redrawn.
	glutKeyboardFunc(keyboard_handler);

    glutMainLoop(); // Run the event loop!  This function does not return.
                    // Program ends when user closes the window.
    return 0;

}

