#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "colors.h"
#define ONE_SIDE (1)
#define TWO_SIDES (2)
#define THREE_SIDES (3)
#define COLOR_MAX (3)
#define CUBE_MAX (26)

typedef enum all_cube_colors{ white, yellow, blue, green, red, orange} clr;
typedef struct Cube{
    int type;
    clr clrs[3];
}cube;


double colors[COLOR_MAX][COLOR_MAX];
cube cubes[CUBE_MAX];

extern enum all_cube_colors recognize_color(double colors[]);

extern void assign_colors(double all_colors[], cube c);
extern void draw_cube(cube c, double colors[COLOR_MAX][COLOR_MAX], double x, double y, double  z);
extern void draw_cube1(double color[COLOR_MAX], double x, double y, double  z);
extern void draw_cube2(double color1[COLOR_MAX], double color2[COLOR_MAX], double x, double y, double  z);
extern void draw_cube3(double color1[COLOR_MAX], double color2[COLOR_MAX], double color3[COLOR_MAX], double x, double y, double  z);
extern void init_colors(cube c);
