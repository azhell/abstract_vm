/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:09:38 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/17 16:47:36 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"

template<typename T>
class Operand : public IOperand
{
private:
	T _value;
public:
	Operand(T arg)
	{

	}

	Operand operator=(Operand const &obj)
	{

	}

	Operand(Operand const &)
	{

	}

	~Operand()
	{
		return ;
	}

	int getPrecision(void) const
	{

	}

	std::string const &toString(void) const
	{

	}
	IOperand const *operator+(IOperand const &rhs) const
	{

	}
	IOperand const *operator-(IOperand const &rhs) const
	{

	}
	IOperand const *operator*(IOperand const &rhs) const
	{

	}
	IOperand const *operator/(IOperand const &rhs) const
	{

	}
	IOperand const *operator%(IOperand const &rhs) const
	{

	}
};

