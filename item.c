#include "item.h"

void defineitem(item *item, unsigned int x, unsigned int y)
{
	item->x = x;
	item->y = y;
	if(x)
	{
		item->display = '!';
		item->colour = rand() % 7 + 1;;
		item->kind = POTION;
		item->pairid = item->colour;
	
	
	}


}

void redefineitem(item *item, unsigned int x, unsigned int y)
{
	item->x = 0;
	item->y = 0;
	item->display = 0;
	item->colour = 0;
	item->kind = 0;
	item->pairid = 0;
	item->x = x;
	item->y = y;
	if(x)
	{
		item->display = '!';
		item->colour = rand() % 7 + 1;;
		item->kind = POTION;
		item->pairid = item->colour;
	
	
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



void pickupitem(creature *player, item *item){
	
	unsigned char x = false;
	unsigned char indexer = 0;
	while(x != true){
	
	if(!player->inventory[indexer]){
		player->inventory[indexer]->x = player->x;
		player->inventory[indexer]->y = player->y;
		player->inventory[indexer]->display = '!';
		player->inventory[indexer]->colour = item->colour;
		player->inventory[indexer]->kind = item->kind;
		player->inventory[indexer]->pairid = item->colour;
		
		item->x = 1000;
		item->y = 1000;
		
	
	
	x = true;
	}
	
	indexer++;
	
	}
	
	



}