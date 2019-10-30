/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:29:17 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/30 14:12:05 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	token_end = 0,
//	token_error = 1,
//	token_push = 2,
//	token_pop = 3,
//	token_dump = 4,
//	token_assert = 5,
//	token_add = 6,
//	token_sub = 7,
//	token_mul = 8,
//	token_div = 9,
//	token_mod = 10,
//	token_print = 11,
//	token_exit = 12,

#pragma once
#include "IOperand.hpp"
#include "Flex.hpp"
#include "Factory.hpp"
#include "Ecxeption.hpp"
#include <iostream>
#include <vector>

class Parser
{
private:
	std::vector<Token> _vec;

public:
	void start();
	void end(std::vector<Token>::iterator &);
	void push(std::vector<Token>::iterator &);
	void pop(std::vector<Token>::iterator &);
	void dump(std::vector<Token>::iterator &);
	void assert(std::vector<Token>::iterator &);
	void add(std::vector<Token>::iterator &);
	void sub(std::vector<Token>::iterator &);
	void mul(std::vector<Token>::iterator &);
	void div(std::vector<Token>::iterator &);
	void mod(std::vector<Token>::iterator &);
	void print(std::vector<Token>::iterator &);
	void e_exit(std::vector<Token>::iterator &);
	Parser(std::vector<Token> &vec);
	class parsExcep : public Exception
	{
	private:
		std::string _error;

	public:
		parsExcep(const std::string &error) : _error(error) {}
		virtual ~parsExcep() throw() {}
		virtual const char *what() const throw()
		{
			return _error.c_str();
		}
	};
	std::array<void (Parser::*)(std::vector<Token>::iterator &), 12> ListFunc;
	std::vector<IOperand const *> stack;
	Factory factory;
	~Parser();
};
