#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int primero = GL_TRUE;

/*  Funcion para mexcla de colores en alpha.  */
void init()
{
   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glShadeModel (GL_FLAT);
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void trianguloIzquierdo()
{
/* dibujamos triangulo con alpha activado de 50 */
   glBegin (GL_TRIANGLES);
      glColor4f(1.0, 0.0, 0.0, 0.50);
      glVertex3f(0.1, 0.9, 0.0); 
      glVertex3f(0.1, 0.1, 0.0); 
      glVertex3f(0.7, 0.5, 0.0); 
   glEnd();
}


void trianguloDerecho()
{
/* dibujamos triangulo con alpha activado de 50 */
   glBegin (GL_TRIANGLES);
      glColor4f(0.0, 0.0, 1.0, 0.50);
      glVertex3f(0.9, 0.9, 0.0); 
      glVertex3f(0.3, 0.5, 0.0); 
      glVertex3f(0.9, 0.1, 0.0); 
   glEnd();
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   if (primero) {
      trianguloIzquierdo();
      trianguloDerecho();
   }
   else {
      trianguloDerecho();
      trianguloIzquierdo();
   }
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h) 
      gluOrtho2D (0.0, 1.0, 0.0, 1.0*(GLfloat)h/(GLfloat)w);
   else 
      gluOrtho2D (0.0, 1.0*(GLfloat)w/(GLfloat)h, 0.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'm':
      case 'M':
         primero = !primero;
         glutPostRedisplay();   
         break;
      case 27:  /*  Escape key  */
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (400, 400);
   glutCreateWindow ("Ejemplo mexcla de colores en alpha");
   init();
   glutReshapeFunc (reshape);
   glutKeyboardFunc (keyboard);
   glutDisplayFunc (display);
   glutMainLoop();
   return 0;
}
