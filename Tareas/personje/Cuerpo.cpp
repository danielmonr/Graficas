#include "Cuerpo.h"

Cuerpo::Cuerpo(float x, float y, float z){
  pos_x = x;
  pos_y = y;
  pos_z = z;
  c_r = 1.0;
  c_g = 0.0;
  c_b = 0.0;
  qobj = gluNewQuadric();
  createLLeg();
  createRLeg();
  createLArm();
  createRArm();
}

Cuerpo::~Cuerpo(){
  delete l_arm;
  delete r_arm;
  delete l_leg;
  delete r_leg;
}

void Cuerpo::Draw(){
  glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    createTorso();
    l_leg->Draw();
    r_leg->Draw();
  glPopMatrix();
}

void Cuerpo::setColorShirt(float r, float g, float b){

}

void Cuerpo::createNeck(){
  glPushMatrix();
    glRotatef(a_n_front, 1.0, 0.0, 0.0);
    //std::cout << "n_sides" << a_n_sides << "\n";
    glRotatef(a_n_sides, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.45, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    GLfloat color[] = {0.88235,0.67451, 0.58824, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    gluCylinder(qobj, 0.3, 0.3, 0.5, 50, 50);
    createHead();
  glPopMatrix();
}

void Cuerpo::createHead(){
  glPushMatrix();
    glTranslatef(0.0, 0.0, -0.38);
    glRotatef(90, 1.0, 0.0, 0.0);
    GLfloat color[] = {0.88235,0.67451, 0.58824, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    glutSolidSphere(0.5, 50, 50);
  glPopMatrix();
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
  //std::cout << "Drawing torso\n";
  glPushMatrix();
    GLfloat color[] = {c_r, c_g, c_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    glutSolidSphere(1.0, 50, 50);
    createNeck();
    l_arm->Draw();
    r_arm->Draw();
  glPopMatrix();
}

void Cuerpo::neckUp(){
  std::cout << "Neck up " << a_n_front <<"\n";
  if(a_n_front > 0)
    a_n_front--;
}

void Cuerpo::neckDown(){
  std::cout << "Neck down" << a_n_front << "\n";
  if(a_n_front < a_n_front_max)
    a_n_front++;
}

void Cuerpo::neckLeft(){
  if(a_n_sides < a_n_sides_max)
    a_n_sides++;
  std::cout << "Neck Left " << a_n_sides << "\n";
}

void Cuerpo::neckRight(){
  if(a_n_sides > -1*a_n_sides_max)
    a_n_sides--;
  std::cout << "Neck Right " << a_n_sides << "\n";
}

void Cuerpo::legsUp(){
  l_leg->legUp();
  r_leg->legUp();
}
void Cuerpo::legsDown(){
  l_leg->legDown();
  r_leg->legDown();
}
void Cuerpo::legsOpen(){
  l_leg->legOpen();
  r_leg->legOpen();
}
void Cuerpo::legsClose(){
  l_leg->legClose();
  r_leg->legClose();
}

void Cuerpo::bendknees(){
  l_leg->bendKnee();
  r_leg->bendKnee();
}
void Cuerpo::extendKnees(){
  l_leg->extendKnee();
  r_leg->extendKnee();
}

void Cuerpo::armsDown(){
  l_arm->armDown();
  r_arm->armDown();
}
void Cuerpo::armsUp(){
  l_arm->armUp();
  r_arm->armUp();
}
void Cuerpo::armsFront(){
  l_arm->armFront();
  r_arm->armFront();
}
void Cuerpo::armsBack(){
  l_arm->armBack();
  r_arm->armBack();
}

void Cuerpo::armsExtend(){
  l_arm->middleDown();
  r_arm->middleDown();
}

void Cuerpo::armsBend(){
  l_arm->middleUp();
  r_arm->middleUp();
}

void Cuerpo::armsRot(){
  l_arm->middleR();
  r_arm->middleR();
}

void Cuerpo::armsLot(){
  l_arm->middleL();
  r_arm->middleL();
}
