#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define ARRAY_SIZE_X 80
#define ARRAY_SIZE_Y 25
#define true 1
#define false 0

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