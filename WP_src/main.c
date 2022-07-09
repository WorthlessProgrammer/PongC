#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/freeglut.h>   
#include <GL/freeglut_std.h>

#define WIDTH 800
#define HEIGHT 600

#define WIN_POS_X 100
#define WIN_POS_Y 100

#define RECT_OFFSET 0.03f
#define RECT_TOP_LEFT_X (RECT_OFFSET - 1)
#define RECT_TOP_LEFT_Y 1
#define RECT_WIDTH 0.035f
#define RECT_LENGTH 0.5f
#define RECT_STEP 0.1f

#define BALL_CX 0.0f
#define BALL_CY 0.0f
#define BALL_RAD 0.5f
#define PI 3.1415926f

#define FPS 1000 / 60

typedef struct {
	float cx;
	float cy;
	float r;
} Ball;

typedef struct {
	float x;
	float y;
	float width;
	float length;
} Rectangle;

Ball make_ball(float x, float y, float radius)
{
	Ball b = {
		.cx = x,
		.cy = y,
		.r  = radius
	};

	return b;
}

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

void drawFilledSun()
{
    //static float angle;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    int i, x, y;
    double radius = 0.30;
    //glColor3ub(253, 184, 19);     
    glColor3ub(255, 0, 0);
    double twicePi = 2.0 * 3.142;
    x = 0, y = 0;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END
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

static float lrect_y = RECT_TOP_LEFT_Y;
static float rrect_y = RECT_TOP_LEFT_Y;
void display2() 
{ 
    glClearColor(0, 0, 0, 1);  
    glClear(GL_COLOR_BUFFER_BIT);

    Rectangle r = make_rect(RECT_TOP_LEFT_X, lrect_y);
    Rectangle l = make_rect(-1.0f*RECT_TOP_LEFT_X - RECT_WIDTH, rrect_y); 

	/* Ball b = make_ball(BALL_CX, BALL_CY, BALL_RAD); */

    render_rect_uniform_color(r);
    render_rect_uniform_color(l);

    glutSwapBuffers(); 
}

void display()
{
    glClearColor(0, 0, 0, 1);  
    glClear(GL_COLOR_BUFFER_BIT);

	drawFilledSun();
}

float clampf(float a)
{
	if (a > 1.0f) return 1.0f;
	if (a - RECT_LENGTH < -1.0f) return -1.0f + RECT_LENGTH;
	return a;
}

void keyboard_handler(unsigned char key, int x, int y)
{
    (void) x;
    (void) y;

    switch (key) 
    {
		case 'q': {exit(0); break;} //quit
		case 's': {lrect_y = clampf(lrect_y - RECT_STEP); break;} //S
		case 'w': {lrect_y = clampf(lrect_y + RECT_STEP); break;} //w
		case 'd': {rrect_y = clampf(rrect_y - RECT_STEP); break;} //D
		case 'e': {rrect_y = clampf(rrect_y + RECT_STEP); break;} //E
		default: break;
    }
	
    glutPostRedisplay();
}

int main(int argc, char** argv) 
{										  
    glutInit(&argc, argv);			    // Initialize GLUT and
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(WIDTH, HEIGHT);		    // Size of display area, in pixels.
    glutInitWindowPosition(WIN_POS_X, WIN_POS_Y);   // Location of window in screen coordinates.
    glutCreateWindow("PongC");			    // Parameter is window title. 
    glutDisplayFunc(display);			    // Called when the window needs to be redrawn.
    glutKeyboardFunc(keyboard_handler);

    glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
    return 0;
}

