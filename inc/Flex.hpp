//
//
//
//
//
//

#pragma once

#undef yyFlexLexer
#define yyFlexLexer zzFlexLexer
#include <FlexLexer.h>

#include <iostream>
#include <fstream>
#include <istream>
#include <vector>

enum Tok
{
	token_end = 0,
	token_error = 1,
	token_push = 2,
	token_pop = 3,
	token_dump = 4,
	token_assert = 5,
	token_add = 6,
	token_sub = 7,
	token_mul = 8,
	token_div = 9,
	token_mod = 10,
	token_print = 11,
	token_exit = 12,
	token_comment = 13,
	token_int8 = 14,
	token_int16 = 15,
	token_int32 = 16,
	token_float = 17,
	token_double = 18,
	token_eol = 19
};

struct Token
{
	Tok token;
	std::string value;
};

class Flex
{
private:
	/* data */
	FlexLexer *lexer;
	bool flagError = true;
	std::vector<Token> _command;
	std::ifstream file;
	std::ofstream bug;
	std::vector<Token> tokenVec;

public:
	Flex();
	Flex(char *file);
	void createTokens();
	bool scanError();
	std::vector<Token> &getTokenVec();
	~Flex();
};
