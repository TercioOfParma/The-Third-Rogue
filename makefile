all:
	gcc	-c	utterbase.h
	gcc	-c	base.h
	gcc	-c	base.c
	gcc	-c	main.c
	gcc	-o	roguelike	main.o	base.o	-lpdcurses