#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#ifndef LIB_H
    #define LIB_H
    #include "lib.h"
#endif


extern void init_rubik(){
    
    
    for(int i=0;i<CUBE_MAX;i++){
        
        int mod=i%9;
        if(i%3==0){
            cubes[i].x=1;
            
        }
        else if(i%3==1){
            cubes[i].x=0;
        }
        else{
            cubes[i].x=-1;
        }
        if(i/9==0){
            cubes[i].y=1;
            
        }
        else if(i/9==1){
            cubes[i].y=0;
        }
        else if(i/9==2){
            cubes[i].y=-1;
        }
        
        if(mod<3){
            cubes[i].z=1;
        }
        else if(mod>=3 && mod<6){
            cubes[i].z=0;
        }
        else{
            cubes[i].z=-1;
        }
        cubes[i].nx=cubes[i].x;
        cubes[i].ny=1;
        cubes[i].nz=cubes[i].z;
        
    }
    //0 donja, 1 prednja, 2 desna, 3 zadnja, 4 leva, 5 gornja
    for(int i=0;i<CUBE_MAX;i++){
        if(cubes[i].y==1){
            cubes[i].clrs[5]=white;
            cubes[i].clrs[0]=black;
        }
        else if(cubes[i].y==0){
            cubes[i].clrs[5]=black;
            cubes[i].clrs[0]=black;
        }
        else{
            cubes[i].clrs[5]=black;
            cubes[i].clrs[0]=orange;
        }
        if(cubes[i].x==1){
            cubes[i].clrs[2]=blue;
            cubes[i].clrs[4]=black;
        }
        else if(cubes[i].x==0){
            cubes[i].clrs[2]=black;
            cubes[i].clrs[4]=black;
        }
        else{
            cubes[i].clrs[2]=black;
            cubes[i].clrs[4]=green;
        }
        if(cubes[i].z==1){
            cubes[i].clrs[3]=black;
            cubes[i].clrs[1]=red;
        }
        else if(cubes[i].z==0){
            cubes[i].clrs[3]=black;
            cubes[i].clrs[1]=black;
        }
        else{
            cubes[i].clrs[3]=yellow;
            cubes[i].clrs[1]=black;
        }
    }
    
    
}
void draw_rubik(){
    
    
    for(int i=0;i<CUBE_MAX;i++){
        
        double x, y, z;
        x=cubes[i].x;
        y=cubes[i].y;
        z=cubes[i].z;
        glPushMatrix();
            glTranslatef(x, y, z);
            draw_cube(cubes[i]);
        glPopMatrix();
        
        
        
    }
}
