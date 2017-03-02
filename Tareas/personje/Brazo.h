#include <iostream>
#include <GL/glut.h>

class Brazo{
  public:
    Brazo(float, float, float, float, float, float, bool);
    ~Brazo();
    void createUp();
    void createMiddle();
    void createDown();
    void setColorShirt(float, float, float);
    GLUquadric* qobj;
  private:
    float pos_x, pos_y, pos_z;
    float cs_r, cs_g, cs_b;
    float skin_r = 0.88235, skin_g = 0.67451, skin_b= 0.58824;
    float shoulder, elbow, wrist;
    float left;
};
