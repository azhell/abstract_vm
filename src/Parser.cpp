//
//
//
//
//
//
//

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
		stack.pop_back();
	}
}

void Parser::dump(std::vector<Token>::iterator &it)
{
	IOperand const *ed;
	for (std::vector<IOperand const *>::reverse_iterator i = stack.rbegin(); i != stack.rend(); ++i)
	{
		ed = *i;
		std::cout << ed->toString() << "\n";
	}
}

void Parser::assert(std::vector<Token>::iterator &it)
{
	if (stack.size() == 0)
		throw Parser::parsExcep("Illegal command assert. Empty stack");
	else
		stack.pop_back();
	std::vector<Token>::iterator i = it + 1;
	stack.push_back(factory.createOperand(
		static_cast<eOperandType>(i->token - token_int8), i->value));
}
void Parser::add(std::vector<Token>::iterator &it)
{
}
void Parser::sub(std::vector<Token>::iterator &it)
{
}
void Parser::mul(std::vector<Token>::iterator &it)
{
}
void Parser::div(std::vector<Token>::iterator &it)
{
}
void Parser::mod(std::vector<Token>::iterator &it)
{
}
void Parser::print(std::vector<Token>::iterator &it)
{
}
void Parser::e_exit(std::vector<Token>::iterator &it)
{
	exit(0);
}

void Parser::end(std::vector<Token>::iterator &it)
{
}