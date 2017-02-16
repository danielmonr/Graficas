#include <GL/glut.h>
#include <stdlib.h>

static int mer = 0, mer_d = 0, ven = 0, ven_d = 0, tie = 0, tie_d = 0, mar = 0, mar_d = 0;
static int jup = 0, jup_d = 0, sat = 0, sat_d = 0, ura = 0, ura_d = 0, nep = 0, nep_d = 0;
static char move = 0;
static int close = 3;
static int moons = 0;

void sun(){
    glPushMatrix();
        glDisable(GL_LIGHT0); // Disable ambient light

        // Create sun's light
        GLfloat l_ambient[] = { 1.0, 0.4, 0.1, 1.0 };
        GLfloat l_specular[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat l_diffuse[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat position[] = {0.0, 1.01, 0.0, 1.0};
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_ambient);
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_ambient);
        glLightfv(GL_LIGHT1, GL_POSITION, position);
        glEnable(GL_LIGHT1); // Enable sun's light

        // Create sun's material
        GLfloat color[] = {1.0, 1.0, 1.0, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);

        glutSolidSphere(1, 20, 50); // Draw sun

        // restore previous light
        glDisable(GL_LIGHT1);
        glEnable(GL_LIGHT0);
    glPopMatrix();
}

struct anillo{
    float ri;
    float re;
    float alt;
    float r;
    float g;
    float b;
    float ang;
};
typedef struct anillo anillo_t;

anillo_t ring(float ang, float ri, float re, float alt, float r, float g, float b){
    anillo_t a;
    a.ri = ri;
    a.re = re;
    a.alt = alt;
    a.r = r;
    a.g = g;
    a.b = b;
    a.ang = ang;
    return a;
}

void draw_r(anillo_t a){
    glPushMatrix();
        glRotatef(a.ang, 1.0, 0.0, 0.0);
        GLfloat mat_ambient[] = {a.r, a.g, a.b, 1.0};
        GLfloat mat_diffuse[] = {a.r, a.g, a.b, 1.0};
        GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        glScalef(1.0, 1.0, a.alt);
        glutSolidTorus(a.ri, a.re, 15, 15);
    glPopMatrix();
}

struct planeta{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float rad;
    anillo_t* a;
    struct planeta* m;
    struct planeta* m2;
};
typedef struct planeta planeta_t;

planeta_t planet(float x, float y, float z, float rad, float r, float g, float b){
    planeta_t p;
    p.x = x; p.y = y; p.z = z; p.rad = rad; p.r = r; p.g = g; p.b = b;
    p.a = NULL; p.m = NULL, p.m2 = NULL;
    return p;
}

