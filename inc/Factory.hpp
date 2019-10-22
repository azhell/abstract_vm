/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:48:03 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/21 20:05:07 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IOperand.hpp"
#include <map>
#include <array>

class Factory
{
private:
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;
	Factory operator=(Factory const &obj);
	Factory(Factory const &);

public:
	Factory();
	~Factory();
	IOperand const *createOperand(eOperandType type, std::string const &value) const;
	std::array<IOperand const *(Factory::*)(std::string const &)const, 5> ListFunc;
};
