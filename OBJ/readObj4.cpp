#include <stdlib.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel *modelo, *modelo2, *modelo3, *modelo4;
GLuint _listaObj1, _listaObj2, _listaObj3, _listaObj4;

void init(void) 
{

    GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 0.0, 5.0, 8.0, 0.0 };
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

   modelo = glmReadOBJ( "pianoAQueue.obj" );
   glmFacetNormals( modelo );
   glmVertexNormals( modelo, 90.0 );
   _listaObj1 = glmList(modelo, GLM_SMOOTH | GLM_COLOR);

   modelo2 = glmReadOBJ( "litMezzanine.obj" );
   glmFacetNormals( modelo2 );
   glmVertexNormals( modelo2, 90.0 );
   _listaObj2 = glmList(modelo2, GLM_SMOOTH | GLM_COLOR);

   modelo3 = glmReadOBJ( "pioneer_3dx.obj");
   glmFacetNormals( modelo3 );
   glmVertexNormals( modelo3, 90.0 );
   _listaObj3 = glmList(modelo3, GLM_SMOOTH | GLM_COLOR);

   modelo4 = glmReadOBJ( "cruz.obj");
   glmFacetNormals( modelo4 );
   glmVertexNormals( modelo4, 90.0 );
   _listaObj4 = glmList(modelo4, GLM_SMOOTH | GLM_COLOR);
}

GLfloat azul[] = { 0.0, 0.2, 0.9, 1.0 };
GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 0.5 };
GLfloat mat_diffuse[] = { 0.95, 0.4, 0.4, 0.7 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix ();
      glTranslatef( 0.0, 0.0, -10.0 );
      glScalef(0.01, 0.01, 0.01);
      glEnable (GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE);
      glCallList(_listaObj1);
      glDisable (GL_BLEND);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef( -0.0, 0.0, -10.5 );
      glScalef(0.01, 0.01, 0.01);
      glEnable (GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE);
      glCallList(_listaObj2);
      glDisable (GL_BLEND);
   glPopMatrix ();
/*
   glPushMatrix ();
      glTranslatef( -0.2, 0.0, -3.5 );
      glCallList(_listaObj3);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef( 0.0, -0.3, -5.5 );
      glScalef(0.1, 0.1, 0.1);
      glCallList(_listaObj4);
   glPopMatrix ();
*/
   glutSwapBuffers ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
