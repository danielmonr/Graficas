#include <stdlib.h>
#include <GL/glut.h>


/*

  p13 p14 p15 p16
  p9  p10 p11 p12
  p5  p6  p7  p8
  p1  p2  p3  p4
  
*/

GLfloat ctrlpoints[4][4][3] =
{
    {
        {-1.5, -1.5, -1.0}, //p1
        {-0.5, -1.5, -0.5}, //p2
        {0.5, -1.5, 1.0}, //p3
        {1.5, -1.5, 1.0}},  //p4
    {
        {-1.5, -0.5, -0.5}, //p5
        {-0.5, -0.5, 0.0},  //p6
        {0.5, -0.5, 0.0}, //p7
        {1.5, -0.5, 1.0}}, //p8
    {
        {-1.5, 0.5, 2.0}, //p9
        {-0.5, 0.5, 2.0}, //p10
        {0.5, 0.5, -0.5}, //p11
        {1.5, 0.5, -2.0}}, //p12
    {
        {-1.5, 1.5, 1.0}, //p13
        {-0.5, 1.5, 2.0}, //p14
        {0.5, 1.5, -1.0}, //p15
        {1.5, 1.5, -2.0}} //p16
};

void
initlights(void)
{
    GLfloat ambient[] =
    {0.2, 0.2, 0.2, 1.0};
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

void
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(-50.0, 1.0, 0.0, 0.0);
    glRotatef(10, 0.0, 1.0, 0.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
    glFlush();
}

void
myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
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

int
main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
