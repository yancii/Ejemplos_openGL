#include <GL/glut.h>

void myInit(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
      glVertex3f(-1,-1,0);
      glVertex3f(1,-1,0);
      glVertex3f(0,1,0);
    glEnd();
    glFlush();
}
 
void init()
{
    glClearColor(0,0,0,0);
}
 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hola, Algoritmos Graficos");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myInit);
    glutMainLoop();
    return 0;
}
