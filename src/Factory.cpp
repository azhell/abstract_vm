/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:48:25 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/21 20:02:01 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operand.hpp"
#include "IOperand.hpp"



Factory::Factory()
{
	func[0] = Factory::createInt8;
	return;
}

Factory::~Factory()
{
	return;
}

IOperand const Factory::*createOperand(eOperandType type, std::string const &value)
{
	switch (type)
	{
	case 1:

		break;
	case 2:
		/* code */
		break;
	case 3:
		/* code */
		break;
	case 4:
		/* code */
		break;
	case 5:
		/* code */
		break;
	default:
		break;
	}
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	IOperand const *ret = new Operand<int8_t>(value, Int8, 0);
	return (ret);
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	IOperand const *ret = new Operand<int16_t>(value, Int16, 1);
	return (ret);
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	IOperand const *ret = new Operand<int32_t>(value, Int32, 2);
	return (ret);
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	IOperand const *ret = new Operand<float>(value, Float, 3);
	return (ret);
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	IOperand const *ret = new Operand<double>(value, Double, 4);
	return (ret);
}