void draw_p(planeta_t p, float angulo){
    glPushMatrix();
        glTranslatef(p.x, p.y, p.z);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        GLfloat mat_ambient[] = {p.r, p.g, p.b, 1.0};
        GLfloat mat_diffuse[] = {p.r, p.g, p.b, 1.0};
        GLfloat mat_specular[] = {p.r, p.g, p.b, 1.0};
        GLfloat mat_shiness[] = {128.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
        glutSolidSphere(p.rad, 20, 20);
        if(p.a != NULL){
            draw_r(*p.a); // If has ring draw ring
        }
        if(p.m != NULL){
            glRotatef(moons, 0.0, 1.0, 0.0);
            draw_p(*p.m, 10); // If has moon draw moon
        }
        if(p.m2 != NULL){
            glRotatef(moons, 0.0, 1.0, 0.0);
            draw_p(*p.m2, 10); // If has moon draw moon
        }
    glPopMatrix();
}

void display_panet(planeta_t p, float year, float day){
    glPushMatrix();
        glRotatef(year, 0.0, 1.0, 0.0); // planet's rotation around the sun
        draw_p(p, day); // Draw planet
    glPopMatrix();
}

void display(void)
{
    // Set position and Activate light
    GLfloat l_position[] = {0.0, 0.0, 1.1, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, l_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    planeta_t mercury = planet(1.15, 0.0, 0.0, 0.05, 0.66, 0.66, 0.66); // Create mercury
    planeta_t venus = planet(1.4, 0.0, 0.0, 0.1, 0.6, 0.1, 0.0); // Create Venus
    planeta_t tierra = planet(1.62, 0.0, 0.0, 0.1, 0.0, 0.8, 0.1); // Create Earth
    planeta_t moon_earth = planet(0.1, 0.1, 0.0, 0.03, 0.3, 0.3, 0.3); tierra.m = &moon_earth;// Create earth's moon
    planeta_t mars = planet(1.8, 0.0, 0.0, 0.04, 0.8, 0.4, 0.4); // Create Mars
    planeta_t moon_mars = planet(0.1, 0.0, 0.0, 0.02, 0.3, 0.3, 0.3); mars.m = &moon_mars; // one of mars moons
    planeta_t jupiter = planet(2.7, 0.0, 0.0, 0.4, 0.6, 0.3, 0.0); // Create Jupiter
    planeta_t moon_jupiter = planet(-0.5, 0.0, 0.0, 0.07, 0.3, 0.3, 0.3); jupiter.m = &moon_jupiter; // one of jupiter's moons
    planeta_t moon2_jupiter = planet(0.5, 0.0, 0.0, 0.04, 0.3, 0.3, 0.3); jupiter.m2 = &moon2_jupiter; // one of jupiter's moons
    planeta_t saturn = planet(4.0, 0.0, 0.0, 0.3, 0.6, 0.5, 0.5); // Create Saturn
    planeta_t moon_saturn = planet(0.4, 0.1, 0.0, 0.05, 0.3, 0.3, 0.3); saturn.m = &moon_saturn; // one of saturn's moons
    anillo_t ring_saturn = ring(90.0, 0.09, 0.48, 0.01, 0.6, 0.5, 0.5); saturn.a = &ring_saturn; // Create saturn's ring
    planeta_t uranus = planet(6.0, 0.0, 0.0, 0.27, 0.0, 0.0, 0.7); // Create uranus
    planeta_t moon_uranus = planet(0.35, 0.0, 0.0, 0.04, 0.4, 0.4, 0.8); uranus.m = &moon_uranus; // one of uranus moons
    anillo_t ring_uranus = ring(10.0, 0.09, 0.37, 0.005, 0.01, 0.01, 0.02); uranus.a = &ring_uranus; // Create uranus ring
    planeta_t neptune = planet(8.0, 0.0, 0.0, 0.27, 0.0, 0.3, 0.7); // Create Neptune
    planeta_t moon_neptune = planet(0.32, 0.0, 0.0, 0.03, 0.3, 0.3, 0.3); neptune.m = &moon_neptune; // one of neptune's moons
    anillo_t ring_neptune = ring(90.0, 0.05, 0.4, 0.005, 0.3, 0.3, 0.3); neptune.a = &ring_neptune; // Create neptune ring
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0); // Set color of all objects to white
    glPushMatrix();
        sun(); // Draw sun
        
        // Display planets
        display_panet(mercury, mer, mer_d);
        display_panet(venus, ven, ven_d);
        display_panet(tierra, tie, tie_d);
        display_panet(mars, mar, mar_d);
        display_panet(jupiter, jup, jup_d);
        display_panet(saturn, sat, sat_d);
        display_panet(uranus, ura, ura_d);
        display_panet(neptune, nep, nep_d);

    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

void init(void) 
{
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

   glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
   glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
   //glLightfv(GL_LIGHT0, GL_POSITION, position);
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, mat_light_ambient);

   
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   
}

static int cont = 0;
void simulacion(){
    int x = 15;
    if(!move)
        return;
    if(cont != 100000){
        cont = cont+1;
        return;
    }
    mer = (mer+(x*40))%360;
    tie = (tie+(x*10))%360;
    ven = (ven+(x*20))%360;
    mar = (mar+(10*x/2))%360;
    jup = (jup+ (x/1))%360;
    sat = (sat+ (x/3))%360;
    ura = (ura + (x/8))%360;
    nep = (nep + (x/15))%360;
    moons = (moons + (x*10))%360;
    cont = 0;
    
    glutPostRedisplay();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 3, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
       case 'w':
        close++;
        glutPostRedisplay();
        break;
    case 's':
        close--;
        glutPostRedisplay();
        break;
    case ' ':
        move = !move;
        break;
    case 27:
        exit(0);
        break;
    default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize (1000, 800); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display); 
   glutIdleFunc(simulacion);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
