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

template <typename T>
class Operand : public IOperand
{
private:
	T _value;
	eOperandType _type;
	int _precision;

public:
	Operand()
	{
		return;
	}

	Operand(std::string arg, eOperandType type, int precision) : _type(type),
																 _precision(precision)
	{
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
		return (this->_type);
	}

	std::string const &toString(void) const
	{
		return (0);
	}

	IOperand const *operator+(IOperand const &rhs) const
	{
		return (0);
	}

	IOperand const *operator-(IOperand const &rhs) const
	{
		return (0);
	}

	IOperand const *operator*(IOperand const &rhs) const
	{
		return (0);
	}

	IOperand const *operator/(IOperand const &rhs) const
	{
		return (0);
	}

	IOperand const *operator%(IOperand const &rhs) const
	{
		return (0);
	}
};
