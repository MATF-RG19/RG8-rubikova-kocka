#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#ifndef LIB_H
    #define LIB_H
    #include "lib.h"
#endif

float curr_normal[3];
extern void init_rubik(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    for(int i=0;i<CUBE_MAX;i++){
        
        glGetFloatv(GL_MODELVIEW_MATRIX, cubes[i].ori);
        /*for(int j=0;j<18;j++){
            cubes[i].normals[j]=0;
        }
        
        cubes[i].normals[1]=-1;
        cubes[i].normals[5]=1;
        cubes[i].normals[6]=1;
        cubes[i].normals[11]=-1;
        cubes[i].normals[12]=-1;
        cubes[i].normals[16]=1;*/
        
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
//donja strana 0, 1, 2
// prednja strana 3, 4, 5
//desna 6, 7, 8
// zadnja 9, 10, 11
// leva 12 13 14
//gornja 15 16 17
/*void update_normals(cube *c){
    
    double nx, ny, nz;
    for(int i=0;i<16;i+=3){
            nx=c->normals[i];
            ny=c->normals[i+1];
            nz=c->normals[i+2];
            c->normals[i]=round(nx*rot[0]+ny*rot[4]+nz*rot[8]+rot[12]);
            c->normals[i+1]=round(nx*rot[1]+ny*rot[5]+nz*rot[9]+rot[13]);
            c->normals[i+2]=round(nx*rot[2]+ny*rot[6]+nz*rot[10]+rot[14]);
    }
}*/


void rotate(double fi, int vector[3], cube *c){
    
    double x, y, z;
        x=c->x;
        y=c->y;
        z=c->z;
    glPushMatrix();
        glRotatef(fi, vector[0], vector[1], vector[2]);
        glTranslatef(c->x, c->y, c->z);
        glPushMatrix();
            glMultMatrixf(c->ori);
        
            draw_cube(*c);
        glPopMatrix();
    glPopMatrix();
        
    
        if(fi==90 || fi ==-90){
        
        glPushMatrix();
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(fi, vector[0], vector[1], vector[2]);
            glGetFloatv(GL_MODELVIEW_MATRIX, rot);
            glMultMatrixf(c->ori);
            glGetFloatv(GL_MODELVIEW_MATRIX, c->ori);
        glPopMatrix();
        
        //update_normals(c);
        c->x=round(x*rot[0]+y*rot[4]+z*rot[8]+rot[12]);
        c->y=round(x*rot[1]+y*rot[5]+z*rot[9]+rot[13]);
        c->z=round(x*rot[2]+y*rot[6]+z*rot[10]+rot[14]);
    }

}
void draw_rubik(double fi, int flag){

    glPushMatrix();
    
    for(int i=0;i<CUBE_MAX;i++){
        
        
        
        glPushMatrix();
        
        
    
        if(flag==1){
            
            if(cubes[i].x==1){
                int vector[3]={1, 0, 0};
                rotate(fi, vector, &(cubes[i]));
            }
            else{
                
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                glMultMatrixf(cubes[i].ori);
                draw_cube(cubes[i]);
            }
            
        }
        else if(flag==2){
            if(cubes[i].x==-1){
                int vector[3]={1, 0, 0};
                rotate(fi, vector, &(cubes[i]));
            }
            else{
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                glMultMatrixf(cubes[i].ori);
                draw_cube(cubes[i]);
            }
        }
        else if(flag==3){
                
            if(cubes[i].y==1){
                int vector[3]={0, 1, 0};
                rotate(fi, vector, &(cubes[i]));
            }
            else{
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                glMultMatrixf(cubes[i].ori);
                draw_cube(cubes[i]);
            }
        }
        else if(flag==4){
            if(cubes[i].y==-1){
                int vector[3]={0, 1, 0};
                rotate(fi, vector, &(cubes[i]));
            }
            else{
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                glMultMatrixf(cubes[i].ori);
                draw_cube(cubes[i]);
            }
        }
        else if(flag==5){
            if(cubes[i].z==1){
                int vector[3]={0, 0, 1};
                rotate(fi, vector, &(cubes[i]));
            }
            else{
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                glMultMatrixf(cubes[i].ori);
                draw_cube(cubes[i]);
            }
        }
        else if(flag==6){
            if(cubes[i].z==-1){
                int vector[3]={0, 0, 1};
                rotate(fi, vector, &(cubes[i]));
            }
            else{
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                glMultMatrixf(cubes[i].ori);
                draw_cube(cubes[i]);
            }
        }
        else{
            glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
            glMultMatrixf(cubes[i].ori);
            draw_cube(cubes[i]);
        }
            
        glPopMatrix();
        
    }
    glPopMatrix();
    
}



