/*
 *========================================================
 *  Daniel Monzalvo Rodriguez A01021514
 *  Acividad 2
 *  Escribir Nombre, apellido y matricula en OpenGL
 *
 *========================================================
 */


#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Funcion para crear los vertices de una linea con anchura de 10
void cuadro(float x1, float x2, float y1, float y2){
    glVertex2f(x1-5, y1+5);
    glVertex2f(x2+5, y1+5);
    glVertex2f(x2+5, y2-5);
    glVertex2f(x1-5, y2-5);
}

// Dibujar una D
void D(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 0.0, 0.0, -50.0);
            cuadro(0.0, 25.0, 0.0, 0.0);
            cuadro(0.0, 25, -50.0, -50.0);
            cuadro(50.0, 50.0, -14, -36);
            cuadro(25.0, 37.5, -46.5, -46.5);
            cuadro(37.5, 50.0, -43, -43);
            cuadro(25.0, 37.5, -3.5, -3.5);
            cuadro(37.5, 50.0, -7, -7);
        glEnd();
    glPopMatrix();
}
// Dibujar una A
void A(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, 0.0,0.0);
            cuadro(0.0, 50.0, -25.0,-25.0);
            cuadro(0.0,0.0, 0.0, -50.0);
            cuadro(50.0, 50.0, 0.0, -50.0);
        glEnd();
    glPopMatrix();
}
// Dibujar una N
void N(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 0.0, 0.0, -50.0);
            cuadro(50.0, 50.0, 0.0, -50.0);
            for(float i = 10.0; i < 50.0;i+=5) // Loop para crear cuadrados en diagonal
               cuadro(i, i, -i, -i);
        glEnd();
    glPopMatrix();
}
// Dibujar I
void I(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, 0.0, 0.0);
            cuadro(0.0, 50.0, -50.0, -50.0);
            cuadro(25.0, 25.0, 0.0, -50.0);
        glEnd();
    glPopMatrix();
}
// Dibujar una E
void E(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, 0.0, 0.0);
            cuadro(0.0, 50.0, -25.0, -25.0);
            cuadro(0.0, 50.0, -50.0, -50.0);
            cuadro(0.0, 0.0, 0.0, -50.0);
        glEnd();
    glPopMatrix();
}
// Dibujar una L
void L(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 0.0, 0.0, -50.0);
            cuadro(0.0, 50.0, -50.0, -50.0);
        glEnd();
    glPopMatrix();
}
// Dibujar una M
void M(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 0.0, 0.0, -50.0);
            cuadro(50.0, 50.0, 0.0, -50.0);
            for(float i = 10.0; i < 30.0; i+=5.0){ // Loop para crear dos diagonales
                cuadro(i, i, -i, -i);
                cuadro(50-i, 50-i, -i, -i);
            }
        glEnd();
    glPopMatrix();
}
// Dibujar una O
void O(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, 0.0, -50.0);
            glColor3f(0,0,0); // Dibujar cuadros del color del fondo
            cuadro(15.0, 35.0, -15.0, -35.0);
        glEnd();
    glPopMatrix();
}
// Dibujar una Z
void Z(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, 0.0, 0.0);
            cuadro(0.0, 50.0, -50.0, -50.0);
            for(float i= 45.0; i > 5.0; i-=5.0) // loop para dibujar una diagonal
                cuadro(i,i, -50+i, -50+i);
        glEnd();
    glPopMatrix();
}
// Dibujar una V
void V(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            for(float i = 0.0; i <= 25.0; i+=5.0){ // loop para dibujar dos diagonales
                cuadro(i, i, -i*2, -i*2);
                cuadro(50-i, 50-i, -i*2, -i*2);
            }
        glEnd();
    glPopMatrix();
}
// Dibujar un 1
void uno(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 0.0, 0.0, -50.0);
        glEnd();
    glPopMatrix();
}
// Dibujar un 2, llama la funcion de dibujo de Z
void dos(int x, int y){
    Z(x,y);
}
// Dibujar un 5
void cinco(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, 0.0, -50.0);
            glColor3f(0,0,0); // Crear cuadrados del color del fondo
            cuadro(15.0, 50.0, -15.0, -15.0);
            cuadro(0.0, 35.0, -35.0, -35.0);
        glEnd();
    glPopMatrix();
}
// Funcion para dibujar 4
void cuatro(int x, int y){
    glPushMatrix(); // Regresar a la matriz original
        glTranslatef(x,y,0.0); // Transladar a la posicion en pantalla deseada
        glBegin(GL_QUADS); // Empezar a dibujar cuadrados con los siguientes vertices (4 en 4)
            cuadro(0.0, 50.0, -25.0, -25.0);
            cuadro(0.0, 0.0, 0.0, -25.0);
            cuadro(50.0, 50.0, 0.0, -50.0);
        glEnd();
    glPopMatrix();
}

// Funcion de inicialización
void init(){
    // Fondo Negro
    glClearColor(0, 0, 0, 0);
    glShadeModel (GL_FLAT);
}

// Funcion que genera un numero aleatorio entre 0 y 1
float col(){
    float c = (rand() % 100);
    if (c == 0.0)
        return col();
    return c/100;
}

void display(){
    glClear (GL_COLOR_BUFFER_BIT);

    //printf("%f", col());

    // Escribir caracteres
    glColor3f(col(),col(), col()); D(-490, 215);
    glColor3f(col(),col(), col()); A(-425, 215);
    glColor3f(col(), col(), col()); N(-360, 215);
    glColor3f(col(), col(),col()); I(-295, 215);
    glColor3f(col(), col(), col()); E(-230, 215);
    glColor3f(col(), col(), col()); L(-165, 215);
    glColor3f(col(), col(), col()); M(-490, 150);
    glColor3f(col(), col(), col()); O(-425, 150);
    glColor3f(col(), col(), col()); N(-360, 150);
    glColor3f(col(), col(), col()); Z(-295, 150);
    glColor3f(col(), col(), col()); A(-230, 150);
    glColor3f(col(), col(), col()); L(-165, 150);
    glColor3f(col(), col(), col()); V(-100, 150);
    glColor3f(col(), col(), col()); O(-35, 150);
    glColor3f(col(), col(), col()); A(-490, 85);
    glColor3f(col(), col(), col()); O(-425, 85);
    glColor3f(col(), col(), col()); uno(-360,85);
    glColor3f(col(), col(), col()); O(-345,85);
    glColor3f(col(), col(), col()); dos(-280,85);
    glColor3f(col(), col(), col()); uno(-215,85);
    glColor3f(col(), col(), col()); cinco(-200,85);
    glColor3f(col(), col(), col()); uno(-135,85);
    glColor3f(col(), col(), col()); cuatro(-120,85);

    glutSwapBuffers();
}

// Funcion de reshape
void reshape(int w, int h){
    // Tamaño de toda la ventana
    glViewport(0,0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    glOrtho(-500, +500, -225, 225, -0.1, 0.1); // Hacer la multiplicacion de la matriz de coordenadas
}

// Funcion principar
int main(int argc, char* argv[]){

    srand(time(NULL)); // inicializar semilla
    // Inicializacion de la ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1000, 450); // Tamano de pantalla
    glutInitWindowPosition(0, 0); // Empezar en la esquina superior izquierda
    glutCreateWindow("Actividad 2"); // crear ventana
    init(); // inicializar los valores de la ventana creada
    glutDisplayFunc(display); // Dibujar letras
    glutReshapeFunc(reshape);
    glutMainLoop(); // Loop de la ventana activa
    return 0;
}
