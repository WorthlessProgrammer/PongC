#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/freeglut.h>   
#include <GL/freeglut_std.h>

#define WIDTH 960
#define HEIGHT 480

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
#define BALL_SPEED 0.007f
#define BALL_RAD 0.02f
#define BALL_DIR_X -1.0f
#define BALL_DIR_Y 0.0f
#define BALL_DEF 20
#define PI 3.1415926f

#define FPS 1000 / 60

typedef struct {
	float cx;
	float cy;
	float r;
	float velocity;
} Ball;

Ball make_ball(float bx, float by, float radius, float v)
{
	Ball b = {
		.cx = bx,
		.cy = by, 
		.r = radius,
		.velocity = v
	};

	return b;
}

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

void render_circle_uniform_color(Ball ball)
{
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 0);

	glVertex2f(ball.cx, ball.cy); // center of circle
	for(int i = 0; i <= BALL_DEF; i++) {
		glVertex2f(
			ball.cx + (BALL_RAD*cos(i * twicePi / BALL_DEF)),
			ball.cy + (BALL_RAD*2*sin(i * twicePi / BALL_DEF))
			);
	}
	glEnd();
}

static float circ_x = BALL_CX;
static float circ_y = BALL_CY;
static float circ_dx = BALL_DIR_X;
static float circ_dy = BALL_DIR_Y;

static float lrect_y = RECT_TOP_LEFT_Y;
static float rrect_y = RECT_TOP_LEFT_Y;

void circ_mv(Ball b)
{
	/* static bool is_left = false; */
	/* static bool is_right = true; */

	/* if (circ_x - BALL_RAD <= -1.0f) */ 
	/* { */
	/*	circ_x -= BALL_SPEED*b.dir_x; */
	/*	is_left = true; */
	/* } */
	/* if (circ_x + BALL_RAD >= 1.0f) */
	/* { */
	/*	circ_x += BALL_SPEED*b.dir_x; */
	/*	is_right = true; */
	/* } */
	/* if (circ_y + BALL_RAD >= 1.0f) circ_y -= BALL_SPEED; */
	/* if (circ_y - BALL_RAD <= -1.0f) circ_y += BALL_SPEED; */
	/* if (!is_right) circ_x += BALL_SPEED; */
	/* else if (is_right && !is_left) circ_x -= BALL_SPEED; */
	/* else */
	/* { */
	/*	is_left = false; */ 
	/*	is_right = false; */	
	/* } */

	circ_x += circ_dx*b.velocity;	
	circ_y += circ_dy*b.velocity;
	
	if (circ_x + b.r >= 1.0f || circ_x - b.r <= -1.0f) 
	{
		circ_dx *= -1.0f;
		circ_x += circ_dx*b.velocity;
	}
	if (circ_y + BALL_RAD >= 1.0f || circ_y - BALL_RAD <= -1.0f)
	{
		circ_dy *= 1.0f;
		circ_y += circ_dy*b.velocity;
	}
	/* printf("%f\n", circ_x); */
	glutPostRedisplay();
}

void display() 
{ 
	glClearColor(0, 0, 0, 1);  
	glClear(GL_COLOR_BUFFER_BIT);

	Rectangle r = make_rect(RECT_TOP_LEFT_X, lrect_y);
	Rectangle l = make_rect(-1.0f*RECT_TOP_LEFT_X - RECT_WIDTH, rrect_y); 

	Ball game_ball = make_ball(circ_x, circ_y, BALL_RAD, BALL_SPEED);

	render_circle_uniform_color(game_ball);
	circ_mv(game_ball);

	render_rect_uniform_color(r);
	render_rect_uniform_color(l);

	glutSwapBuffers(); 
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
	glutInit(&argc, argv);				// Initialize GLUT and
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);	// Use single color buffer and no depth buffer.
	glutInitWindowSize(WIDTH, HEIGHT);			// Size of display area, in pixels.
	glutInitWindowPosition(WIN_POS_X, WIN_POS_Y);	// Location of window in screen coordinates.
	glutCreateWindow("PongC");				// Parameter is window title. 
	glutDisplayFunc(display);				// Called when the window needs to be redrawn.
	glutKeyboardFunc(keyboard_handler);

	glutMainLoop(); // Run the event loop!	This function does not return.
					// Program ends when user closes the window.
	return 0;
}

