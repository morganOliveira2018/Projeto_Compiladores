%{

%}

NUM [0-9]+\.?[0-9]*
VARS[a-z]
FIM "FIM"
IF "IF"
ELSE "ELSE"
WHILE "WHILE"
PRINT "PRINT"

%%

{VARS} {
	yylval.inter = *yytext - 'a';
	return VARS;
	}

{NUM} {
	yylval.flo = atof(yytext);
	return NUM;
	}

[-+()=/*^{};] {return *yytext;
			}
			

">" {yylval.fn = 1; return CMP; }
"<" {yylval.fn = 2; return CMP; }
"<>" {yylval.fn = 3; return CMP; }
"==" {yylval.fn = 4; return CMP; }
">=" {yylval.fn = 5; return CMP; }
"<=" {yylval.fn = 6; return CMP; }


{FIM} {return FIM;}
{IF} {return IF;}
{ELSE} {return ELSE;}
{WHILE} {return WHILE;}
{PRINT} {return PRINT;}
[\ \n\t]*	{;}
. {printf("(%s) Ingonrado\n",yytext);}
%%