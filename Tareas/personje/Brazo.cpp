#include "Brazo.h"

Brazo::Brazo(float x, float y, float z, float r, float g, float b, bool lf){
  pos_x = x; pos_y = y; pos_z = z;
  cs_r = r; cs_g = g; cs_b = b;
  left = (lf)? -1.0 : 1.0;
  //std::cout << "Creando Brazo\n";
  qobj = gluNewQuadric();
}

Brazo::~Brazo(){
  //delete qobj;
}

void Brazo::Draw(){
  glPushMatrix();
    glTranslatef(left*pos_x, pos_y, pos_z);
    glRotatef(left*49.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    createUp();
  glPopMatrix();
}

void Brazo::createDown(){
  //std::cout << "Parte de abajo\n";
  glPushMatrix();
    GLfloat color[] = {skin_r, skin_g, skin_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    glTranslatef(0.0, 0.0, -0.35);
    glScalef(0.2, 0.2, 0.2);
    glutSolidDodecahedron();
  glPopMatrix();
}

void Brazo::createUp(){
  //std::cout << "Parte de arriba\n";
  glPushMatrix();
    glRotatef(left*a_a_front, 0.0, 1.0, 0.0);
    glRotatef(a_a_up, 1.0, 0.0, 0.0);
    GLfloat color[] = {cs_r, cs_g, cs_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    gluCylinder(qobj, 0.3, 0.4, 1, 50, 50);
    createMiddle();
  glPopMatrix();
}

void Brazo::createMiddle(){
  //std::cout << "Parte de en medio.\n";
  glPushMatrix();
    glRotatef(a_e_up, 1.0, 0.0, 0.0);
    glRotatef(a_e_r, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.7);
    GLfloat color[] = {skin_r, skin_g, skin_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    gluCylinder(qobj, 0.2, 0.3, 0.7, 50, 50);
    createDown();
  glPopMatrix();
}
void Brazo::setColorShirt(float r, float g, float b){
  cs_r = r;
  cs_g = g;
  cs_b = b;
}

void Brazo::armUp(){
  if(a_a_up < a_a_up_max)
    a_a_up++;
}

void Brazo::armDown(){
  if(a_a_up > 0)
    a_a_up--;
}

void Brazo::armFront(){
  if(a_a_front < a_a_front_max)
    a_a_front++;
}

void Brazo::armBack(){
  if(a_a_front > -1*a_a_front_max)
    a_a_front--;
}

void Brazo::middleUp(){
  if(a_e_up < a_e_up_max)
    a_e_up++;
}

void Brazo::middleDown(){
  if(a_e_up > 0)
    a_e_up--;
}

void Brazo::middleR(){
  if(a_e_r < a_e_r_max)
    a_e_r++;
}

void Brazo::middleL(){
  if(a_e_r > 0)
    a_e_r--;
}
