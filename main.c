#include "item.h"
#include "base.h"




int main(){
	srand(time(NULL));
	init();
	int i = 0;
	creature player;
	player.kind = 1;//makes the player a player
	defineplayer(&player);
	entity **map = malloc(sizeof(entity) * 80);
	if(!map)
	{
		printw("Map assignment failed: insufficient memory");
		
	
	}
	item *items = malloc(sizeof(item) * DUNGEON_ITEMS);
	if(!items)
	{
		printw("Item assignment failed, insufficient memory");
	}
	while(i < ARRAY_SIZE_X){
	
	map[i] = malloc(sizeof(entity)* 25);
	i++;


	}

	
	i = 0;
	int j = 0;
	int itemdecider = 0;
	int itemcounter = 0;
	while(i < ARRAY_SIZE_X)
		{
		while(j < ARRAY_SIZE_Y)
			{
			itemdecider = rand() % 50 + 1;
			definefloor(&map[i][j], i , j);//defines the thing
			if(map[i][j].blocked == false && itemdecider == 5 && itemcounter < 20 + 1)
			{
				defineitem(&items[itemcounter], i , j);
				
				itemcounter++;
			}
			j++;
		}
		j = 0;
		i++;
		
	}
	i = 0;
	
	while(1 == 1){
		
		player.oldx = player.x;
		player.oldy = player.y;
		drawcreature(&player);
		
		takeinp(&player, map, items);
		
	while(i < ARRAY_SIZE_X){
		drawarray(map[i]);
		drawitemarray(items);
		i++;
	}
		if ( i == ARRAY_SIZE_X){
			i = 0;
		
		}
	while(i < ARRAY_SIZE_X){
		while(j < ARRAY_SIZE_Y){
			int take = collisiontile(&player, &map[i][j]);
				if (take == 1 || player.x > (ARRAY_SIZE_X - 1)  || player.x < 0 || player.y > (ARRAY_SIZE_Y - 1) || player.y < 0){
					player.x = player.oldx;
					player.y = player.oldy;
				
				
				}
				else if(take == 2){//alpha new level
					i = 0;
					j = 0;
					while(i < ARRAY_SIZE_X){
						while(j < ARRAY_SIZE_Y){
							
							definefloor(&map[i][j], i , j);//defines the thing
							
							j++;
						}
						j = 0;
						i++;
		
					}
				i = 0;
				
				
				}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;	
		
	
	}
	
	free(items);
	free(map);
	return 0;
}
