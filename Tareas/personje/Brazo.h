#include <iostream>
#include <GL/glut.h>

class Brazo{
  public:
    Brazo(float, float, float, float, float, float, bool);
    ~Brazo();
    void Draw();
    void createUp();
    void createMiddle();
    void createDown();
    void setColorShirt(float, float, float);
    void armUp();
    void armDown();
    void armFront();
    void armBack();
    void middleUp();
    void middleDown();
    void middleR();
    void middleL();
    GLUquadric* qobj;
  private:
    float pos_x, pos_y, pos_z;
    float cs_r, cs_g, cs_b;
    float skin_r = 0.88235, skin_g = 0.67451, skin_b= 0.58824;
    float a_a_front= 0;
    float a_a_front_max = 10;
    float a_a_up= 0;
    float a_a_up_max = 10;
    float a_e_up = 0;
    float a_e_up_max = 90;
    float a_e_r = 0;
    float a_e_r_max = 5;
    float left;
};
