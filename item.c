#include "item.h"

void defineitem(item *item, unsigned int x, unsigned int y)
{
	item->x = x;
	item->y = y;
	if(x)
	{
		item->display = '!';
		item->colour = 4;
		item->kind = POTION;
		item->pairid = 4;
	
	
	}


}

void drawitemarray(item *itemarray)
{	
	
	unsigned int counter = 0;
	item *temp = itemarray;
	while(counter < DUNGEON_ITEMS)
	{
		int s = itemarray->colour;
		init_pair(s, s, COLOR_BLACK);
		attron(COLOR_PAIR(s));
		mvaddch(itemarray->y, itemarray->x, itemarray->display);
		attroff(COLOR_PAIR(s));
		counter++;
		itemarray++;
	}

	itemarray =  temp;
}