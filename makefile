all:
	gcc	-c	utterbase.h
	gcc	-c	item.h
	gcc	-c	base.h
	gcc	-c	item.c
	gcc	-c	base.c
	gcc	-c	main.c
	gcc	-o	roguelike	main.o	base.o	item.o	-lpdcurses