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
        cubes[i].x=1;
        cubes[i].y=1;
        cubes[i].z=1;
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
        
    }
}