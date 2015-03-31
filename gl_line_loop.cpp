#include <GL/gl.h>
#include <GL/glut.h>



void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);
    glTranslatef(0.0f,0.0f,-0.2f);//move forward 2 units
    glColor3f(0.0f,0.0f,1.0f); //blue color
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f,0.0f,0.0f);//left of window
        glVertex3f(0.0f,-1.0f,0.0f);//bottom of window
        glVertex3f(1.0f,0.0f,0.0f);//right of window
        glVertex3f(0.0f,1.0f,0.0f);//top of window
    glEnd();
    glFlush ();

}
void init (void)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
