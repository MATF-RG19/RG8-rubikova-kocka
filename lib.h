#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "colors.h"
#include "image.h"
#define COLOR_MAX (3)
//broj kockica od kojih se sastoji Rubikova kocka
#define CUBE_MAX (27)

//ime teksture
#define FILENAME0 "sume.bmp"

static GLuint name;


typedef enum all_cube_colors{ white, yellow, blue, green, red, orange, black} clr;

typedef struct Cube{
    //enum niz koji sadrzi po boju za svaku stranu kockice
    clr clrs[6];
    //koordinate kockice
    double x, y, z;
    //matrica orijentacije kockice
    GLfloat ori[16];
    
}cube;


                
//matrica rotacije Rubikove kocke                
GLfloat rot[16];
cube cubes[CUBE_MAX];

extern enum all_cube_colors recognize_color(double colors[]);
void init_texture();
void title();
void randomize();
extern void draw_rubik(double fi, int flag);
extern void assign_colors(enum all_cube_colors t, double (*c)[3]);
extern void draw_cube(cube c);
void rotate(double fi, int vector[3], cube *c);
extern void init_rubik();

