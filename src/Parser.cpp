/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:28:37 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/11/06 12:24:57 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(std::vector<Token> &vec) : _vec(vec)
{
	ListFunc.at(0) = &Parser::end;
	ListFunc.at(1) = &Parser::push;
	ListFunc.at(2) = &Parser::pop;
	ListFunc.at(3) = &Parser::dump;
	ListFunc.at(4) = &Parser::assert;
	ListFunc.at(5) = &Parser::add;
	ListFunc.at(6) = &Parser::sub;
	ListFunc.at(7) = &Parser::mul;
	ListFunc.at(8) = &Parser::div;
	ListFunc.at(9) = &Parser::mod;
	ListFunc.at(10) = &Parser::print;
	ListFunc.at(11) = &Parser::e_exit;
	return;
}

Parser::~Parser()
{
	for (std::vector<IOperand const *>::iterator  i = stack.begin(); i != stack.end(); ++i)
	{
		IOperand const *del = *i;
		delete del;
	}
	return;
}

void Parser::start()
{
	for (std::vector<Token>::iterator i = _vec.begin(); i != _vec.end(); ++i)
	{
		if (i->token < 12)
			(this->*ListFunc.at(i->token))(i);
	}
}

void Parser::push(std::vector<Token>::iterator &it)
{
	std::vector<Token>::iterator i = it + 1;
	stack.push_back(factory.createOperand(
		static_cast<eOperandType>(i->token - token_int8), i->value));
}

void Parser::pop(std::vector<Token>::iterator &it)
{
	if (stack.size() == 0)
		throw Parser::parsExcep("Illegal command pop. Empty stack");
	else
	{
		std::vector<IOperand const *>::reverse_iterator it = stack.rbegin();
		IOperand const *del = *it;
		delete del;
		stack.pop_back();
	}
	(void)it;
}

void Parser::dump(std::vector<Token>::iterator &it)
{
	IOperand const *ed;
	for (std::vector<IOperand const *>::reverse_iterator i = stack.rbegin(); i != stack.rend(); ++i)
	{
		ed = *i;
		std::cout << ed->toString() << "\n";
	}
	(void)it;
}

void Parser::assert(std::vector<Token>::iterator &it)
{
	if (stack.size() == 0)
		throw Parser::parsExcep("Illegal command assert. Empty stack");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *del = *d;
	std::vector<Token>::iterator check = it + 1;
	if ((check->token - token_int8) != del->getType())
		throw Parser::parsExcep("Illegal command assert. Error type");
	if (del->toString() != check->value)
		throw Parser::parsExcep("Assert: different value");
	(void)it;
}
void Parser::add(std::vector<Token>::iterator &it)
{
	if (stack.size() < 2)
		throw Parser::parsExcep("Illegal command add. Not found two operand");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *op2 = *d;
	IOperand const *op1 = *(d + 1);
	IOperand const *op3 = *op1 + *op2;
	delete op1;
	stack.pop_back();
	delete op2;
	stack.pop_back();
	stack.push_back(op3);
	(void)it;
}
void Parser::sub(std::vector<Token>::iterator &it)
{
	if (stack.size() < 2)
		throw Parser::parsExcep("Illegal command sub. Not found two operand");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *op2 = *d;
	IOperand const *op1 = *(d + 1);
	IOperand const *op3 = *op1 - *op2;
	delete op1;
	stack.pop_back();
	delete op2;
	stack.pop_back();
	stack.push_back(op3);
	(void)it;
}
void Parser::mul(std::vector<Token>::iterator &it)
{
	if (stack.size() < 2)
		throw Parser::parsExcep("Illegal command mul. Not found two operand");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *op2 = *d;
	IOperand const *op1 = *(d + 1);
	IOperand const *op3 = *op1 * *op2;
	delete op1;
	stack.pop_back();
	delete op2;
	stack.pop_back();
	stack.push_back(op3);
	(void)it;
	(void)it;
}
void Parser::div(std::vector<Token>::iterator &it)
{
	if (stack.size() < 2)
		throw Parser::parsExcep("Illegal command div. Not found two operand");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *op2 = *d;
	IOperand const *op1 = *(d + 1);
	IOperand const *op3 = *op1 / *op2;
	delete op1;
	stack.pop_back();
	delete op2;
	stack.pop_back();
	stack.push_back(op3);
	(void)it;
	(void)it;
}
void Parser::mod(std::vector<Token>::iterator &it)
{
	if (stack.size() < 2)
		throw Parser::parsExcep("Illegal command mod. Not found two operand");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *op2 = *d;
	IOperand const *op1 = *(d + 1);
	IOperand const *op3 = *op1 % *op2;
	delete op1;
	stack.pop_back();
	delete op2;
	stack.pop_back();
	stack.push_back(op3);
	(void)it;
	(void)it;
}
void Parser::print(std::vector<Token>::iterator &it)
{
	if (stack.size() == 0)
		throw Parser::parsExcep("Illegal command print. Empty stack");
	std::vector<IOperand const *>::reverse_iterator d = stack.rbegin();
	IOperand const *op1 = *d;
	if (op1->getType() != Int8)
		throw Parser::parsExcep("Illegal command print. Object not int8");
	char ch = static_cast<char>(std::atoi(op1->toString().c_str()));
	std::cout << ch << std::endl;;
	(void)it;
}
void Parser::e_exit(std::vector<Token>::iterator &it)
{
	for (std::vector<IOperand const *>::iterator i = stack.begin(); i != stack.end(); ++i)
	{
		IOperand const *del = *i;
		delete del;
	}
	(void)it;
	exit(0);
}

void Parser::end(std::vector<Token>::iterator &it)
{
	(void)it;
}