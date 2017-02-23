/* ============================================
 * Author: Daniel Monzalvo Rodriguez
 * ID: A01021514
 *
 * Actividad 4 | Graficas Computacionales
 *
 * ITESM, CSF
 *
 * 15-02-17
 * ============================================
*/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLUquadric* qobj;

void cilindro(float h, float x, float y, float z, float ang){
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(90, 0.0, 1.0, 0.0);
        glRotatef(ang, 0.0, 0.0, 1.0);
        gluCylinder(qobj, 0.05, 0.05, h, 50, 50);
    glPopMatrix();
}

void rectangulo(float h, float x, float y, float z, float ang){
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(ang, 0.0, 0.0, 1.0);
        for(int i = 0; i < h; i++){
            glTranslatef(0.0, 0.1, 0.0);
            glutSolidCube(0.1);
        }
    glPopMatrix();

}


void M(float x, float r, float g, float b){
    glPushMatrix();
        glTranslatef(x, 0.0, 0.0);
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {r, g, b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        
        rectangulo(4, 0, 0, 0, 0.0);
        rectangulo(2, 0.19, 0.23, 0, 45.0);
        rectangulo(2, 0.19, 0.23, 0, -45.0);
        rectangulo(4, 0.38, 0, 0, 0);
    glPopMatrix();

}

void O(float x, float r, float g, float b){
    glPushMatrix();
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        glTranslatef(x, 0.23, 0.0);
        glScalef(1.0, 1.0, 0.1);
        //glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidTorus(0.08, 0.18, 15, 15);
    glPopMatrix();
}

void N(float x, float r, float g, float b){
    glPushMatrix();
        glTranslatef(x, 0.0, 0.0);
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {r, g, b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        
        rectangulo(4, 0, 0, 0, 0.0);
        rectangulo(4.1, 0.38, 0.05, 0, 45.0);
        rectangulo(4, 0.35, 0, 0, 0);
    glPopMatrix();
}

void Z(float x, float r, float g, float b){
    glPushMatrix();
        glTranslatef(x, 0.0, 0.0);
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {r, g, b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        
        rectangulo(4, 0.0, 0.4, 0, 90.0);
        rectangulo(4.2, -0.42, 0, 0, -42.0);
        rectangulo(4, 0.0, 0, 0, 90);
    glPopMatrix();
}

void A(float x, float r, float g, float b){
    glPushMatrix();
        glTranslatef(x, 0.0, 0.0);
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {r, g, b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        
        rectangulo(4, 0.0, 0.0, 0, -30.0);
        rectangulo(4, 0.4, 0, 0, 30.0);

        cilindro(0.15, 0.13, 0.13, 0.0, 0.0);

    glPopMatrix();
}

void L(float x, float r, float g, float b){
    glPushMatrix();
        glTranslatef(x, 0.0, 0.0);
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {r, g, b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        
        rectangulo(4, 0, 0, 0, 0.0);
        rectangulo(2, 0.3, 0.1, 0, 90);
    glPopMatrix();
}

void V(float x, float r, float g, float b){
    glPushMatrix();
        glTranslatef(x, 0.0, 0.0);
        GLfloat mat_ambient[] = {r, g, b, 1.0};
        GLfloat mat_diffuse[] = {r, g, b, 1.0};
        GLfloat mat_specular[] = {r, g, b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        
        rectangulo(4, 0, 0, 0, 25.0);
        rectangulo(4, -0.05, 0.0, 0, -25.0);
    glPopMatrix();
}

void display(void){
    GLfloat l_position[] = {0.0, 0.0, 1.1, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, l_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0); // Set color of all objects to white

    M(-1, 1, 0, 0);
    O(-0.2,0,1,0);
    N(0.2, 0, 0, 1);
    Z(1.2, 1,0, 0);
    A(1.3, 1, 1, 0);
    L(1.9, 1, 0, 1);
    V(2.4, 0, 1, 1);
    O(2.9, 0.5, 0.5, 0.5);

    glutSwapBuffers();
}

void preguntas(){
    printf("1) el padre fue ivan suderlan, pluma e inicio en transformaciones. Creo SGI.\n");
    printf("2)\n");
    printf("3)OpenGL fue diseñado para c, . Fundadores: Intel, SGI, Microsoft, IBM.\n");
    printf("4) El rendering es la multiplicacion de las matrices para poder crear la imagen que se visualizará en la pantalla.\n");
    printf("5) a) para establecer el tamaño del display dentro de la pantalla. b) para crear matrices de coordenadas y materiales nuevas dentro de las anteriores. c)Para cargar al la matriz principal sus nuevos valores de configuracion.\n d) Poner todo el color del frame a ese valor.\n e) Configurar una funcion que corra cada fframe en background.\n f) Multiplicar la matriz original para obtener una matriz de coordenadas orthogonal en 2 dimensiones.\n");
    printf("6) Quien sabe.\n");
    printf("7) a- ; b-V; c- ; d- ; e- ; f- \n");
}

/* Keys actions */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
    case 27:
        exit(0); // Escape to exit program
        break;
    default:
         break;
   }
}

/* function to initialize opengl scene */
void init(void) 
{
    // Set light's configuration
    GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 }; // High white ambient light
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

   qobj = gluNewQuadric();
   
}

// Reshape function
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION); // Projection mode
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0); // set perspective configuration
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (-3, -0.1, 4, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Camera settings
}

int main(int argc, char** argv)
{
    preguntas();
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
   return 0;
}
