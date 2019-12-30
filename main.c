#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "lib.h"
#include <sys/time.h>
#include <time.h>
#define TIMER_ID (0)
#define TIMER_INT (100)
#define START_TIMER_ID (1)



static int window_width;
static int window_height;

static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void start_timer(int value);

static int mouse_x, mouse_y;
static void on_mouse(int button, int state, int x, int y);
static void on_motion(int x, int y);

static void init();
static int animation_ongoing=0;
//angle of rotation
double fi=0;
//parameter for timer interval
double param=1;
double animation_parameter=-1.5;
int factor;
//flag for indicating which rotation is being animated
int flag;
//counter for randomizing cube
int count=0;
//flag for randomizing cube
int index=0;
//rotation matrix updated on mouse motion
static float matrix[16];

int main(int argc, char **argv){
    
    
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow(argv[0]);
    
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };
    GLfloat light_diffuse[] = { 1, 1, 1, 1 };
    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };
    GLfloat ambient_coeffs[] = { 1.0, 0.1, 0.1, 1 };
    GLfloat diffuse_coeffs[] = { 0.7, 0.7, 0.7, 1 };
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };
    
    glutKeyboardFunc(on_keyboard);
    glutMouseFunc(on_mouse);
    glutMotionFunc(on_motion);
    mouse_x = 0;
    mouse_y = 0;
    
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    
    
    glClearColor(0, 0, 0, 0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    
    GLfloat shininess = 20;
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    //BUG problem sa normalama
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glEnable(GL_COLOR_MATERIAL);
    
    init_texture();
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
static void on_mouse(int button, int state, int x, int y){
    mouse_x = x;
    mouse_y = y;
}
static void on_motion(int x, int y)
{
    int delta_x, delta_y;

    delta_x = x - mouse_x;
    delta_y = y - mouse_y;

    mouse_x = x;
    mouse_y = y;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        glRotatef(180 * (float) delta_x / window_width, 0, 1, 0);
        glRotatef(180 * (float) delta_y / window_height, 1, 0, 0);
        glMultMatrixf(matrix);

        glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    glPopMatrix();

    glutPostRedisplay();
}


void randomize(){
    int s=RAND_MAX/6;
    flag=(rand()/s)+1;
    double clip_plane[]={0, -1, 0, animation_parameter};
    glClipPlane(GL_CLIP_PLANE0, clip_plane);
    glEnable(GL_CLIP_PLANE0);
    if(fi==0 && count<20){
        param=0.5;
        factor=18;
        animation_ongoing=1;
        glutTimerFunc(TIMER_INT*param, on_timer, TIMER_ID);
    }
    if(count>=20){
        index=0;
        param=1;
        animation_parameter=-1.5;
        count=0;
        glDisable(GL_CLIP_PLANE0);
    }
    
}
static void on_timer(int value){
    
    if(value!=TIMER_ID){
        return;
    }
    
    fi+=factor;
    if(index){
        animation_parameter+=0.03;
    }
    if(fi>90 || fi<-90){
        animation_ongoing=0;
        flag=0;
        fi=0;
        
        if(index){
            count++;
            randomize();
        } 
        return;        
    }
    

    glutPostRedisplay();
    if (animation_ongoing){
        glutTimerFunc(TIMER_INT*param, on_timer, TIMER_ID);
        
    }
        
        
    
}
static void on_keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            glDeleteTextures(1, &name);
            exit(0);
            break;
        case 'r':
            //right rotation
            //flag=1
            
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=1;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            
            break;
        case 'R':
            //inverted right rotation
            //flag=1
            
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=1;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            
            break;
            
        case 'l':
            //left rotation
            //flag=2
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=2;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            
            break;
        case 'L':
            //inverted left rotation
            //flag=2
            if(animation_ongoing==0){
                animation_ongoing=1;
                flag=2;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            
            break;
            
        case 'u':
            //up rotation
            //flag=3
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=3;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
            
        case 'U':
            //inverted up rotation
            //flag=3
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=3;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            break;
        case 'd':
            //down rotation
            //flag=4
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=4;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'D':
            //inverted down rotation
            //flag=4
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=4;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'f':
            //front rotation
            //flag=5;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=5;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'F':
            //inverted front rotation
            //flag=5;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=5;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'b':
            //back rotation
            //flag=6;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=6;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'B':
            //inverted back rotation
//             flag=6;
            if(!animation_ongoing){
                animation_ongoing=1;
                flag=6;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 't':
        case 'T':
            //randomize cube
            if(!animation_ongoing){
                index=1;
                randomize();    
            }
            
            break;
        case 'n':
        case 'N':
            //restart cube
            if(!animation_ongoing){
                init_rubik();
                glutPostRedisplay();
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
            1, 300);
    
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //TODO pomeranje kamere od pozicije -10, -10, 60
    //do 6, 6, 6
    gluLookAt(
            -10, -10, 60,
            0, 0, 0,
            0, 1, 0
        );
    
    glMultMatrixf(matrix);
    GLfloat light_position[] = { 1000, 1000, 1000, 0 };
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  
    
    init();    
    title();
    glutSwapBuffers();
}
