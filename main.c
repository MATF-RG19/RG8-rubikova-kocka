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
    //fja provere niza
    /*for(int i=0;i<CUBE_MAX;i++){
        
        if(i<=8){
            printf("top layer:\n");
            if(cubes[i].type==THREE_SIDES){
                printf("%i three\n", i);
            }
            else if(cubes[i].type==ONE_SIDE){
                printf("%i one\n", i);
            }
            else if(cubes[i].type==TWO_SIDES){
                printf("%i two\n", i);
            }
        }
        else if(i>=9 && i<=16){
            printf("middle layer:\n");
            if(cubes[i].type==ONE_SIDE){
                printf("%i one\n", i);
            }
            else if(cubes[i].type==TWO_SIDES){
                printf("%i two\n", i);
            }
        }
        else if(i>=17){
            printf("bottom layer:\n");
            if(cubes[i].type==THREE_SIDES){
                printf("%i three\n", i);
            }
            else if(cubes[i].type==ONE_SIDE){
                printf("%i one\n", i);
            }
            else if(cubes[i].type==TWO_SIDES){
                printf("%i two\n", i);
            }
        }
        
    }*/
    glutSwapBuffers();
}
