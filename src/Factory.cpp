/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:48:25 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/30 17:25:43 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operand.hpp"
#include "IOperand.hpp"

Factory::Factory()
{
	ListFunc.at(0) = &Factory::createInt8;
	ListFunc.at(1) = &Factory::createInt16;
	ListFunc.at(2) = &Factory::createInt32;
	ListFunc.at(3) = &Factory::createFloat;
	ListFunc.at(4) = &Factory::createDouble;
	return;
}

Factory::~Factory()
{
	return;
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	IOperand const *(Factory::*func)(std::string const &)const;
	func = ListFunc[type];
	return ((*this.*func)(value));
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	IOperand const *ret = new Operand<int8_t>(value, Int8, 0, this);
	return (ret);
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	IOperand const *ret = new Operand<int16_t>(value, Int16, 0, this);
	return (ret);
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	IOperand const *ret = new Operand<int32_t>(value, Int32, 0, this);
	return (ret);
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	IOperand const *ret = new Operand<float>(value, Float, 7, this);
	return (ret);
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	IOperand const *ret = new Operand<double>(value, Double, 14, this);
	return (ret);
}