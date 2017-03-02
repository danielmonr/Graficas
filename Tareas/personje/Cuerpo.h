#include "Brazo.h"
#include "Cabeza.h"
#include "Pierna.h"
#include <GL/glut.h>
#include <iostream>

class Cuerpo{
  public:
    Cuerpo(float, float, float);
    ~Cuerpo();
    void setColorShirt(float, float, float);
    GLUquadric* qobj;
  private:
    /* Position of the carachter */
    float pos_x;
    float pos_y;
    float pos_z;
    /* Colors of the shirt */
    float c_r;
    float c_g;
    float c_b;
    /* Create limbs and body parts */
    void createTorso();
    void createLLeg();
    void createRLeg();
    void createLArm();
    void createRArm();
    void createHead();
    void createNeck();
    /* Limbs */
    Brazo* l_arm;
    Brazo* r_arm;
    Pierna* l_leg;
    Pierna* r_leg;
};
