#include "lib.h"
#ifndef COLORS_H
#define COLORS_H
#include "colors.h"
#endif

float curr_normal[3];
extern void draw_cube(cube c){
    
    double color[3];
    double x;
    x=0.45;
    
    assign_colors(c.clrs[0], &color);
    glColor3f(color[0], color[1], color[2]);
    
    glPushMatrix();
    //donja strana
//     int i, j, k;
//     i=0;
//     j=1;
//     k=2;
    glBegin(GL_POLYGON);
        //glNormal3f(c.normals[i], c.normals[j], c.normals[k]);
        glNormal3f(0, -1, 0);
        glVertex3f(x, -x, x);
        glVertex3f(x,  -x, -x);
        glVertex3f(-x, -x, -x);
        glVertex3f(-x, -x, x);
    glEnd();
//     glGetFloatv(GL_CURRENT_NORMAL, curr_normal);
//     printf("donja %f %f %f\n", curr_normal[0], curr_normal[1], curr_normal[2]);
    //prednja strana
    assign_colors(c.clrs[1], &color);
    glColor3f(color[0], color[1], color[2]);
//     i=3;
//     j=4;
//     k=5;
    glBegin(GL_POLYGON);
//         glNormal3f(c.normals[i], c.normals[j], c.normals[k]);
        glNormal3f(0, 0, 1);
        glVertex3f(x, -x, x);
        glVertex3f(x,  x, x);
        glVertex3f(-x, x, x);
        glVertex3f(-x, -x, x);
    glEnd();
//     glGetFloatv(GL_CURRENT_NORMAL, curr_normal);
//         printf("prednja %f %f %f\n", curr_normal[0], curr_normal[1], curr_normal[2]);
    //desna strana
    assign_colors(c.clrs[2], &color);
    glColor3f(color[0], color[1], color[2]);
//     i=6;
//     j=7;
//     k=8;
    glBegin(GL_POLYGON);
//         glNormal3f(c.normals[i], c.normals[j], c.normals[k]);
        glNormal3f(1, 0, 0);
        glVertex3f(x, -x, x);
        glVertex3f(x,  -x, -x);
        glVertex3f(x, x, -x);
        glVertex3f(x, x, x);
    glEnd();
//     glGetFloatv(GL_CURRENT_NORMAL, curr_normal);
//         printf("desna %f %f %f\n", curr_normal[0], curr_normal[1], curr_normal[2]);
    //zadnja strana
    assign_colors(c.clrs[3], &color);
    glColor3f(color[0], color[1], color[2]);
//     i=9;
//     j=10;
//     k=11;
    glBegin(GL_POLYGON);
//         glNormal3f(c.normals[i], c.normals[j], c.normals[k]);
        glNormal3f(0, 0, -1);
        glVertex3f(x, -x, -x);
        glVertex3f(x,  x, -x);
        glVertex3f(-x, x, -x);
        glVertex3f(-x, -x, -x);
    glEnd();
//     glGetFloatv(GL_CURRENT_NORMAL, curr_normal);
//         printf("zadnja %f %f %f\n", curr_normal[0], curr_normal[1], curr_normal[2]);
    //leva strana
    assign_colors(c.clrs[4], &color);
    glColor3f(color[0], color[1], color[2]);
//     i=12;
//     j=13;
//     k=14;
    glBegin(GL_POLYGON);
//         glNormal3f(c.normals[i], c.normals[j], c.normals[k]);
        glNormal3f(-1, 0, 0);
        glVertex3f(-x, -x, -x);
        glVertex3f(-x,  x, -x);
        glVertex3f(-x, x, x);
        glVertex3f(-x, -x, x);
    glEnd();
//     glGetFloatv(GL_CURRENT_NORMAL, curr_normal);
//         printf("leva %f %f %f\n", curr_normal[0], curr_normal[1], curr_normal[2]);
    //gornja strana
    assign_colors(c.clrs[5], &color);
    glColor3f(color[0], color[1], color[2]);
//     i=15;
//     j=16;
//     k=17;
    glBegin(GL_POLYGON);
//         glNormal3f(c.normals[i], c.normals[j], c.normals[k]);
        glNormal3f(0, 1, 0);
        glVertex3f(x, x, x);
        glVertex3f(x,  x, -x);
        glVertex3f(-x, x, -x);
        glVertex3f(-x, x, x);
    glEnd();
//     glGetFloatv(GL_CURRENT_NORMAL, curr_normal);
//         printf("gornja %f %f %f\n", curr_normal[0], curr_normal[1], curr_normal[2]);
    glPopMatrix();
    
}
void assign_colors(clr t, double (*color)[3]){
    
    if(t==yellow){
        double c[]={YELLOW};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        
        return;
    }
    if(t==white){
        double c[]={WHITE};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        return;
    }
    if(t==blue){
        double c[]={BLUE};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        return;
    }
    if(t==red){
        double c[]={RED};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        return;
    }
    if(t==green){
        double c[]={GREEN};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        return;
    }
    if(t==orange){
        double c[]={ORANGE};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        return;
    }
    if(t==black){
        double c[]={BLACK};
        for(int i=0;i<3;i++){
            (*color)[i]=c[i];
        }
        return;
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
    if(colors[0]==0 && colors[1]==0 && colors[2]==0){
        return black;
    }
    return -1;
}

void init_colors(cube *c){
    
    for(int i=0;i<3;i++){
        c->clrs[i]=-1;
    }
}
