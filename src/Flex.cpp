#include "Flex.hpp"
#include <sstream>
#include <iostream>
#include "Ecxeption.hpp"

Flex::Flex() : lexer(new yyFlexLexer),
				flagError(0)
{
}

Flex::Flex(char *file_name) : 	flagError(0)
{
	file.open(file_name);
	if (!file.is_open())
		throw Flex::flexExcep("Not found file!");
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
		tokenVec.push_back({static_cast<Tok>(token), lexer->YYText()});
	}
	if (file.is_open())
		file.close();
}

int Flex::scanError()
{
	int line = 1;
	std::vector<Token>::iterator check;
	if (tokenVec.size() == 0)
		throw Flex::flexExcep("Not found command");
	for (std::vector<Token>::iterator i = tokenVec.begin(); i != tokenVec.end(); ++i)
	{
		if (i->token == token_error)
		{
			std::cout << "Syntax error in " << line << " line. Exit.\n";
			flagError = 1;
			break ;
		}
		else if (i->token == token_eol)
			line++;
		else if (i->token == 1 || i->token == 4)
		{
			check = i + 1;
			if (check->token < 13 || check->token > 17)
			{
				std::cout << "Syntax error in " << line << " line. Exit.\n";
				flagError = 1;
				break ;
			}
		}
	}
	return (flagError);
}

std::vector<Token> &Flex::getTokenVec()
{
	return tokenVec;
}