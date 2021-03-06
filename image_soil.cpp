#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h> 


GLuint texture[0];

void resize(int h, int w) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-5.0f);
    
     texture[0] = SOIL_load_OGL_texture // cargamos la imagen
    (
        "container.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
	
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(1.0f, 1.0f);  
    glVertex3f(0.0,1.0,0.0);
    glTexCoord2f(0.1f, 0.0f);  
    glVertex3f(-1.0,-0.4,0.0);
    glTexCoord2f(0.0f, 1.0f);  
    glVertex3f(0.8,-0.4,0.0);
    glEnd();
    
    glutSwapBuffers();
    
   
}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("ejmplo1");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
   
    /////////////////////////////////////
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutMainLoop();
}

