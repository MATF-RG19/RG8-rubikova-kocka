#include "lib.h"
#include "colors.h"

extern void draw_cube(cube c , double colors[COLOR_MAX][COLOR_MAX]){
    
    
    if(c.type==ONE_SIDE){
        draw_cube1(c, colors[0]);
    }
    if(c.type==TWO_SIDES){
        draw_cube2(c, colors[0], colors[1]);
    }
    if(c.type==THREE_SIDES){

        draw_cube3(c, colors[0], colors[1], colors[2]);
    }
}
extern void draw_cube3(cube c, double color1[], double color2[], double color3[]){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color1[0], color1[1], color1[2]);
    glBegin(GL_POLYGON);
        glVertex3f(c.x, -c.y, c.z);
        glVertex3f(-c.x, -c.y, c.z);
        glVertex3f(-c.x, c.y, c.z);
        glVertex3f(c.x, c.y, c.z);
    glEnd();
    glColor3f(color2[0], color2[1], color2[2]);
    glBegin(GL_POLYGON);
        glVertex3f(c.x, -c.y, c.x);
        glVertex3f(c.x, -c.y, -c.x);
        glVertex3f(c.x, c.y, -c.x);
        glVertex3f(c.x, c.y, c.x);
        
    glEnd();
    glColor3f(color3[0], color3[1], color3[2]);
    
    glBegin(GL_POLYGON);
        glVertex3f(c.x, c.y, c.z);
        glVertex3f(c.x, c.y, -c.z);
        glVertex3f(-c.x, c.y, -c.z);
        glVertex3f(-c.x, c.y, c.z);
        
    glEnd();
    
    
}
extern void draw_cube2(cube c, double color1[], double color2[]){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color1[0], color1[1], color1[2]);
    glBegin(GL_POLYGON);
        glVertex3f(c.x, -c.y, c.z);
        glVertex3f(c.x, c.y, c.z);
        glVertex3f(-c.x, c.y, c.z);
        glVertex3f(-c.x, -c.y, c.z);
        
    glEnd();
    glColor3f(color2[0], color2[1], color2[2]);
    glBegin(GL_POLYGON);
        glVertex3f(c.x, -c.y, c.z);
        glVertex3f(c.x, -c.y, -c.z);
        glVertex3f(c.x, c.y, -c.z);
        glVertex3f(c.x, c.y, c.z);
    glEnd();
    
}
extern void draw_cube1(cube c,double color[]){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
        glVertex3f(c.x, -c.y, c.z);
        glVertex3f(c.x, c.y, c.z);
        glVertex3f(-c.x, c.y, c.z);
        glVertex3f(-c.x, -c.y, c.z);
    glEnd();
    
    
}
void assign_colors(double all_colors[], int type){
    
    if(type==ONE_SIDE){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
        }
    }
    else if(type==TWO_SIDES){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
            colors[1][i]=all_colors[3+i];
        }
    }
    else if(type==THREE_SIDES){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
            colors[1][i]=all_colors[3+i];
            colors[2][i]=all_colors[6+i];
            
        }
       
    }
    
    
    
}

