all: calc_elidian.l calc_elidian.y
	cls
	flex -i calc_elidian.l
	bison calc_elidian.y
	gcc calc_elidian.tab.c -o calc_elidian -lm
	./calc_elidian