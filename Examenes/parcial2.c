#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

float angX=-90, angY=0;
/*

  p13 p14 p15 p16
  p9  p10 p11 p12
  p5  p6  p7  p8
  p1  p2  p3  p4

*/

GLfloat ctrlpoints[4][4][3] =
{
    {
        {-1.73, -1.73, 0.0}, //p1
        {-1.5, -3.0, 0.0}, //p2
        {1.5, -3.0, 0.0}, //p3
        {1.73, -1.73, 0.0}},  //p4
    {
        {-3, -1.5, 0.0}, //p5
        {-1.5, -1.5, 2.0},  //p6
        {1.5, -1.5, 2.0}, //p7
        {3, -1.5, 0.0}}, //p8
    {
        {-3, 1.5, 0.0}, //p9
        {-1.5, 1.5, 2.0}, //p10
        {1.5, 1.5, 2.0}, //p11
        {3, 1.5, 0.0}}, //p12
    {
        {-1.73, 1.73, 0.0}, //p13
        {-1.5, 3.0, 0.0}, //p14
        {1.5, 3.0, 0.0}, //p15
        {1.73, 1.73, 0.0}} //p16
};

/*

  p13 p14 p15 p16
  p9  p10 p11 p12
  p5  p6  p7  p8
  p1  p2  p3  p4

*/

GLfloat ctrlpoints2[4][4][3] =
{
    {
        {-3, -3, 3}, //p1
        {-1.5, -3.0, 0.75}, //p2
        {1.5, -3.0, 0.75}, //p3
        {3, -3, 3}},  //p4
    {
        {-3, -1.5, 3}, //p5
        {-1.5, -1.5, 0.75},  //p6
        {1.5, -1.5, 0.75}, //p7
        {3, -1.5, 3}}, //p8
    {
        {-3, 1.5, 3}, //p9
        {-1.5, 1.5, 0.75}, //p10
        {1.5, 1.5, 0.75}, //p11
        {3, 1.5, 3}}, //p12
    {
        {-3.0, 3, 3}, //p13
        {-1.5, 3.0, 0.75}, //p14
        {1.5, 3.0, 0.75}, //p15
        {3, 3, 3}} //p16
};

void
initlights(void)
{
    GLfloat ambient[] =
    {1, 1, 1, 1.0};
    GLfloat position[] =
    {0.0, 0.0, 5.0, 1.0};
    GLfloat mat_diffuse[] =
    {0.6, 0.6, 0.6, 1.0};
    GLfloat mat_specular[] =
    {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] =
    {50.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void materialCarne(){
  GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat mat_ambient[] = { 0.21, 0.10, 0.05, 1.0 };
  GLfloat mat_diffuse[] = { 63/255, 52/255, 12/255, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat no_shininess[] = { 0.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}

void materialPan(){
  GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat mat_ambient[] = { 0.25, 0.23, 0.05, 1.0 };
  GLfloat mat_diffuse[] = { 0.25, 0.23, 0.05, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat no_shininess[] = { 0.0 };
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}

void pan_arriba(){
  glPushMatrix();
    materialPan();
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    glRotatef(90, 1.0, 0.0,0.0);
    glTranslatef(0.0, 0.0, 1.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
  glPopMatrix();
}
void pan_abajo(){
  glPushMatrix();
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    glRotatef(-90, 1.0, 0.0,0.0);
    glTranslatef(0.0, 0.0, 1.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
  glPopMatrix();
}

void carne(){
  glPushMatrix();
    materialCarne();
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints2[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -3.0);
    glScalef(0.8, 0.3, 1.5);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
  glPopMatrix();
}


void
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
      glTranslatef(0.0, 0.0, 4.0);
      glRotatef(angX, 1, 0, 0);
      glRotatef(angY, 0, 1, 0);

      pan_arriba();
      pan_abajo();
      glTranslatef(0,0, -1.5);
      carne();
      glTranslatef(0.0, 0, 3.0);
      glRotatef(180,1.0, 0.0, 0.0);
      carne();

    glPopMatrix();
    glFlush();
}

int down = 0, lastx, lasty;

/* ARGSUSED1 */
void
motion(int x, int y)
{
    if (down) {
        angX = lasty - y;
        angY = (lastx - x);
        glutPostRedisplay();
    }
}

/* ARGSUSED3 */
void
mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            lastx = x;
            down = 1;
        } else {
            down = 0;
        }
    }
}

void
myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    initlights();       /* for lighted version only */
}

void
myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
            4.0 * (GLfloat) h / (GLfloat) w, -4.0, 4.0);
    else
        glOrtho(-4.0 * (GLfloat) w / (GLfloat) h,
            4.0 * (GLfloat) w / (GLfloat) h, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void respuestas(){
  printf("1) las dos secciones son:\n\t- Header: metadata(tipo de imagen, fromato, etc..)\n\t- cuerpo: RGB o contenido de imagen\n");
  printf("2) 4:3, 16:9, 3:2\n");
  printf("3)\n\t- translacion: se le suma a la ultima columna de la matriz el valor de translacion\n\t- rotacion: se multiplican los valores de la primera columna por el coseno del angulo, los de la segunda por el seno del angulo.\n");
  printf("4)\n\t- COP: Center of projeccion\n\t- Distance of projection\n\t- punto de fuga: es el punto hacial el cual todos los elementos de una perpesctiva se dirigen.\n");
  printf("5) La cinematica son las fuerzas y movimientos que se aplican sobre un objeto.\n\t- directa: se aplica directamente sobre el objeto.\n\t- indirecta un objeto le aplica la fuerza, el usuario no interactua directamente.\n");
  printf("6)\n\t- hombro: rotacion, revolucion\n\t- codo:torcion, rotacion\n\t- muneca: rotacion, revolucion\n");
  printf("7)\n");
  printf("8)La diferencia está en el numero de funciones que utilizan para mezclar.\n");
  printf("9)\n");
  printf("10)\n\t- AR: Realidad Aumentada, se ve la realidad pero se le agrega algun elemento digital (googlelens)\n\t- VR: Realidad Virtual, el mundo es virtual la realidad no interfiere en la esena.\n\t- MR:Mixed Reality, se mezclan varias realidades\n\t-AV: Augmented Virtual, se le añaden otras sensaciones al mundo virtual.\n\t\n");
}

int
main(int argc, char **argv)
{
  respuestas();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
