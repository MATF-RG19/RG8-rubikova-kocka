#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "colors.h"
#include "image.h"
#define COLOR_MAX (3)
#define CUBE_MAX (27)

#define FILENAME0 "1.bmp"
//texture name
static GLuint name;

typedef enum all_cube_colors{ white, yellow, blue, green, red, orange, black} clr;
typedef struct Cube{
    int type;
    clr clrs[6];
    double x, y, z;
    GLfloat ori[16];
    //double normals[18];
    
}cube;


                
                
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

