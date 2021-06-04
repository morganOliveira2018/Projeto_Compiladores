all : aulaAST.l aulaAST.y
	cls
	flex -i aulaAST.l
	bison aulaAST.y
	gcc aulaAST.tab.c -o analisador -lm
	./analisador
