parser: lex.yy.c y.tab.c 
	g++ -o parser $^ -ll
y.tab.c y.tab.h: sail.y
	bison -d -y $^
lex.yy.c: sail.l
	flex sail.l