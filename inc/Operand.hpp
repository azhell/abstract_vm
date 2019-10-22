/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:09:38 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/21 19:52:01 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"
#include <iostream>

template <typename T>
class Operand : public IOperand
{
private:
	eOperandType _type;
	int _precision;
	T _value;
	std::string _st;

public:
	Operand()
	{
		return;
	}

	Operand(std::string arg, eOperandType type, int precision) : _type(type),
																 _precision(precision)
	{
		try
		{
			if (type < 3)
			{
				int64_t type = std::strtoll(arg.c_str(), nullptr, 10);
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		return;
	}

	eOperandType getType(void) const
	{
		return this->_type;
	}

	~Operand()
	{
		return;
	}

	int getPrecision(void) const
	{
		return (this->_precision);
	}

	std::string const &toString(void) const
	{
		return (this->_st);
	}

	IOperand const *operator+(IOperand const &rhs) const
	{
		IOperand const *ret = new Operand<int8_t>(_st, Int8, 0);
		return (ret);
	}

	IOperand const *operator-(IOperand const &rhs) const
	{
		IOperand const *ret = new Operand<int8_t>(_st, Int8, 0);
		return (ret);
	}

	IOperand const *operator*(IOperand const &rhs) const
	{
		IOperand const *ret = new Operand<int8_t>(_st, Int8, 0);
		return (ret);
	}

	IOperand const *operator/(IOperand const &rhs) const
	{
		IOperand const *ret = new Operand<int8_t>(_st, Int8, 0);
		return (ret);
	}

	IOperand const *operator%(IOperand const &rhs) const
	{
		IOperand const *ret = new Operand<int8_t>(_st, Int8, 0);
		return (ret);
	}
};
