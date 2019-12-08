#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#ifndef LIB_H
    #define LIB_H
    #include "lib.h"
#endif

#define MAX_MINI 9
static int l=0;

double x=0.6;
double y=0.6;
double z=0.6;

int rr_cubes[MAX_MINI]={0, 1, 2, 9, 10, 11, 17, 18, 19};
int top_cubes[MAX_MINI]={0, 1, 2, 3, 4,5,6,7,8};
//desna rotacija, potrebni indeksi iz niza: 
// top:0, 1, 2
// middle:9, 10, 11
// bottom: 17, 18, 19


//BUG: ideja je bila da rotiram ostale kockice oko sredisnje kockice (slicno ideji sa casa kada smo radili solarni sistem)
void right_rotation(double fi){
    
    
    glPushMatrix();
        glRotatef(fi, 1, 0, 0);
        draw_cube(cubes[rr_cubes[4]], x, y, z);
    glPopMatrix();
    glTranslatef(1.5, 1.5, 1.5);
    for(int i=0;i<MAX_MINI;i++){
        if(i!=4){
            glPushMatrix();
                glRotatef(fi, 1, 0, 0);
                draw_cube(cubes[rr_cubes[i]], x, y, z);
            glPopMatrix();
        }
        
    }
    
}
/*
void top_rotation(double fi){
    
    
    glPushMatrix();
        glRotatef(fi, 0, 1, 0);
        draw_cube(cubes[top_cubes[8]], x, y, z);
        
    glPopMatrix();
    glTranslatef(1.5, 0, 0);
    for(int i=0;i<MAX_MINI;i++){
        if(i!=4){
            glPushMatrix();
                glRotatef(fi/2, 1, 0, 0);
                draw_cube(cubes[top_cubes[i]], x, y, z);
            glPopMatrix();
        }
        
    }
    
}*/
void middle_layer(){
    
    cube c;
    
    
    double middle_colors[4][3]={{GREEN}, {BLUE}, {YELLOW}, {RED}};
    
    double factor = 1.5;
    int ind=0;
    glTranslatef(0, -factor, 0);
    
    for(int i=0, k=0;i<8;i++, l++){
        
        init_colors(&c);
        if(i%2==0){
            c.type=TWO_SIDES;
            double tmp1[3];
            for(int j=0;j<3;j++){
                tmp1[j]=middle_colors[k%4][j%3];
            }
            c.clrs[0]=recognize_color(tmp1);
            for(int j=0;j<3;j++){
                tmp1[j]=middle_colors[(k+1)%4][j%3];
                
            }
            c.clrs[1]=recognize_color(tmp1);
            
            glTranslatef(factor,0 , 0);
            ind++;
            cubes[l]=c;
            k++;
            draw_cube(c, x, y, z);
        }
        else{
            c.type=ONE_SIDE;
            double tmp2[3];
            for(int j=0;j<3;j++){
                tmp2[j]=middle_colors[k%4][j%3];
            }
            c.clrs[0]=recognize_color(tmp2);
            
            cubes[l]=c;
            
            glRotatef(90, 0, 1, 0);
            if(ind==2){
                glTranslatef(-factor,0 , 0);
                ind=0;
            }
            else{
                glTranslatef(factor,0 , 0);
            }
                
            ind++;
            draw_cube(c, x, y, z);
                
            
        }
    }
    
}

