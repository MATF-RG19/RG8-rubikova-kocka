#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "lib.h"

static int window_width;
static int window_height;
static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
int main(int argc, char **argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    
    glClearColor(1, 1, 1, 0);
    glEnable(GL_DEPTH_TEST);
    
    glutMainLoop();

    return 0;
    
    
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
            1, 5);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            1, 1, 3,
            0, 0, 0,
            0, 1, 0
        );
    cube1(1, 0, 0);
    glutSwapBuffers();
}
