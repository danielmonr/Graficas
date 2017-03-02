#include <iostream>
#include <GL/glut.h>

class Pierna{
  public:
    Pierna(float, float, float, float, float, float, bool);
    ~Pierna();
    void Draw();
    void createUp();
    void createMiddle();
    void createDown();
    void setColorPants(float, float, float);
    GLUquadric* qobj;
  private:
    float pos_x, pos_y, pos_z;
    float cs_r, cs_g, cs_b;
    float skin_r = 0.88235, skin_g = 0.67451, skin_b= 0.58824;
    float hip, elbow, wrist;
    float left;
};
