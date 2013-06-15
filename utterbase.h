#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAP_ARRAY_SIZE_X 80
#define MAP_ARRAY_SIZE_Y 25
#define true 1
#define false 0
#define DUNGEON_ITEMS 20
#define POTION 1;


//really important, there will be only 8 pair ids, they are equal to the colours used so init_pair(7, 7, COLOR_BLACK) would be white pair or pair 7
typedef struct
{//dont have access to sizeof at the moment 'cos no compiler, but methinks
	//it is 18 bytes in size
	unsigned int x, y;
	unsigned char colour;//this holds the colour from 0-7
	unsigned char display;//the character that is displayed
	unsigned int kind;//this tells the computer what it is
	unsigned char pairid;
	unsigned char blocked;//tells the computer if it blocks the way of the person
	unsigned char stairsdown;
	unsigned char isvisible;
}entity;
typedef struct
{
	unsigned int x, y;
	unsigned char kind, colour, display, pairid;


}item;

typedef struct
{
	unsigned int x, y, oldx, oldy;
	unsigned char colour, display;
	unsigned char kind, pairid, combatant;
	item inventory[26];




}creature;
