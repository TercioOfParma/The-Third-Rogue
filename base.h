#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define ARRAY_SIZE_X 80
#define ARRAY_SIZE_Y 25
#define true 1
#define false 0
#define VIEW_RADIUS 30



typedef struct{//dont have access to sizeof at the moment 'cos no compiler, but methinks
	//it is 18 bytes in size
	int x, y;
	char colour;//this holds the colour from 0-7
	char display;//the character that is displayed
	unsigned int kind;//this tells the computer what it is
	unsigned char pairid;
	unsigned char blocked;//tells the computer if it blocks the way of the person
	unsigned char stairsdown;
	unsigned char isvisible;
}entity;

typedef struct{
	int x, y, oldx, oldy;
	char colour, display;
	unsigned char kind, pairid, combatant;




}creature;

void init();//updated 12/06/13
void definething(entity *ent);//non existant
void takeinp(creature *ent);//updated from base.c 12/06/13
void deinit();//updated 12/06/13
void drawentity(entity *ent);//doesn't exist
void drawcreature(creature *ent);//updated from base.c 12/06/13
void defineplayer(creature *ent);//updated from base.c 12/06/13
void definefloor(entity *ent, int x, int y);//deemed alright from base.c 12/06/13
int collisiontile(creature *one, entity *two);//updated from base.c 12/06/13
entity *drawarray(entity *ent);//deemed ok 12/06/13
void clearmap();//deemed ok from base.c 12/06/13
