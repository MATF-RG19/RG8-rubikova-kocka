#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "lib.h"

#define TIMER_ID 0
#define TIMER_INT 500



static int window_width;
static int window_height;
static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void init();
static int animation_ongoing=0;
double fi=0;

int flag;
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
static void on_timer(int value){
    
    if(value!=TIMER_ID){
        return;
    }
    
    fi+=18;
    if(fi>90){
        animation_ongoing=0;
        flag=0;
        return;
    }
    flag=1;
    
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
        case 'R':
            if(!animation_ongoing){
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                animation_ongoing=1;
                
            }
            
            break;
        case 's':
        case 'S':
            animation_ongoing=0;
            break;
        default:
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
            6, 6, -6,
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
        printf("boje:\n");
        for(int j=0;j<3;j++){
            printf("%i ", cubes[i].clrs[j]);
        }
        
    }*/
    
    
    
    if(flag==1){
        printf("flag\n");
        top_rotation(fi);
        printf("rr\n");
        
    }
    
    glutSwapBuffers();
}
