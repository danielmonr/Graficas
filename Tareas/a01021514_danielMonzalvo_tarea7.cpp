#include <stdlib.h>
#include <GL/glut.h>
#include <random>
#include <cstdlib>
#include <iostream>
using namespace std;

// arreglos de puntos para las curvas de Besier (letras)
GLfloat apts[7][3] = {
	{ 2.0, 1.0, 0.0}, { 2.0, 3.0, 0.0},
	{-4.8, 3.0, 0.0}, {-4.8, -4.0, 0.0},
    {2.0, -4.0, 0.0}, {2.0, 8.0, 0.0}, {3.0, -2.0, 0.0}};
GLfloat ipts[5][3] = {
	{0,0,0},{5,0,0},{2.5,9,0},{3.5,-4,0},{5,0,0}
    };
GLfloat arcopts[5][3] = {
	{0,0,0},{0,2,0},{2,4,0},{4,2,0},{4,0,0}
    };
GLfloat epts[6][3] = {
	{0,0,0},{5,0,0},{3.5,9,0},{0.5,5,0},{0.5,-4,0},{5,0,0}
    };
GLfloat opts[7][3] = {
	{0,0,0},{-1.5,0,0.0},{-1.5,-3,0},{0,-5,0},{3,-3,0},{1.5,-0,0.0},{0,0,0}
    };
GLfloat cejitapts[2][3] = {
	{0,0,0},{2,0,0}
    };
GLfloat lpts[6][3] = {
	{0,0,0},{5,0,0},{3.5,18,0},{0.5,5,0},{0.5,-4,0},{5,0,0}
    };
GLfloat dpts[6][3] = {
	{0,0,0},{-1.5,6,0},{-7,-4,0},{5,-4,0},{0,0,0},{-2,7,0}//,{0,-10,0},{2,-1,0}
  };
GLfloat vpts[7][3] = {
	{0,0,0},{1,3,0},{4,0,0},{1,-7,0},{4,-7,0},{2,-0.5,0},{7, 1, 0}//,{0,-10,0},{2,-1,0}
};

GLfloat zpts[7][3] = {
	{0,0,0},{7,0,0},{-10,-4,0},{8,-0,0},{4,-7,0},{-5,-7,0},{4,-1,0}
};

// funciones de las letras y helpers
void Daniel();
void Monzalvo();
void D();
void A();
void N();
void I();
void E();
void L();
void M();
void O();
void Z();
void V();
void Arco();


//random colors
void getColor()
{
    std::random_device rd; std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    glColor3f(dis(gen), dis(gen), dis(gen));
}

// GLmagick
void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);
}

// Escribir Daniel, Pintar letras en su lugar
void Daniel()
{
    glPushMatrix();
			glTranslatef(-6, 1, 0.0);
			D();
			glTranslatef(2, 0,0);
			A();
			glTranslatef(2,-0.5,0);
			N();
			glTranslatef(2,0,0);
			I();
			glTranslatef(2.5,0,0);
			E();
			glTranslatef(2,-0.2,0);
			L();
    glPopMatrix();
}

// Pintar Monzalvo, Pintar letras en su lugar
void Monzalvo(){
    glPushMatrix();
      	M();
				glTranslatef(4,1.3,0);
				O();
				glTranslatef(1,-1.3,0);
				N();
				glTranslatef(2,1.5,0);
				Z();
				glTranslatef(2,-1.2, 0);
				A();
				glTranslatef(1.6,-1,0);
				L();
				glTranslatef(2,2,0);
				V();
				glTranslatef(4,0,0);
				O();
    glPopMatrix();
}

// Pintar letra A
void A()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &apts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar letra I
void I()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &ipts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar Arco para formar N y M
void Arco()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &arcopts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar letra M
void M()
{
    glPushMatrix();
        glScalef(0.5,1,1);
        glPushMatrix();
            Arco();
            glTranslatef(2,0,0);
            Arco();
            glTranslatef(2,0,0);
            Arco();
        glPopMatrix();
    glPopMatrix();
}

// Pintar letra E
void E()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &epts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar letra O
void O()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &opts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
     glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &cejitapts[0][0]);
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar letra L
void L()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &lpts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar lerta N
void N()
{
    glPushMatrix();
        glScalef(0.5,1,1);
        glPushMatrix();
            Arco();
            glTranslatef(2,0,0);
            Arco();
        glPopMatrix();
    glPopMatrix();
}

// Pintar letra D
void D()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &dpts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar letra Z
void Z()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &zpts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Pintar letra V
void V()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &vpts[0][0]);
    getColor();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++)
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// Función que describe lo que se va a dibujar
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   Daniel();
   glTranslatef(-9.5,-3,0);
   Monzalvo();
   glFlush();
}

// Funciones de GL para armar la escena
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
               5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
   else
      glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
               5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Función del teclado
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

// Función principal
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (1500, 700);
   glutInitWindowPosition (00, 00);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
