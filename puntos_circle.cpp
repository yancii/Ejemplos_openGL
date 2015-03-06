#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float radio=0.5;
int numPuntos=30;
const double radius = 5; // The radius of the circle
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);
    glColor3f(1.0f, 0.4f, 0.8f);
    glBegin(GL_POINTS);
      for( int i=0; i<numPuntos; i++ )
        {
            float Angulo = i * (2.0*M_PI/numPuntos); // use 360 instead of 2.0*PI
            float X = cos( Angulo )*radio; // you use d_cos and d_sin
            float Y = sin( Angulo )*radio;
            glVertex2f( X, Y );
        }

    glEnd();
    glFlush ();

}
void init (void)
{
    GLint viewport[4];
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
