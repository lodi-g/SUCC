%{
#include <stdio.h>
#include <string.h>

int yyparse(void);
int yylex(void);
void yyerror(char const *msg);

%}

%define parse.error verbose

%token XMLHEADER SBMLHEADER SBMLFOOTER OPENTAG CLOSETAG WORD DASH QUOTE EQUAL

%%

stmts: stmt | stmts stmt

stmt: XMLHEADER | SBMLHEADER | SBMLFOOTER | xml_tag;

xml_tag: begintag | endtag | alonetag;

begintag: OPENTAG tagname attributes CLOSETAG
{
	printf(">\n");
};

endtag: OPENTAG DASH tagname CLOSETAG
{
	printf("\r</%s>\n", $3);
};

alonetag: OPENTAG tagname attributes DASH CLOSETAG
{
	printf("/>\n");
};

tagname: WORD
{
	printf("<%s", $1);
}

attributes: %empty | attributes attribute
{
	printf("\b\"");
	$$ = $2;
};

attribute: attrname EQUAL attrvalue;

attrname: WORD
{
	printf(" %s=\"", $1);
}

attrvalue: QUOTE words QUOTE;

words: %empty | words WORD
{
	printf("%s ", $2);
};

%%

extern int yylineno;
void yyerror(char const *msg)
{
	fprintf(stderr, "line %d: %s\n", yylineno, msg);
}

int yywrap()
{
	return 1;
}

int main(void)
{
	yyparse();
}