void bottom_layer(){
    
    cube c;
    
    y=-0.6;
    
    double bottom_colors[5][3]={{GREEN}, {BLUE}, {YELLOW}, {RED}, {ORANGE}};
    
    double factor = 1.5;
    int ind=0;
    glTranslatef(0, -factor, 0);
    
    
    for(int k=0, i=0;i<8;i++, l++){
        
        init_colors(&c);
        if(i%2==0){
            c.type=THREE_SIDES;
            double tmp1[3];
            for(int j=0;j<3;j++){
                tmp1[j]=bottom_colors[k%4][j%3];
            }
            c.clrs[0]=recognize_color(tmp1);
            for(int j=0;j<3;j++){
                tmp1[j]=bottom_colors[(k+1)%4][j%3];
                
            }
            c.clrs[1]=recognize_color(tmp1);
            for(int j=0;j<3;j++){
                tmp1[j]=bottom_colors[4][j%3];
                
            }
            c.clrs[2]=recognize_color(tmp1);
            
            glTranslatef(factor,0 , 0);
            
            ind++;
            cubes[l]=c;
            k++;
            draw_cube(c, x, y, z);
        }
        else{
            c.type=TWO_SIDES;
            double tmp2[3];
            for(int j=0;j<3;j++){
                tmp2[j]=bottom_colors[k%4][j%3];
            }
            c.clrs[0]=recognize_color(tmp2);
            for(int j=0;j<3;j++){
                tmp2[j]=bottom_colors[4][j%3];
            }
            c.clrs[1]=recognize_color(tmp2);
            
            cubes[l]=c;
            
            
            glRotatef(90, 0, 1, 0);
            if(ind==2){
                glTranslatef(-factor,0 , 0);
                
                ind=0;
            }
            else{
                glTranslatef(factor,0 , 0);
                
            }
                
            ind++;
           
             glPushMatrix();
                glRotatef(-90, 0, 0, 1);
                draw_cube(c, x, y, z);
            glPopMatrix();
                
            
        }
           
    }
   c.type=ONE_SIDE;
    
    double color[]={ORANGE};
    init_colors(&c);
    c.clrs[0]=recognize_color(color);
    
    glPushMatrix();
        glTranslatef(0,0,-factor);
        glRotatef(90, 1, 0, 0);
        cubes[l++]=c;
        draw_cube(c, x, y, z);
    glPopMatrix();
    
}
void top_layer(){
    
    
    cube c;
    
    
    
    double top_colors[5][3]={{GREEN}, {BLUE}, {YELLOW}, {RED}, {WHITE}};
    
    double factor = 1.5;
    int ind=0;
    
    
    for(int i=0, k=0;i<8;i++, l++){
        
        init_colors(&c);
        if(i%2==0){
            c.type=THREE_SIDES;
            double tmp1[3];
            for(int j=0;j<3;j++){
                tmp1[j]=top_colors[k%4][j%3];
            }
            c.clrs[0]=recognize_color(tmp1);
            for(int j=0;j<3;j++){
                tmp1[j]=top_colors[(k+1)%4][j%3];
                
            }
            c.clrs[1]=recognize_color(tmp1);
            for(int j=0;j<3;j++){
                tmp1[j]=top_colors[4][j%3];
                
            }
            c.clrs[2]=recognize_color(tmp1);
            
            
            glTranslatef(factor,0 , 0);
            
            
            ind++;
            
            k++;
            
            draw_cube(c, x, y, z);
            
            cubes[l]=c;
        }
        else{
            c.type=TWO_SIDES;
            double tmp2[3];
            for(int j=0;j<3;j++){
                tmp2[j]=top_colors[k%4][j%3];
            }
            c.clrs[0]=recognize_color(tmp2);
            for(int j=0;j<3;j++){
                tmp2[j]=top_colors[4][j%3];
            }
            c.clrs[1]=recognize_color(tmp2);
            
            
            
            glRotatef(90, 0, 1, 0);
            
            
            if(ind==2){
                glTranslatef(-factor,0 , 0);
                
                ind=0;
                
            }
            else{
                glTranslatef(factor,0 , 0);
                
                
            }
                
            ind++;
            glPushMatrix();
                glRotatef(90, 0, 0, 1);
                draw_cube(c, x, y, z);
            glPopMatrix();
            
            cubes[l]=c;
                
            
        }
        
    }
    
    c.type=ONE_SIDE;
    double color[]={WHITE};
    init_colors(&c);
    c.clrs[0]=recognize_color(color);
    
    glPushMatrix();
        glTranslatef(0,0,-factor);
        glRotatef(-90, 1, 0, 0);
        draw_cube(c, x, y, z);
    glPopMatrix();
    
    
    
    cubes[l++]=c;
    
}
