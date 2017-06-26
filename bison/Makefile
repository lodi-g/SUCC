all:
	flex lexer.l
	bison -d grammar.y
	gcc lex.yy.c grammar.tab.c

	@rm grammar.tab.*
	@rm lex.yy.c
