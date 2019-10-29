#include "Flex.hpp"
#include <sstream>
#include <iostream>
#include "Ecxeption.hpp"

Flex::Flex() : lexer(new yyFlexLexer)
{

}

Flex::Flex(char *file_name)
{
	file.open(file_name);
	if (!file.is_open())
		exit(-22);   //---------------------------------------
	//bug.open(".ssss");
	lexer = new yyFlexLexer(file, bug);
}
Flex::~Flex()
{
	return;
}

void Flex::createTokens()
{
	int token;
	while ((token = lexer->yylex()))
	{
		tokenVec.push_back( { static_cast<Tok>(token), lexer->YYText() } );
	}
	if (file.is_open())
		file.close();
}

bool Flex::scanError()
{

}

std::vector<Token>& Flex::getTokenVec()
{
	return tokenVec;
}