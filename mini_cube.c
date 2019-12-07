#include "lib.h"
#ifndef COLORS_H
#define COLORS_H
#include "colors.h"
#endif


extern void draw_cube(cube c , double colors[COLOR_MAX][COLOR_MAX], double x, double y, double  z){
    
    
    if(c.type==ONE_SIDE){
        draw_cube1( colors[0], x, y, z);
        
    }
    if(c.type==TWO_SIDES){
        draw_cube2( colors[0], colors[1], x, y, z);
        
    }
    if(c.type==THREE_SIDES){

        draw_cube3( colors[0], colors[1], colors[2], x, y, z);
    }
}
extern void draw_cube3( double color1[], double color2[], double color3[], double x, double y, double  z){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color1[0], color1[1], color1[2]);
    glBegin(GL_POLYGON);
        glVertex3f(x, -y, z);
        glVertex3f(-x,  -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(x, y, z);
    glEnd();
    glColor3f(color2[0], color2[1], color2[2]);
    glBegin(GL_POLYGON);
        glVertex3f(x, -y, x);
        glVertex3f(x, -y, -x);
        glVertex3f(x, y, -x);
        glVertex3f(x, y, x);
        
    glEnd();
    glColor3f(color3[0], color3[1], color3[2]);
    
    glBegin(GL_POLYGON);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glVertex3f(-x, y, -z);
        glVertex3f(-x, y, z);
        
    glEnd();
    
    
}
extern void draw_cube2(double color1[], double color2[], double x, double y, double  z){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color1[0], color1[1], color1[2]);
    glBegin(GL_POLYGON);
        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(-x,y, z);
        glVertex3f(-x, -y, z);
        
    glEnd();
    glColor3f(color2[0], color2[1], color2[2]);
    glBegin(GL_POLYGON);
        glVertex3f(x, -y, z);
        glVertex3f(x, -y, -z);
        glVertex3f(x, y, -z);
        glVertex3f(x, y, z);
    glEnd();
    
}
extern void draw_cube1(double color[], double x, double y, double  z){
    
    glColor3f(0, 0, 0);
    glutSolidCube(1);
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, -y, z);
    glEnd();
    
    
}
void assign_colors(double all_colors[], cube c){
    
    if(c.type==ONE_SIDE){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
        }
        c.clrs[0]=recognize_color(colors[0]);
    }
    else if(c.type==TWO_SIDES){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
            colors[1][i]=all_colors[3+i];
        }
        c.clrs[0]=recognize_color(colors[0]);
        c.clrs[1]=recognize_color(colors[1]);
    }
    else if(c.type==THREE_SIDES){
        for(int i=0;i<COLOR_MAX;i++){
            colors[0][i]=all_colors[i];
            colors[1][i]=all_colors[3+i];
            colors[2][i]=all_colors[6+i];
            
        }
        c.clrs[0]=recognize_color(colors[0]);
        c.clrs[1]=recognize_color(colors[1]);
        c.clrs[2]=recognize_color(colors[2]);
       
    }
    
    
    
}

enum all_cube_colors recognize_color(double colors[] ){
    
    if(colors[0]==1 && colors[1]==1 && colors[2]==1){
        return white;
    }
    if(colors[0]==0.8 && colors[1]==0.8 && colors[2]==0){
        return yellow;
    }
    if(colors[0]==0 && colors[1]==0.3 && colors[2]==0.68){
        return blue;
    }
    if(colors[0]==0 && colors[1]==0.4 && colors[2]==0.2){
        return green;
    }
    if(colors[0]==0.5 && colors[1]==0 && colors[2]==0){
        return red;
    }
    if(colors[0]==1 && colors[1]==0.5 && colors[2]==0){
        return orange;
    }
    return 0;
}

void init_colors(cube c){
    
    for(int i=0;i<3;i++){
        c.clrs[i]=-1;
    }
}
