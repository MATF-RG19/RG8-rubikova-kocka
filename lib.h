#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "colors.h"
#define ONE_SIDE (1)
#define TWO_SIDES (2)
#define THREE_SIDES (3)
#define COLOR_MAX (3)
#define CUBE_MAX (27)

typedef enum all_cube_colors{ white, yellow, blue, green, red, orange} clr;
typedef struct Cube{
    int type;
    clr clrs[6];
    double x, y, z;
    
}cube;




//niz se inicijalizuje tako sto svaka druga kockica je istog tipa
//u gornjem sloju su to tipa: tri obojene(indeks paran), dve obojene strane(indeks neparan), jedna obojena strana na poziciji 8, indeksi [0-8]
//u srednjem sloju su to tipa: dve obojene(indeks neparan) i jedna obojena strana(indeks paran), indeksi [9-16]
//u donjem sloju su to tipa: tri obojene(indeks neparan), dve obojene strane(indeks paran), jedna obojena strana na poziciji 25,  indeksi [17-25]
cube cubes[CUBE_MAX];

extern enum all_cube_colors recognize_color(double colors[]);
extern void top_layer();
extern void middle_layer();
extern void bottom_layer();
extern void right_rotation(double fi);
extern void top_rotation(double fi);

extern void assign_colors(enum all_cube_colors t, double (*c)[3]);
extern void draw_cube(cube c);
// extern void draw_cube1(cube c, double x, double y, double  z);
// extern void draw_cube2(cube c,  double x, double y, double  z);
// extern void draw_cube3(cube c, double x, double y, double  z);
extern void init_colors(cube* c);
extern void init_rubik();