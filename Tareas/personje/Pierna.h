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
    void legUp();
    void legDown();
    void legOpen();
    void legClose();
    void bendKnee();
    void extendKnee();
    GLUquadric* qobj;
  private:
    float pos_x, pos_y, pos_z;
    float cs_r, cs_g, cs_b;
    float skin_r = 0.88235, skin_g = 0.67451, skin_b= 0.58824;
    float a_hip_sides=0;
    float a_hip_sides_max = 20;
    float a_hip_front=0;
    float a_hip_front_max = 10;
    float a_knee_front = 0;
    float a_knee_front_max = 90;
    float left;
};
