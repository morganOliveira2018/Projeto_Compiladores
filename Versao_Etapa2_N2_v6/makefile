all: calc_morgana.l calc_morgana.y
	flex -i calc_morgana.l
	bison calc_morgana.y
	gcc calc_morgana.tab.c -o calc_morgana -lm
	./calc_morgana
	