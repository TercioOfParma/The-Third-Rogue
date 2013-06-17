#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK	
#include "utterbase.h"
#endif

void defineitem(item *item, unsigned int x, unsigned int y);
void redefineitem(item *item, unsigned int x, unsigned int y);
void drawitemarray(item *itemarray);
void pickupitem(creature *player, item *item);