/***************************************************
 *
 *  Autor: Daniel Monzalvo
 *  Matricula: A01021514
 *
 *  mail: danielmonr@gmail.com
 *
***************************************************
*/

#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>


// Valores para la camara
float x1 = 0.0;
float x2 = 0.0;
float y2 = 5.0;
float z1 = 2.0;
float z2 = -3.0;
float yi = 5.0;
int bool = 0;

GLUquadric* qobj;


// Dibujar esfera
void sphere(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        //glTranslatef(0.0,0.0, -3.0);
        glColor3f(0,1,0);
        glutSolidSphere(1,50,50);
    glPopMatrix();
}

// Dibujar anillo
void ring(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        //glRotatef(90, 1,0,0);
        glColor3f(1,0,0);
        glutSolidTorus(0.05, 1.9, 50,50);
    glPopMatrix();
}


// Dibujar ala izquierda
void Lwing(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        glColor3f(1,1,1);
        glTranslatef(2.2,-0.1,0);
        glRotatef(5, 0,0,1);
        glScalef(0.5,0.5,0.5);
        glutSolidTetrahedron();

    glPopMatrix();
}

// Dibujar ala derecha
void Rwing(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        glColor3f(1,1,1);
        glRotatef(180, 0,0,1);
        glTranslatef(2.2, -0.1, 0);
        glRotatef(5,0,0,1);
        glScalef(0.5, 0.5, 0.5);
        glutSolidTetrahedron();
    glPopMatrix();
}

// Dibujar propulsor
void rear(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        glTranslatef(0,1,0);
        gluCylinder(qobj, 0.05, 0.05, 2.0, 50, 50);
    glPopMatrix();
}

// Dibujar soporte de los annillo

void Lsupport(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        glColor3f(0,0,1);
        glTranslatef(-1, 0,0);
        for(float i = 0; i > -0.8; i-=0.05){
            glTranslatef(-0.05, 0,0);
            glutSolidCube(0.05);
        }
    glPopMatrix();
}

void Rsupport(){
    glPushMatrix();
        glTranslatef(0.0,0.0,-3);
        glColor3f(0,0,1);
        glTranslatef(1,0,0);
        for(float i =0; i < 0.8; i +=0.05){
            glTranslatef(0.05, 0,0);
            glutSolidCube(0.05);
        }
    glPopMatrix();
}

// Dibujar nave

void spaceship(){
    sphere();
    ring();
    Lwing();
    Rwing();
    rear();
    Lsupport();
    Rsupport();
}

// Mapeo de teclas
void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'a':
            x1--;
            glutPostRedisplay();
            break;
        case 'w':
            y2--;
            glutPostRedisplay();
            break;
        case 's':
            y2++;
            glutPostRedisplay();
            break;
        case 'd':
            x1++;
            glutPostRedisplay();
            break;
        case 'i':
            z1--;
            glutPostRedisplay();
            break;
        case 'k':
            z1++;
            glutPostRedisplay();
        case 'j':
            x1--;
            break;
        case 'l':
            x1++;
            glutPostRedisplay();
            break;
        case 'v':
            bool = !bool;
            break;
    }
    printf("x (%f, %f) y %f , z %f\nbool:%d\n", x1, x2, y2, z1, bool);
}

// Funciones de inicializacion de matrices y panatallas

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluQuadricDrawStyle(qobj, GLU_LINE);
    glShadeModel (GL_FLAT);
}

void display(void){
    glClear (GL_COLOR_BUFFER_BIT);
    //glRotatef(90,1,0,0);
    gluLookAt(x1, yi, z1, x1, yi, z2,0,0.1,0);

    spaceship();
    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(0.0,0.0,5.0);
}

// Funcion principal

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("Spaceship");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


