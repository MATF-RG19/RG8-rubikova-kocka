#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "lib.h"




static int window_width;
static int window_height;
static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void init();
static int l=0;

double x=0.6;
double y=0.6;
double z=0.6;
int main(int argc, char **argv){
    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    
    glutMainLoop();

    return 0;
    
    
}
void middle_layer(){
    
    cube c;
    init_colors(c);
    
    double middle_colors[4][3]={{GREEN}, {BLUE}, {YELLOW}, {RED}};
    
    double factor = 1.5;
    int ind=0;
    glTranslatef(0, -factor, 0);
    for(int i=0, k=0;i<8;i++){
        
        if(i%2==0){
            c.type=TWO_SIDES;
            double tmp1[6];
            for(int j=0;j<3;j++){
                tmp1[j]=middle_colors[k%4][j%3];
            }
            for(int j=3;j<6;j++){
                tmp1[j]=middle_colors[(k+1)%4][j%3];
                
            }
            assign_colors(tmp1, c);
            glTranslatef(factor,0 , 0);
            ind++;
            cubes[i]=c;
            k++;
            draw_cube(c, colors, x, y, z);
        }
        else{
            c.type=ONE_SIDE;
            double tmp2[3];
            for(int j=0;j<3;j++){
                tmp2[j]=middle_colors[k%4][j%3];
            }
            assign_colors(tmp2, c);
            cubes[i]=c;
            
            glRotatef(90, 0, 1, 0);
            if(ind==2){
                glTranslatef(-factor,0 , 0);
                ind=0;
            }
            else{
                glTranslatef(factor,0 , 0);
            }
                
            ind++;
            draw_cube(c, colors, x, y, z);
                
            
        }
    }
}

void bottom_layer(){
    
    cube c;
    init_colors(c);
    y=-0.6;
    
    double bottom_colors[5][3]={{GREEN}, {BLUE}, {YELLOW}, {RED}, {ORANGE}};
    
    double factor = 1.5;
    int ind=0;
    glTranslatef(0, -factor, 0);
    
    
    for(int k=0, i=0;i<8;i++){
        
        if(i%2==0){
            c.type=THREE_SIDES;
            double tmp1[9];
            for(int j=0;j<3;j++){
                tmp1[j]=bottom_colors[k%4][j%3];
            }
            for(int j=3;j<6;j++){
                tmp1[j]=bottom_colors[(k+1)%4][j%3];
                
            }
            for(int j=6;j<9;j++){
                tmp1[j]=bottom_colors[4][j%3];
                
            }
            assign_colors(tmp1, c);
            glTranslatef(factor,0 , 0);
            
            ind++;
            cubes[l]=c;
            k++;
            draw_cube(c, colors, x, y, z);
        }
        else{
            c.type=TWO_SIDES;
            double tmp2[6];
            for(int j=0;j<3;j++){
                tmp2[j]=bottom_colors[k%4][j%3];
            }
            for(int j=3;j<6;j++){
                tmp2[j]=bottom_colors[4][j%3];
            }
            assign_colors(tmp2, c);
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
                draw_cube(c, colors, x, y, z);
            glPopMatrix();
                
            
        }
           
    }
   c.type=ONE_SIDE;
    
    double color[]={ORANGE};
    assign_colors(color, c);
    glPushMatrix();
        glTranslatef(0,0,-factor);
        glRotatef(90, 1, 0, 0);
        cubes[++l]=c;
        draw_cube(c, colors, x, y, z);
    glPopMatrix();
    
}
void top_layer(){
    
    
    cube c;
    init_colors(c);
    
    
    double top_colors[5][3]={{GREEN}, {BLUE}, {YELLOW}, {RED}, {WHITE}};
    
    double factor = 1.5;
    int ind=0;
    
    
    for(int i=0, k=0;i<8;i++, l++){
        
        
        if(i%2==0){
            c.type=THREE_SIDES;
            double tmp1[9];
            for(int j=0;j<3;j++){
                tmp1[j]=top_colors[k%4][j%3];
            }
            for(int j=3;j<6;j++){
                tmp1[j]=top_colors[(k+1)%4][j%3];
                
            }
            for(int j=6;j<9;j++){
                tmp1[j]=top_colors[4][j%3];
                
            }
            assign_colors(tmp1, c);
            
            glTranslatef(factor,0 , 0);
            
            
            ind++;
            
            k++;
            
            draw_cube(c, colors, x, y, z);
            
            cubes[l]=c;
        }
        else{
            c.type=TWO_SIDES;
            double tmp2[6];
            for(int j=0;j<3;j++){
                tmp2[j]=top_colors[k%4][j%3];
            }
            for(int j=3;j<6;j++){
                tmp2[j]=top_colors[4][j%3];
            }
            assign_colors(tmp2, c);
            
            
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
                draw_cube(c, colors, x, y, z);
            glPopMatrix();
            
            cubes[l]=c;
                
            
        }
        
    }
    c.type=ONE_SIDE;
    double color[]={WHITE};
    assign_colors(color, c);
    glPushMatrix();
        glTranslatef(0,0,-factor);
        glRotatef(-90, 1, 0, 0);
        draw_cube(c, colors, x, y, z);
    glPopMatrix();
    
    
    
    cubes[++l]=c;
}
void init(){
    
    glPushMatrix();
        glColor3f(1,0,0);
        glBegin(GL_LINES);
            glVertex3f(100,0,0);
            glVertex3f(-100,0,0);
        glEnd();
    glPopMatrix();

    //Iscrtavanje y ose
    glPushMatrix();
        glColor3f(0,1,0); 
        glBegin(GL_LINES); 
            glVertex3f(0,-100,0);
            glVertex3f(0,100,0);
        glEnd();
    glPopMatrix();

    //Iscrtavanje z ose
    glPushMatrix();
        glColor3f(0,0,1); 
        glBegin(GL_LINES);
            glVertex3f(0,0,100);
            glVertex3f(0,0,-100);
        glEnd();
    glPopMatrix();
    
   

    //u nizu cubes su poredjani redom od gornjeg do donjeg sloja 
    top_layer();
    middle_layer();
    bottom_layer();
    
    
    
}
static void on_keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

static void on_reshape(int width, int height){
    
    window_width = width;
    window_height = height;
}
static void on_display(void){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window_width, window_height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 20);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            6, 6, 6,
            0, 0, 0,
            0, 1, 0
        );
    init();
    glutSwapBuffers();
}
