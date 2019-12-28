#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "lib.h"

#define TIMER_ID (0)
#define TIMER_INT (100)



static int window_width;
static int window_height;
static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void init();
static int animation_ongoing=0;
double fi=0;
int factor;
int flag;



int main(int argc, char **argv){
    
    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(on_keyboard);
    
    
    
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    
    
    glClearColor(0.7, 0.7, 0.7, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    init_rubik();
    
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
    
   

    
    
    draw_rubik(fi, flag);
    
    
    
    
}

static void on_timer(int value){
    
    if(value!=TIMER_ID){
        return;
    }
    
    fi+=factor;
    
         
    if(fi>90 || fi<-90){
        animation_ongoing=0;
        flag=0;
        fi=0;
        
        return;
    }
    
    
    glutPostRedisplay();
    if (animation_ongoing)
        glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
    
}
static void on_keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'r':
            //flag=1
            
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=1;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            
            break;
        case 'R':
            //flag=1
            
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=1;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            
            break;
            
        case 'l':
            //flag=2
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=2;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            
            break;
        case 'L':
            //flag=2
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=2;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            
            break;
            
        case 'u':
            //flag=3
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=3;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
            
        case 'U':
            //flag=3
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=3;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            break;
        case 'd':
            //flag=4
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=4;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'D':
            //flag=4
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=4;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'f':
            //             flag=5;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=5;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'F':
            //             flag=5;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=5;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'b':
            //             flag=6;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=6;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'B':
//             flag=6;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=6;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 's':
        case 'S':
            animation_ongoing=0;
            break;
        default:
            animation_ongoing=0;
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
