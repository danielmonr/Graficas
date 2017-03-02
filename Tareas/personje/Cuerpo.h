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
    void neckUp();
    void neckDown();
    void neckLeft();
    void neckRight();
    void legsUp();
    void legsDown();
    void legsOpen();
    void legsClose();
    void bendknees();
    void extendKnees();
    void armsDown();
    void armsUp();
    void armsFront();
    void armsBack();
    void armsExtend();
    void armsBend();
    void armsRot();
    void armsLot();
    void Draw();
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
    /* Rotation Angles Neck */
    float a_n_sides = 0;
    float a_n_front = 0;
    float a_n_sides_max = 20;
    float a_n_front_max = 20;
};
