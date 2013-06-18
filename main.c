#include "item.h"
#include "base.h"




int main()
{
	srand(time(NULL));
	init();
	printf("Works 1 \n");
	int i = 0;
	creature player;
	player.kind = 1;//makes the player a player
	defineplayer(&player);
	entity **map = malloc(sizeof(entity) * MAP_ARRAY_SIZE_X);
	if(!map)
	{
		printw("Map assignment failed: insufficient memory");
		printf("Fails at map");
		
	
	}
	item *items = malloc(sizeof(item) * DUNGEON_ITEMS);
	if(!items)
	{
		printw("Item assignment failed, insufficient memory");
		printf("fails at items");
	}
	while(i < MAP_ARRAY_SIZE_X){
	
		map[i] = malloc(sizeof(entity)* MAP_ARRAY_SIZE_Y);
		
		i++;


	}

	printf("at redefine map");
	redefinemap(map, items);
	printf("after redefine map");
	
	while(1 == 1)
	{
		i = 0;
		int j = 0;
		int k = 0;
		int collider = 0;
		player.oldx = player.x;
		player.oldy = player.y;
		
	
		
		
		
		drawcreature(&player);
		takeinp(&player, map, items);
		
		
		
		
		
		
		
	while(i < MAP_ARRAY_SIZE_X)
	{
		drawarray(map[i]);
		
		i++;
	}
	drawitemarray(items);
		
	while(j < MAP_ARRAY_SIZE_X)
		{
			while(k < MAP_ARRAY_SIZE_Y){
				collider = collisiontile(&player, &map[j][k]);
				if(collider == 1){
					
					player.x = player.oldx;
					player.y = player.oldy;
					break;
				
				}
				k++;
			}
			if(collider == 1){
				break;
			
			}
			k = 0;
			j++;
		}
	}
	
						
	
	
	
	free(items);
	free(map);
	return 0;
}
