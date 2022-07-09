#include <stdio.h>
#include <GL/glut.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;

void reshape(int width, int heigth){
    /* window ro reshape when made it bigger or smaller*/

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //clip the windows so its shortest side is 2.0
    if (width < heigth) {
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 2.0, 2.0);
    }
    else{
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth,2.0 , 2.0);
    }
    // set viewport to use the entire new window
    glViewport(0, 0, width, heigth);
}

void rect(){
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.1, -0.2);
    glVertex2f(-0.1, 0.2);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.1, -0.2);
    glEnd();

}

void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(posX,posY,posZ);
    rect();
    glPopMatrix();
    glFlush();
}


void init(){
    // set clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // set fill color to white
    glColor3f(1.0, 1.0, 1.0);

    //set up standard orthogonal view with clipping
    //box as cube of side 2 centered at origin
    //This is the default view and these statements could be removed
}
float move_unit = 0.1f;
void keyboardown(int key, int x, int y)
{
	(void) x;
	(void) y;

    switch (key){
        case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Practice 1");
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(keyboardown);
    glutMainLoop();

}
