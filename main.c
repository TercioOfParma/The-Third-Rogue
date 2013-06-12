#include "base.h"



int main(){
	srand(time(NULL));
	init();
	int i = 0;
	creature player;
	player.kind = 1;//makes the player a player
	defineplayer(&player);
	entity **map = malloc(sizeof(entity) * 80);
	while(i < ARRAY_SIZE_X){
	
	map[i] = malloc(sizeof(entity)* 25);
	i++;


	}

	
	i = 0;
	int j = 0;
	while(i < ARRAY_SIZE_X){
		while(j < ARRAY_SIZE_Y){
			definefloor(&map[i][j], i , j);//defines the thing
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
		takeinp(&player);
		
	while(i < ARRAY_SIZE_X){
		drawarray(map[i]);
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
	
	free(map);
	return 0;
}
