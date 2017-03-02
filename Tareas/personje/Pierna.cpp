#include "Pierna.h"

Pierna::Pierna(float x, float y, float z, float r, float g, float b, bool lf){
  pos_x = x; pos_y = y; pos_z = z;
  cs_r = r; cs_g = g; cs_b = b;
  left = (lf)? -1.0 : 1.0;
  //std::cout << "Creando Pierna\n";
  qobj = gluNewQuadric();
}

Pierna::~Pierna(){
  //delete qobj;
}

void Pierna::Draw(){
  glPushMatrix();
    glRotatef(left*a_hip_sides, 0.0, 0.0, 1.0);
    glRotatef(a_hip_front, 1.0, 0.0, 0.0);
    glTranslatef(left*pos_x, pos_y, pos_z);
    glRotatef(left*149.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    createUp();
  glPopMatrix();
}

void Pierna::createDown(){
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

void Pierna::createUp(){
  //std::cout << "Parte de arriba\n";
  glPushMatrix();
    GLfloat color[] = {cs_r, cs_g, cs_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    gluCylinder(qobj, 0.3, 0.4, 1.4, 50, 50);
    createMiddle();
  glPopMatrix();
}

void Pierna::createMiddle(){
  //std::cout << "Parte de en medio.\n";
  glPushMatrix();
    glRotatef(a_knee_front, -1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -0.8);
    GLfloat color[] = {skin_r, skin_g, skin_b, 1.0};
    GLfloat mat_shiness[] = {128.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
    gluCylinder(qobj, 0.2, 0.3, 0.8, 50, 50);
    createDown();
  glPopMatrix();
}
void Pierna::setColorPants(float r, float g, float b){
  cs_r = r;
  cs_g = g;
  cs_b = b;
}

void Pierna::legUp(){
  if(a_hip_front < a_hip_front_max)
    a_hip_front++;
}

void Pierna::legDown(){
  if(a_hip_front > -1*a_hip_front_max)
    a_hip_front--;
}

void Pierna::legOpen(){
  if(a_hip_sides < a_hip_sides_max)
    a_hip_sides++;
}

void Pierna::legClose(){
  if(a_hip_sides > 0)
    a_hip_sides--;
}

void Pierna::bendKnee(){
  if(a_knee_front < a_knee_front_max)
    a_knee_front++;
}

void Pierna::extendKnee(){
  if(a_knee_front > 0)
    a_knee_front--;
}
