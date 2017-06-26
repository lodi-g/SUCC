%{
#include <stdio.h>
#define YYSTYPE char*
#include "parse.h"
%}

%option warn
%option yylineno

%%
\<\?xml.*\?\>                return XMLHEADER;
\<sbml.*\>                   return SBMLHEADER;
\<\/sbml\>                   return SBMLFOOTER;
\<                           return OPENTAG;
\>                           return CLOSETAG;
\/                           return DASH;
\"                           return QUOTE;
=                            return EQUAL;
[a-zA-Z0-9,-]+               yylval=strdup(yytext);return WORD;
[\n\t \r]+                   ;
%%
