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
        cubes[i].nx=0;
        cubes[i].ny=1;
        cubes[i].nz=0;
        /*glBegin(GL_POINTS);
            glNormal3f(cubes[i].nx, cubes[i].ny, cubes[i].nz);
            glVertex3f(cubes[i].x, cubes[i].y, cubes[i].z);
        glEnd();*/
        printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
        
        
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
void draw_rubik(double fi, int flag){

    glPushMatrix();
    
    for(int i=0;i<CUBE_MAX;i++){
        
        double x, y, z;
        x=cubes[i].x;
        y=cubes[i].y;
        z=cubes[i].z;
        
        glPushMatrix();
        
        
    
        if(flag==1){
            if(cubes[i].x==1){
                printf("RIGHT \n\n");
                glPushMatrix();
                    glRotatef(fi, 1, 0 , 0);
                    glPushMatrix();
                        glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                        draw_cube(cubes[i]);
                    glPopMatrix();
                glPopMatrix();
                if(fi==90 || fi ==-90){
                    glPushMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(fi, 1, 0 , 0);
                        glGetFloatv(GL_MODELVIEW_MATRIX, rot);
                    glPopMatrix();
                    
                    printf("pre \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
                    
                    cubes[i].x=x*rot[0]+y*rot[4]+z*rot[8]+rot[12];
                    cubes[i].y=x*rot[1]+y*rot[5]+z*rot[9]+rot[13];
                    cubes[i].z=x*rot[2]+y*rot[6]+z*rot[10]+rot[14];
                    printf("posle \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
            
                }
                    
            }
            /*else{
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                draw_cube(cubes[i]);
            }*/
            
        }
        else if(flag==2){
            if(cubes[i].x==-1){
                printf("LEFT \n\n");
                glPushMatrix();
                    glRotatef(fi, 1, 0 , 0);
                    glPushMatrix();
                        glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                        draw_cube(cubes[i]);
                    glPopMatrix();
                glPopMatrix();
                
                if(fi==90 || fi ==-90){
                    glPushMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(fi, 1, 0 , 0);
                        glGetFloatv(GL_MODELVIEW_MATRIX, rot);
                    glPopMatrix();
                
                    printf("pre \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
                    
                    cubes[i].x=x*rot[0]+y*rot[4]+z*rot[8]+rot[12];
                    cubes[i].y=x*rot[1]+y*rot[5]+z*rot[9]+rot[13];
                    cubes[i].z=x*rot[2]+y*rot[6]+z*rot[10]+rot[14];
                            
                    printf("posle \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
            
                }
                
            }
        }
        else if(flag==3){
                printf("UP %lf \n\n", fi);
            /*if(i==6 || i==24){
                glRotatef(fi, 0, 1 , 0);
                glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                draw_cube(cubes[i]);
            }*/
            if(cubes[i].y==1){
                //printf("cubes[%i]\n", i);
                glPushMatrix();
                    glRotatef(fi, 0, 1 , 0);
                    glPushMatrix();
                        glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                        draw_cube(cubes[i]);
                    glPopMatrix();
                glPopMatrix();
                if(fi==90|| fi ==-90.0){
                    glPushMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(fi, 0, 1 , 0);
                        glGetFloatv(GL_MODELVIEW_MATRIX, rot);
                    glPopMatrix();
                    
                     printf("pre \n");
                     printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
                    
                    cubes[i].x=x*rot[0]+y*rot[4]+z*rot[8]+rot[12];
                    cubes[i].y=x*rot[1]+y*rot[5]+z*rot[9]+rot[13];
                    cubes[i].z=x*rot[2]+y*rot[6]+z*rot[10]+rot[14];
                            
                     printf("posle \n");
                     printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
            
                }
            }
        }
        else if(flag==4){
            if(cubes[i].y==-1){
                printf("DOWN \n\n");
                glPushMatrix();
                    glRotatef(fi, 0, 1 , 0);
                    glPushMatrix();
                        glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                        draw_cube(cubes[i]);
                    glPopMatrix();
                glPopMatrix();
                if(fi==90 || fi ==-90){
                    glPushMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(fi, 0, 1 , 0);
                        glGetFloatv(GL_MODELVIEW_MATRIX, rot);
                    glPopMatrix();
                    
                    printf("pre \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
                    
                    cubes[i].x=x*rot[0]+y*rot[4]+z*rot[8]+rot[12];
                    cubes[i].y=x*rot[1]+y*rot[5]+z*rot[9]+rot[13];
                    cubes[i].z=x*rot[2]+y*rot[6]+z*rot[10]+rot[14];
                            
                    printf("posle \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
            
                }
            }
        }
        else if(flag==5){
            if(cubes[i].z==1){
                printf("FRONT\n");
                glPushMatrix();
                    glRotatef(fi, 0, 0 , 1);
                    glPushMatrix();
                        glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                        draw_cube(cubes[i]);
                    glPopMatrix();
                glPopMatrix();

                if(fi==90 || fi ==-90){
                    
                    glPushMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(fi, 0, 0 , 1);
                        glGetFloatv(GL_MODELVIEW_MATRIX, rot);
                    glPopMatrix();
                    
                    printf("pre \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
                    
                    cubes[i].x=x*rot[0]+y*rot[4]+z*rot[8]+rot[12];
                    cubes[i].y=x*rot[1]+y*rot[5]+z*rot[9]+rot[13];
                    cubes[i].z=x*rot[2]+y*rot[6]+z*rot[10]+rot[14];
                    printf("posle \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
            
                }
            }
        }
        else if(flag==6){
            if(cubes[i].z==-1){
                printf("BACK\n");
                glPushMatrix();
                    glRotatef(fi, 0, 0 , 1);
                    glPushMatrix();
                        glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
                        draw_cube(cubes[i]);
                    glPopMatrix();
                glPopMatrix();
                
                if(fi==90 || fi ==-90){
                    printf("usao\n");
                    glPushMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(fi, 0, 0 , 1);
                        glGetFloatv(GL_MODELVIEW_MATRIX, rot);
                    glPopMatrix();
                    
                    printf("pre \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
                    
                    cubes[i].x=x*rot[0]+y*rot[4]+z*rot[8]+rot[12];
                    cubes[i].y=x*rot[1]+y*rot[5]+z*rot[9]+rot[13];
                    cubes[i].z=x*rot[2]+y*rot[6]+z*rot[10]+rot[14];
                            
                    printf("posle \n");
                    printf("cubes[%i] xyz %lf %lf %lf\n", i, cubes[i].x, cubes[i].y,cubes[i].z);
            
                }
            }
        }
        else{
            glTranslatef(cubes[i].x, cubes[i].y, cubes[i].z);
            draw_cube(cubes[i]);
        }
            
        glPopMatrix();
        
    }
    glPopMatrix();
    
}



