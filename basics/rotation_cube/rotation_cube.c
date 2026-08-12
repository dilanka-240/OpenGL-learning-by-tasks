#include <GL/glut.h>

float angle = 0.0;

void createCube(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //back face
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2,0,-0.4);
    glVertex3f(-0.2,0.4,-0.4);
    glVertex3f(0.2,0.4,-0.4);
    glVertex3f(0.2,0,-0.4);
    glEnd();

    //left face
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, -0.2,  0.0);
    glVertex3f(-0.4,  0.2,  0.0);
    glVertex3f(-0.2,  0.4, -0.4);
    glVertex3f(-0.2,  0.0, -0.4);
    glEnd();

    //top face
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4,  0.2,  0.0);
    glVertex3f( 0.0,  0.2,  0.0);
    glVertex3f( 0.2,  0.4, -0.4);
    glVertex3f(-0.2,  0.4, -0.4);
    glEnd();

    //bottom face
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, -0.2,  0.0);
    glVertex3f( 0.0, -0.2,  0.0);
    glVertex3f( 0.2,  0.0, -0.4);
    glVertex3f(-0.2,  0.0, -0.4);
    glEnd();

    //front face
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4,-0.2,0);
    glVertex3f(-0.4,0.2,0);
    glVertex3f(0,0.2,0);
    glVertex3f(0,-0.2,0);
    glEnd();

    //right face
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f( 0.0, -0.2,  0.0);
    glVertex3f( 0.0,  0.2,  0.0);
    glVertex3f( 0.2,  0.4, -0.4);
    glVertex3f( 0.2,  0.0, -0.4);
    glEnd();
    glFlush();
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -2.0);   // move cube back
    glRotatef(angle, 1.0, 1.0, 0.0); // rotate around x and y

    createCube();

    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // call again in 16 ms
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Rotation Cube");
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION); // set up projection
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0.0,0.0,0.0,1.0);
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
return 0;
}

