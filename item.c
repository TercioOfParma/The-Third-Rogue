#include "item.h"

void defineitem(item *item, unsigned int x, unsigned int y)
{
	item->x = x;
	item->y = y;
	int decider = rand() % 3 + 1;
	if(decider == 1)
	{
		item->display = '!';
		item->colour = rand() % 7 + 1;
		item->kind = POTION;
		item->pairid = item->colour;
		strcpy(item->name, " Potion");
	
	}
	else if(decider == 2){
		item->display = '?';
		item->colour = rand() % 7 + 1;
		item->kind = SCROLL;
		item->pairid = item->colour;
		strcpy(item->name, " Scroll");
		
	
	
	}
	else if(decider == 3){
		item->display = '/';
		item->colour = rand() % 7 + 1;
		item->kind = SCROLL;
		item->pairid = item->colour;
		strcpy(item->name, " Weapon");
	
	
	
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
		strcpy(item->name, "Potion");
	
	
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
	
	if(player->inventory[indexer].x == 0 && player->inventory[indexer].y == 0 && player->inventory[indexer].display == 0){
		player->inventory[indexer].x = player->x;
		player->inventory[indexer].y = player->y;
		player->inventory[indexer].display = item->display;
		player->inventory[indexer].colour = item->colour;
		player->inventory[indexer].kind = item->kind;
		player->inventory[indexer].pairid = item->colour;
		strcpy(player->inventory[indexer].name, item->name);
		
		item->x = 1000;
		item->y = 1000;
		
	
	
	x = true;
	break;
	}
		if(indexer >= 24 || x == false){
			item->x = player->x;
			item->y = player->y;
			
		
		
		}
	indexer++;
	
	}
	
	



}