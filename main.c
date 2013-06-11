#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define ARRAY_SIZE_X 80
#define ARRAY_SIZE_Y 25
#define true 1
#define false 0
#define VIEW_RADIUS 30



typedef struct{
	int x, y, oldx, oldy;
	char colour;//this holds the colour from 0-7
	char display;//the character that is displayed
	unsigned int kind;//this tells the computer what it is
	unsigned char pairid;
	unsigned char combatant;//tells the computer if it is a combatant, not relevant at the moment
	unsigned char blocked;//tells the computer if it blocks the way of the person
	unsigned char stairsdown;
	unsigned char isvisible;
}entity;


void init();
void definething(entity *ent);
void takeinp(entity *ent);
void deinit();
void draw(entity *ent);
void defineplayer(entity *ent);
void definefloor(entity *ent, int x, int y);
int collision(entity *one, entity *two);
void FOV(entity *ent, entity map[80][25]);
int DoFovd(float x, float y, entity *ent, entity map[80][25]);
entity *drawarray(entity *ent);
void clearmap();


int main(){
	srand(time(NULL));
	init();
	entity player;
	player.kind = 1;//makes the player a player
	defineplayer(&player);
	entity testthings[80][25];
	
	
	int i = 0;
	int j = 0;
	while(i < ARRAY_SIZE_X){
		while(j < ARRAY_SIZE_Y){
			definefloor(&testthings[i][j], i , j);//defines the thing
			j++;
		}
		j = 0;
		i++;
		
	}
	i = 0;
	
	while(1 == 1){
		player.oldx = player.x;
		player.oldy = player.y;
		draw(&player);
		takeinp(&player);
		
	while(i < ARRAY_SIZE_X){
		drawarray(&testthings[i]);
		i++;
	}
		if ( i == ARRAY_SIZE_X){
			i = 0;
		
		}
	while(i < ARRAY_SIZE_X){
		while(j < ARRAY_SIZE_Y){
			int take = collision(&player, &testthings[i][j]);
				if (take == 1 || player.x > 79 || player.x < 0 || player.y > 24 || player.y < 0){
					player.x = player.oldx;
					player.y = player.oldy;
				
				
				}
				else if(take == 2){
					i = 0;
					j = 0;
					while(i < ARRAY_SIZE_X){
						while(j < ARRAY_SIZE_Y){
							
							definefloor(&testthings[i][j], i , j);//defines the thing
							
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
	
	
	return 0;
}

void clearmap(){//simply makes it dark
int i = 0, j = 0;
	while(i < ARRAY_SIZE_X){
		while(j < ARRAY_SIZE_Y){
		mvaddch(i, j, ' ' );
		j++;
		
		}

	j = 0;
	i++;
}
}








void draw(entity *ent){
	int s = ent->colour;
	static int derp = 0;
	
	init_pair(ent->pairid , s, COLOR_BLACK);
	attron(COLOR_PAIR(ent->pairid));
	mvaddch(ent->y, ent->x, ent->display);
	attroff(COLOR_PAIR(ent->pairid));



}
int collision(entity *one, entity *two){
	if (one->x == two->x && one->y == two->y && two->blocked == true){

	return 1;

	}
	if(one->x == two->x && one->y == two->y && two->stairsdown == true){
	
		return 2;
	
	}
	else{
		return 0;
	}



}
void init(){
	initscr();
	raw();
	
	keypad(stdscr, TRUE);
	start_color();



}

void deinit(){
	refresh();
	endwin();
	exit(0);

}
void takeinp(entity *ent){
	int takeinp;
	takeinp = getch();

	switch(takeinp){
		
		case KEY_LEFT:
			mvaddch(ent->y, ent->x, ' ');
			ent->x--;
			break;
		case KEY_RIGHT:
			mvaddch(ent->y, ent->x, ' ');
			ent->x++;
			break;
		case KEY_UP:
			mvaddch(ent->y, ent->x, ' ');
			ent->y--;
			break;
		case KEY_DOWN:
			mvaddch(ent->y, ent->x, ' ');
			ent->y++;
			break;
		case 27:
			deinit();
			break;
		case KEY_A1:
			mvaddch(ent->y, ent->x, ' ');
			ent->x--;
			ent->y--;
			break;
		case KEY_A2:
			mvaddch(ent->y, ent->x, ' ');
			ent->y--;
			break;
		case KEY_A3:
			mvaddch(ent->y, ent->x, ' ');
			ent->x++;
			ent->y--;
			break;
		case KEY_B1:
			mvaddch(ent->y, ent->x, ' ');
			ent->x--;
			break;
		case KEY_B3:
			mvaddch(ent->y, ent->x, ' ');
			ent->x++;
			break;
		case KEY_C1:
			mvaddch(ent->y, ent->x, ' ');
			ent->x--;
			ent->y++;
			break;
		case KEY_C2:
			mvaddch(ent->y, ent->x, ' ');
			ent->y++;
		
			break;
		case KEY_C3:
			mvaddch(ent->y, ent->x, ' ');
			ent->x++;
			ent->y++;
			break;
			
			
		default:
			break;


	}




}


entity *drawarray(entity *ent){
	int arraycount = 0;
	entity *returnar = ent;
	int derp = 0;
	
	while(arraycount < ARRAY_SIZE_Y){
		int s = ent->colour;
		init_pair(ent->pairid , s, COLOR_BLACK);
		if(ent->isvisible == true){
			attron(COLOR_PAIR(ent->pairid));
			if (ent->pairid == 4){
		
				attron(A_STANDOUT | A_BOLD);
		
			}	
			mvaddch(ent->y, ent->x, ent->display);
			attroff(COLOR_PAIR(ent->pairid));
			if(ent->pairid == 4){
				attroff(A_STANDOUT | A_BOLD);
		
			}
		}
		arraycount++;
		ent++;
		derp++;
	
	
	}
	return returnar;


}

void defineplayer(entity *ent){
		ent->x = 30;
		ent->y = 20;
		ent->display = '@';
		ent->colour = 4;
		ent->pairid = 1;
		ent->combatant = true;
		ent->blocked = false;
}

void definefloor(entity *ent, int x, int y){
	
	static int isstairs = 0;
	static int dungeonlevel = 0;
	static int totalsquares = 0;
	int terraintype = rand() % 100 + 1;
	if(terraintype > 70 && terraintype < 96){
		ent->x = x;
		ent->y = y;
		ent->display = '#';
		ent->colour = 7;
		ent->pairid = 3;
		ent->combatant = false;
		ent->blocked = true;
		ent->stairsdown = false;
		ent->isvisible = true;
	
	
	}
	else if(terraintype == 99 && isstairs == dungeonlevel){
		ent->x = x;
		ent->y = y;
		ent->display = '>';
		ent->colour = 3;
		ent->pairid = 4;
		ent->combatant = false;
		ent->blocked = false;
		ent->stairsdown = true;
		ent->isvisible = true;
		isstairs++;
		
	
	}
	else{
		ent->x = x;
		ent->y = y;
		ent->display = '.';
		ent->colour = 7;	
		ent->pairid = 2;
		ent->combatant = false;
		ent->blocked = false;
		ent->stairsdown = false;
		ent->isvisible = true;
	}
	totalsquares++;
	if(totalsquares == 2000){
		totalsquares = 0;
		dungeonlevel++;
	
	
	}

}