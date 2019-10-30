
%{

#include "Flex.hpp"
int yyFlexLexer::yywrap() {return 1;}

%}
%x N_INT8 N_INT16 N_INT32 N_FLOAT N_DOUBLE LAST EOL
%option noyywrap
%option nounput
%option noinput
%%

" int8("		BEGIN(N_INT8);
" int16("		BEGIN(N_INT16);
" int32("		BEGIN(N_INT32);
" float("		BEGIN(N_FLOAT);
" double("		BEGIN(N_DOUBLE);

<N_INT8>[-+]?[0-9]+		{BEGIN(LAST); return token_int8;}
<N_INT16>[-+]?[0-9]+	{BEGIN(LAST); return token_int16;}
<N_INT32>[-+]?[0-9]+	{BEGIN(LAST); return token_int32;}
<N_FLOAT>[-+]?[0-9]*\.?[0-9]*[f]?([eE][+-]?[0-9]+)?		{BEGIN(LAST); return token_float;}
<N_DOUBLE>[-+]?[0-9]*\.?[0-9]*[f]?([eE][+-]?[0-9]+)?	{BEGIN(LAST); return token_double;}

<LAST>")" BEGIN(INITIAL);

"exit"	{return token_exit;}
"push"	{return token_push;}
"pop"	{return token_pop;}
"dump"	{return token_dump;}
"assert" {return token_assert;}
"add"	{return token_add;}
"sub"	{return token_sub;}
"mul"	{return token_mul;}
"div"	{return token_div;}
"mod"	{return token_mod;}
"print"	{return token_print;}
^;;$	{return token_end;}
;.*		{return token_comment;}
<*>.	{return token_error;}
[\n]	{return token_eol;}
%%