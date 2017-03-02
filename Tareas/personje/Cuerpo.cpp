#include "Cuerpo.h"

Cuerpo::Cuerpo(float x, float y, float z){
  pos_x = x;
  pos_y = y;
  pos_z = z;
  c_r = 1.0;
  c_g = 0.0;
  c_b = 0.0;
  qobj = gluNewQuadric();
  glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    createTorso();
    createLLeg();
    createRLeg();
    createLArm();
    createRArm();
    createHead();
  glPopMatrix();
}

Cuerpo::~Cuerpo(){

}

void Cuerpo::setColorShirt(float r, float g, float b){

}

void Cuerpo::createNeck(){
  glPushMatrix();
    GLfloat color[] = {cs_r, cs_g, cs_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    gluCylinder(qobj, 0.3, 0.4, 1, 50, 50);
  glPopMatrix();
}

void Cuerpo::createHead(){

}

void Cuerpo::createRArm(){
  r_arm = new Brazo(-1.5, 1, 0.0, 1.0, 0.0, 0.0, false);
}

void Cuerpo::createLArm(){
  l_arm = new Brazo(-1.5, 1, 0.0, 1.0, 0.0, 0.0, true);
}

void Cuerpo::createRLeg(){
  r_leg = new Pierna(-1, -1.8, 0.0, 0.0, 0.0, 1.0, false);
}

void Cuerpo::createLLeg(){
  l_leg = new Pierna(-1.1, -2, 0.0, 0.0, 0.0, 1.0, true);
}

void Cuerpo::createTorso(){
  std::cout << "Drawing torso\n";
  glPushMatrix();
    GLfloat color[] = {c_r, c_g, c_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glRotatef(21.0, 0.0,1.0,0.0);
    //glutSolidDodecahedron();
    glutSolidSphere(1.0, 50, 50);
  glPopMatrix();
}
