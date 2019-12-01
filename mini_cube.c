#include "lib.h"
#include "colors.h"

extern void draw_cube(cube c , int color[COLOR_MAX][COLOR_MAX]){
    
    
    if(c.type==ONE_SIDE){
        draw_cube1(c, color[0]);
    }
    if(c.type==TWO_SIDES){
        draw_cube2(c, color[0], color[1]);
    }
    if(c.type==THREE_SIDES){
        draw_cube3(c, color[0], color[1], color[2]);
    }
}
extern void draw_cube3(cube c, int color1[], int color2[], int color3[]){
    
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
        glVertex3f(c.z, -c.x, c.y);
        glVertex3f(c.z, -c.x, -c.y);
        glVertex3f(c.z, c.x, -c.y);
        glVertex3f(c.z, c.x, c.y);
        
    glEnd();
    glColor3f(color3[0], color3[1], color3[2]);
    glBegin(GL_POLYGON);
        glVertex3f(-c.z, -c.x, c.y);
        glVertex3f(-c.z, -c.x, -c.y);
        glVertex3f(-c.z, c.x, -c.y);
        glVertex3f(-c.z, c.x, c.y);
        
    glEnd();
    
    
}
extern void draw_cube2(cube c, int color1[], int color2[]){
    
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
        glVertex3f(c.z, -c.x, c.y);
        glVertex3f(c.z, -c.x, -c.y);
        glVertex3f(c.z, c.x, -c.y);
        glVertex3f(c.z, c.x, c.y);
    glEnd();
    
}
extern void draw_cube1(cube c,int color[]){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
        glVertex3f(c.x, -c.y, c.z);
        glVertex3f(-c.x, -c.y, c.z);
        glVertex3f(-c.x, c.y, c.z);
        glVertex3f(c.x, c.y, c.z);
    glEnd();
    
    
}
void assign_colors(int all_colors[], int type){
    
    if(type==ONE_SIDE){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
        }
    }
    else if(type==TWO_SIDES){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
            colors[1][i]=all_colors[2+i];
        }
    }
    else if(type==THREE_SIDES){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
            colors[1][i]=all_colors[2+i];
            colors[2][i]=all_colors[4+i];
        }
    }
    
}

