%{
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define YYSTYPE char*

int yylex();
void yyerror(const char *msg);

%}

%token XMLHEADER SBMLHEADER SBMLFOOTER OPENTAG CLOSETAG WORD DASH QUOTE EQUAL

%%

stmts: stmt | stmts stmt
stmt: XMLHEADER | SBMLHEADER | SBMLFOOTER | xml_tag;

xml_tag: commontag { /* set_type(curr, *$1); add_to_root(curr); */ };
commontag:
		begintag { $$ = "0"; };
	| endtag   { $$ = "1"; };
	| alonetag { $$ = "2"; };

begintag: OPENTAG tagname attributes CLOSETAG;
endtag: OPENTAG DASH tagname CLOSETAG;
alonetag: OPENTAG tagname attributes DASH CLOSETAG;

tagname: WORD {	/* curr = new_tag(curr, yylval); */ };

attributes: %empty | attributes attribute;
attribute: attrname EQUAL attrvalue;

attrname: WORD { /* new_attr(curr, yylval); */ };
attrvalue: QUOTE words QUOTE;
words: %empty | WORD words { /* new_attr_val(curr, yylval); */ };

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
