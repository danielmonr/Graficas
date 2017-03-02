#include <iostream>
#include "Cuerpo.h"

Cuerpo* carachter = new Cuerpo(0,0,0);;

void display(){
  GLfloat l_position[] = {0.0, 0.0, 2.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, l_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);

  glPushMatrix();
    carachter->Draw();
  glPopMatrix();

  glutSwapBuffers();
  glFlush();
}

void init(){
  // Set light's configuration
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.0, 1.0 }; // Low yellow ambient light
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // white specular light
    GLfloat mat_diffuse[] = {1.0, 1.0, 1.0, 1.0}; // white diffuse light
    GLfloat mat_light_ambient[] = {0.0, 0.0, 0.0, 1.0}; // black ambient
    glEnable(GL_DEPTH_TEST); // activate depth
    glDepthFunc(GL_LESS); // set depth function

    // Set LIGHT0 settings
   glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
   glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, mat_light_ambient);


   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
}

void reshape(int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION); // Projection mode
  glLoadIdentity ();
  gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0); // set perspective configuration
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt (0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Camera settings
}

void keyboard(unsigned char key, int x, int y){
  switch (key){
    case 'n':
      carachter->neckDown();
      glutPostRedisplay();
      break;
    case 'N':
      carachter->neckUp();
      glutPostRedisplay();
      break;
    case 'm':
      carachter->neckLeft();
      glutPostRedisplay();
      break;
    case 'M':
      carachter->neckRight();
      glutPostRedisplay();
      break;
    case 27:
      exit(0);
      break;
    default:
      break;
  }
}


int main(int argc, char* argv[]){

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize (1000, 800);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 1;
}
