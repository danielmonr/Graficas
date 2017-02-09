/**
 * Programa que despliega objetos 3d y les aplica transformaciones.
 */
#include <GL/glut.h>
#include <stdlib.h>

/**
 * Metodo de inicializacion.
 */
void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();
     glTranslatef (1.0, 0.0, 0.0);
     glScalef (2.0, 0.4, 1.0);
     glutWireCube (1.0);
   glPopMatrix();
   glPushMatrix();
     glTranslatef (0.0, 1.0, 0.0);
     glPushMatrix();
       glScalef (1.0, 1.4, 1.0);
       glutWireCube (1.0);
     glPopMatrix();
     glTranslatef (-2.0, -2.0, 1.0);
     glRotatef( -90.0, 1.0, 0.0, 0.0);
     glutWireCone( 1.0, 2.0, 10.0, 10.0);
   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
