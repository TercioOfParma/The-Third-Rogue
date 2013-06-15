#include "base.h"

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








void drawcreature(creature *ent){
	int s = ent->colour;
	static int derp = 0;
	
	init_pair(ent->pairid , s, COLOR_BLACK);
	attron(COLOR_PAIR(ent->pairid));
	mvaddch(ent->y, ent->x, ent->display);
	attroff(COLOR_PAIR(ent->pairid));



}
int collisiontile(creature *one, entity *two){
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
void takeinp(creature *ent, entity **map, item *itemarray){
	int takeinp;
	entity **tempmap = map;
	item *tempitem = itemarray;
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
	itemarray = tempitem;
	map = tempmap;



}


entity *drawarray(entity *ent){
	int arraycount = 0;
	entity *returnar = ent;
	
	
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
		
	
	
	}
	return returnar;


}

void defineplayer(creature *ent){
		ent->x = 30;
		ent->y = 20;
		ent->display = '@';
		ent->colour = 4;
		ent->pairid = 4;
		ent->combatant = true;
		
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
		ent->pairid = 7;
		ent->blocked = true;
		ent->stairsdown = false;
		ent->isvisible = true;
	
	
	}
	else if(terraintype == 99 && isstairs == dungeonlevel){
		ent->x = x;
		ent->y = y;
		ent->display = '>';
		ent->colour = 3;
		ent->pairid = 3;
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
		ent->pairid = 7;
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

