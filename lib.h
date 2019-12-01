#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define ONE_SIDE (1)
#define TWO_SIDES (2)
#define THREE_SIDES (3)
#define COLOR_MAX (3)
#define CUBE_MAX (26)

typedef struct Cube{
    double x;
    double y;
    double z;
    int type;
}cube;
int colors[COLOR_MAX][COLOR_MAX];
cube cubes[CUBE_MAX];

extern void assign_colors(int all_colors[], int type);
extern void draw_cube(cube c, int colors[COLOR_MAX][COLOR_MAX]);
extern void draw_cube1(cube c, int color[COLOR_MAX]);
extern void draw_cube2(cube c, int color1[COLOR_MAX], int color2[COLOR_MAX]);
extern void draw_cube3(cube c, int color1[COLOR_MAX], int color2[COLOR_MAX], int color3[COLOR_MAX]);
