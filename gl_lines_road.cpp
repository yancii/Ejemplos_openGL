#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>


void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);
    glColor3f(0.0f,0.0f,1.0f); //blue color
    GLfloat angulo;
    
	int i; 
    glBegin(GL_LINES);
	for (i=0; i<180; i+=10)
	{
      angulo = (GLfloat)i*M_PI/180.0f; // grados a radianes
      glVertex3f(0.0f, 0.0f, 0.0f);
      glVertex3f(cos(angulo), sin(angulo), 0.0f);
	}
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
