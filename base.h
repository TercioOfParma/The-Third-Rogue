#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK	
#include "utterbase.h"
#endif
#define MAP_ARRAY_SIZE_X 80
#define MAP_ARRAY_SIZE_Y 25


void init();//updated 12/06/13
void definething(entity *ent);//non existant
void takeinp(creature *ent, entity **map, item *itemarray);//updated from base.c 12/06/13
void deinit();//updated 12/06/13
void drawentity(entity *ent);//doesn't exist
void drawcreature(creature *ent);//updated from base.c 12/06/13
void defineplayer(creature *ent);//updated from base.c 12/06/13
void definefloor(entity *ent, int x, int y);//deemed alright from base.c 12/06/13
int collisiontile(creature *one, entity *two);//updated from base.c 12/06/13
entity *drawarray(entity *ent);//deemed ok 12/06/13
void clearmap();//deemed ok from base.c 12/06/13
void redefinemap(entity **map, item *items);

