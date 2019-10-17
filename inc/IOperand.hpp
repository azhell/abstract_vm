/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:21:33 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/17 16:33:49 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

enum eOperandType {Int8, Int16, Int32, Float, Double};

class IOperand
{
public:
	virtual int getPrecision(void) const = 0;						  // Precision of the type of the instance
	virtual eOperandType getType(void) const = 0;					  // Type of the instance
	virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
	virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
	virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
	virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
	virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo
	virtual std::string const &toString(void) const = 0;			  // String representation of the instance
	virtual ~IOperand(void) {}
};