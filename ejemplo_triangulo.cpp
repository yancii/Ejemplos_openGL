#include <GL/freeglut.h>
//#include<stdlib.h>
#include<math.h>
//#include<GL/glu.h>

//static void RenderSceneCB()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glutSwapBuffers();
//}

//static void InitializeGlutCallbacks()
//{
//    glutDisplayFunc(RenderSceneCB);
//}

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);   //Selecciona el color de fondo
  glColor3f(0.5f, 0.0f, 1.0f);        //El color a dibujar
  glPointSize(4.0);                   //Tamaño de los puntos
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);      //Limpia la pantalla
    
    
    glBegin(GL_LINE_STRIP); 
      glColor3f(1.0f, 0.0f, 0.0f);  // activamos el color rojo
      glVertex3f(0.0f, 0.0f, 0.0f); //Priver vertice
      glColor3f(0.0f, 1.0f, 0.0f);  // activamos el color verde
      glVertex3f(0.5f, 0.5f, 0.0f); //Segundo vertice
      glVertex3f(0.7f, -0.2f, 0.0f); //segundo vertice 2da linea
      glVertex3f(0.3f, -1.0f, 0.0f); //segundo vertice 2da linea
      
    glEnd();
    glFlush();                        //Envía toda la salida a pantalla
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(800/2, 600/2);
    
    glutCreateWindow("Ejemplo 1");
    
    glutDisplayFunc(myDisplay);                       //Registra función de redibujar
    //myInit();
  
    //InitializeGlutCallbacks();

    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();
    
    return 0;
}
