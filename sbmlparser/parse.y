%{
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "incs/sbmlparser.h"

#define YYSTYPE char*
#define MPF

int yyparse(void);
int yylex(void);
void yyerror(char const *msg);

#define BEGINTAG "0"
#define ENDTAG "1"
#define ALONETAG "2"

static t_node *curr = { 0 };

int print_curr(char tag)
{
	if (tag == *ENDTAG)
		return printf("</%s>\n", curr->name);

	int i, j;
	printf("<%s ", curr->name);
	for (i = 0; curr->attrs[i]; i++)
		{
			printf("%s=\"", curr->attrs[i]->name);
			for (j = 0; curr->attrs[i]->values[j]; j++);
			while (j--)
				{
					printf("%s ", curr->attrs[i]->values[j]);
				}
			printf("\b\" ");
		}
	printf("\b%s", curr->attrs[0] ? "/>" : ">");
	printf("\n");
}


%}

%define parse.error verbose

%token XMLHEADER SBMLHEADER SBMLFOOTER OPENTAG CLOSETAG WORD DASH QUOTE EQUAL

%%

stmts: stmt | stmts stmt

stmt: XMLHEADER | SBMLHEADER | SBMLFOOTER | xml_tag;

xml_tag: begintag | endtag | alonetag;

begintag: OPENTAG tagname attributes CLOSETAG
{
	print_curr(*BEGINTAG);
};

endtag: OPENTAG DASH tagname CLOSETAG
{
	print_curr(*ENDTAG);
};

alonetag: OPENTAG tagname attributes DASH CLOSETAG
{
	print_curr(*ALONETAG);
};

tagname: WORD
{
	curr = calloc(1, sizeof(t_node));
	curr->name = strdup(yylval);
	MPF("<%s", curr->name);
}

attributes: %empty | attributes attribute
{
	MPF("\b\"");
};

attribute: attrname EQUAL attrvalue;

attrname: WORD
{
	t_attrs **c = curr->attrs;
	while (*c)
		c++;
	*c = calloc(1, sizeof(t_attrs));
	(*c)->values = calloc(10, sizeof(char *));
	(*c)->name = strdup(yylval);
}

attrvalue: QUOTE words QUOTE;

words: %empty | WORD words
{
	t_attrs **c = curr->attrs;
	while (*c)
		c++;
	c--;
	char **n = (*c)->values;
	while (*n)
		n++;
	*n = strdup($1);
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
