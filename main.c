#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "lib.h"
#include <sys/time.h>
#include <time.h>
#define TIMER_ID (0)
#define TIMER_INT (100)
#define START_TIMER_ID (1)
#define START_TIMER_INT (60)



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

static int animation_ongoing=0;
//ugao rotacije
double fi=0;
//parametar za podesavanje intervala tajmera
double param=1;
double animation_parameter=-1.5;
int factor;
//flag koji govori koja rotacija se izvrsava
int flag;
//brojac za randomizaciju kocke
int count=0;
//flag za randomizaciju kockice, pokrece tajmer sve dok se ne izvrsi 20 rotacija
int index=0;
//matrica rotacije koja se azurira na pomeraj misa
static float matrix[16];
//promenljive za pocetnu animaciju
double start_parameter=0;
static int start_ongoing=1;

int main(int argc, char **argv){
    
    
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(500, 250);
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

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glEnable(GL_COLOR_MATERIAL);
    
    init_texture();
    init_rubik();
    
    
    //poziv pocetne animacije
    if(start_ongoing)
        glutTimerFunc(START_TIMER_INT, start_timer, START_TIMER_ID);
    glutMainLoop();
    
    

    return 0;
    
    
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

//randomizacija kockice
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
//tajmer za pocetnu animaciju
static void start_timer(int value){
    
    if(value!=START_TIMER_ID){
        return;
    }
    
    start_parameter+=0.01;
    
    
    glutPostRedisplay();
    if(start_ongoing){
        glutTimerFunc(START_TIMER_INT, start_timer, START_TIMER_ID);
    }
}
//tajmer za animaciju rotacija
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
            //rotacija desne strane, flag=1
            
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=1;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            
            break;
        case 'R':
            //invertovana rotacija desne strane, flag=1
            
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=1;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            
            break;
            
        case 'l':
            //rotacija leve strane, flag=2
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=2;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            
            break;
        case 'L':
            //invertovana rotacija leve strane, flag=2
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=2;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            
            break;
            
        case 'u':
            //rotacija gornje strane, flag=3
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=3;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
            
        case 'U':
            //invertovana rotacija gornje strane, flag=3
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=3;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
            }
            break;
        case 'd':
            //rotacija donje strane, flag=4
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=4;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'D':
            //invertovana rotacija donje strane, flag=4
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=4;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'f':
            //rotacija prednje strane, flag=5
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=5;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'F':
            //invertovana rotacija prednje strane, flag=5
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=5;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'b':
            //rotacija zadnje strane, flag=6
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=6;
                factor=18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 'B':
            //invertovana rotacija prednje strane, flag=6
            if(!animation_ongoing && !start_ongoing){
                animation_ongoing=1;
                flag=6;
                factor=-18;
                glutTimerFunc(TIMER_INT, on_timer, TIMER_ID);
                
                
            }
            break;
        case 't':
        case 'T':
            //randomizacija kocke
            if(!animation_ongoing && !start_ongoing){
                index=1;
                randomize();    
            }
            
            break;
        case 'n':
        case 'N':
            //restartovanje kocke
            if(!animation_ongoing && !start_ongoing){
                init_rubik();
                glutPostRedisplay();
            }
            break;
        case 's':
        case 'S':
            //zaustavljanje animacija
            animation_ongoing=0;
            start_ongoing=0;
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
            1, 60);
    
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(
            -10+16*start_parameter, -10+16*start_parameter, 60-54*start_parameter,
            0, 0, 0,
            0, 1, 0
        );
    
    glMultMatrixf(matrix);
    GLfloat light_position[] = { 1000, 1000, 1000, 0 };
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  
    
    double clip_plane[]={0, 0, -1, 5};
    glClipPlane(GL_CLIP_PLANE1, clip_plane);
    
    
    //sakrivanje naslova posle zavrsetka pocetne animacije
    if(start_parameter>=1){
        start_ongoing=0;
        start_parameter=1;
        glEnable(GL_CLIP_PLANE1);
    }
    //iscrtavanje Rubikove kocke
    draw_rubik(fi, flag);
    //iscrtavanje naslova
    title();
    glutSwapBuffers();
}
