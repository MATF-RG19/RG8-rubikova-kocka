#include "lib.h"


extern void cube3(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, 0.6);
        glVertex3f(-0.5, -0.5, 0.6);
        glVertex3f(-0.5, 0.5, 0.6);
        glVertex3f(0.5, 0.5, 0.6);
    glEnd();
    glColor3f(r2, g2, b2);
    glBegin(GL_POLYGON);
        glVertex3f(0.6, -0.5, 0.5);
        glVertex3f(0.6, -0.5, -0.5);
        glVertex3f(0.6, 0.5, -0.5);
        glVertex3f(0.6, 0.5, 0.5);
    glEnd();
    glColor3f(r3, g3, b3);
    glBegin(GL_POLYGON);
        glVertex3f(-0.6, -0.5, 0.5);
        glVertex3f(-0.6, -0.5, -0.5);
        glVertex3f(-0.6, 0.5, -0.5);
        glVertex3f(-0.6, 0.5, 0.5);
    glEnd();
    
    
}
extern void cube2(int r1, int g1, int b1, int r2, int g2, int b2){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, 0.6);
        glVertex3f(-0.5, -0.5, 0.6);
        glVertex3f(-0.5, 0.5, 0.6);
        glVertex3f(0.5, 0.5, 0.6);
    glEnd();
    glColor3f(r2, g2, b2);
    glBegin(GL_POLYGON);
        glVertex3f(0.6, -0.5, 0.5);
        glVertex3f(0.6, -0.5, -0.5);
        glVertex3f(0.6, 0.5, -0.5);
        glVertex3f(0.6, 0.5, 0.5);
    glEnd();
    
}
extern void cube1(int r, int g, int b){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, 0.6);
        glVertex3f(-0.5, -0.5, 0.6);
        glVertex3f(-0.5, 0.5, 0.6);
        glVertex3f(0.5, 0.5, 0.6);
    glEnd();
    glColor3f(0, 1, 0);
    
}

