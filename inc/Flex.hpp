/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flex.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:29:02 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/30 13:49:02 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#undef yyFlexLexer
#define yyFlexLexer zzFlexLexer
#include <FlexLexer.h>

#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include "Ecxeption.hpp"

enum Tok
{
	token_end = 0,
	token_error = 20,
	token_push = 1,
	token_pop = 2,
	token_dump = 3,
	token_assert = 4,
	token_add = 5,
	token_sub = 6,
	token_mul = 7,
	token_div = 8,
	token_mod = 9,
	token_print = 10,
	token_exit = 11,
	token_comment = 12,
	token_int8 = 13,
	token_int16 = 14,
	token_int32 = 15,
	token_float = 16,
	token_double = 17,
	token_eol = 18
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
	int flagError;
	int	exitError;
	std::vector<Token> _command;
	std::ifstream file;
	std::ofstream bug;
	std::vector<Token> tokenVec;

public:
	Flex();
	Flex(char *file);
	void createTokens();
	int scanError();
	std::vector<Token> &getTokenVec();
	class flexExcep : public Exception
	{
	private:
		std::string _error;

	public:
		flexExcep(const std::string &error) : _error(error) {}
		virtual ~flexExcep() throw() {}
		virtual const char *what() const throw()
		{
			return _error.c_str();
		}
	};
	~Flex();
};
