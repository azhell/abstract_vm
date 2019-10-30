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

#pragma once

#include "Ecxeption.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include <iostream>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <iomanip>
#include <cmath>

template <typename T>
class Operand : public IOperand
{
private:
	eOperandType _type;
	int _precision;
	T _value;
	std::string _str;
	const Factory *_fact;

public:
	Operand()
	{
		return;
	}

	class overExcep : public Exception
	{
	private:
		std::string _error;

	public:
		overExcep(const std::string &error) : _error(error) {}
		virtual ~overExcep() throw() {}
		virtual const char *what() const throw()
		{
			return _error.c_str();
		}
	};

	Operand(std::string arg, eOperandType type, int prec, const Factory *fact) : _type(type),
																				 _precision(prec),
																				 _fact(fact)
	{
		try
		{
			if (type < 3)
			{
				int64_t val = std::strtoll(arg.c_str(), nullptr, 10);
				if (overFlow(val, type))
					throw Operand::overExcep("Overflow | Underflow");
				std::stringstream ss;
				this->_value = static_cast<T>(val);
				ss << val;
				this->_str = ss.str();
			}
			else
			{
				long double val = std::strtold(arg.c_str(), nullptr);
				if (overFlow(val, type))
					throw Operand::overExcep("Overflow | Underflow");
				this->_value = static_cast<T>(val);
				std::stringstream ss;
				ss << std::setprecision(_precision) << val;
				this->_str = ss.str();
			}
		}
		catch (const std::out_of_range &e)
		{
			e.what();
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
		return (this->_str);
	}

	IOperand const *operator+(IOperand const &rhs) const
	{
		try
		{
			std::stringstream ss;
			eOperandType type = (_type < rhs.getType()) ? rhs.getType() : _type;
			int pers = (_precision < rhs.getPrecision()) ? rhs.getPrecision() : _precision;
			if (_type < 3 && rhs.getType() < 3)
			{
				int64_t op1 = std::strtoll(_str.c_str(), nullptr, 10);
				int64_t op2 = std::strtoll(rhs.toString().c_str(), nullptr, 10);
				int64_t res = op1 + op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underflow");
				ss << res;
				return (_fact->createOperand(type, ss.str()));
			}
			else
			{
				long double op1 = std::strtold(_str.c_str(), nullptr);
				long double op2 = std::strtold(rhs.toString().c_str(), nullptr);
				long double res = op1 + op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underflow");
				ss << std::setprecision(pers) << res;
				return (_fact->createOperand(type, ss.str()));
			}
		}
		catch (const std::out_of_range &e)
		{
			e.what();
		}
		return (0);
	}

	IOperand const *operator-(IOperand const &rhs) const
	{
		try
		{
			std::stringstream ss;
			eOperandType type = (_type < rhs.getType()) ? rhs.getType() : _type;
			int pers = (_precision < rhs.getPrecision()) ? rhs.getPrecision() : _precision;
			if (_type < 3 && rhs.getType() < 3)
			{
				int64_t op1 = std::strtoll(_str.c_str(), nullptr, 10);
				int64_t op2 = std::strtoll(rhs.toString().c_str(), nullptr, 10);
				int64_t res = op1 - op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Undefrlow");
				ss << res;
				return (_fact->createOperand(type, ss.str()));
			}
			else
			{
				long double op1 = std::strtold(_str.c_str(), nullptr);
				long double op2 = std::strtold(rhs.toString().c_str(), nullptr);
				long double res = op1 - op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Undefrlow");
				ss << std::setprecision(pers) << res;
				return (_fact->createOperand(type, ss.str()));
			}
		}
		catch (const std::out_of_range &e)
		{
			e.what();
		}
		return (0);
	}

	IOperand const *operator*(IOperand const &rhs) const
	{
		try
		{
			std::stringstream ss;
			eOperandType type = (_type < rhs.getType()) ? rhs.getType() : _type;
			int pers = (_precision < rhs.getPrecision()) ? rhs.getPrecision() : _precision;
			if (_type < 3 && rhs.getType() < 3)
			{
				int64_t op1 = std::strtoll(_str.c_str(), nullptr, 10);
				int64_t op2 = std::strtoll(rhs.toString().c_str(), nullptr, 10);
				int64_t res = op1 * op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underflow");
				ss << res;
				return (_fact->createOperand(type, ss.str()));
			}
			else
			{
				long double op1 = std::strtold(_str.c_str(), nullptr);
				long double op2 = std::strtold(rhs.toString().c_str(), nullptr);
				long double res = op1 * op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underflow");
				ss << std::setprecision(pers) << res;
				return (_fact->createOperand(type, ss.str()));
			}
		}
		catch (const std::out_of_range &e)
		{
			e.what();
		}
		return (0);
	}

	IOperand const *operator/(IOperand const &rhs) const
	{
		try
		{
			std::stringstream ss;
			eOperandType type = (_type < rhs.getType()) ? rhs.getType() : _type;
			int pers = (_precision < rhs.getPrecision()) ? rhs.getPrecision() : _precision;
			if (_type < 3 && rhs.getType() < 3)
			{
				int64_t op1 = std::strtoll(_str.c_str(), nullptr, 10);
				int64_t op2 = std::strtoll(rhs.toString().c_str(), nullptr, 10);
				if (op2 == 0)
					throw Operand::overExcep("Division by zero");
				int64_t res = op1 / op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underlow");
				ss << res;
				return (_fact->createOperand(type, ss.str()));
			}
			else
			{
				long double op1 = std::strtold(_str.c_str(), nullptr);
				long double op2 = std::strtold(rhs.toString().c_str(), nullptr);
				if (op2 == 0.0)
					throw Operand::overExcep("Division by zero");
				long double res = op1 / op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underlow");
				ss << std::setprecision(pers) << res;
				return (_fact->createOperand(type, ss.str()));
			}
		}
		catch (const std::out_of_range &e)
		{
			e.what();
		}
		return (0);
	}

	IOperand const *operator%(IOperand const &rhs) const
	{
		try
		{
			std::stringstream ss;
			eOperandType type = (_type < rhs.getType()) ? rhs.getType() : _type;
			int pers = (_precision < rhs.getPrecision()) ? rhs.getPrecision() : _precision;
			if (_type < 3 && rhs.getType() < 3)
			{
				int64_t op1 = std::strtoll(_str.c_str(), nullptr, 10);
				int64_t op2 = std::strtoll(rhs.toString().c_str(), nullptr, 10);
				if (op2 == 0)
					throw Operand::overExcep("Division by zero");
				int64_t res = op1 % op2;
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underlow");
				ss << res;
				return (_fact->createOperand(type, ss.str()));
			}
			else
			{
				long double op1 = std::strtold(_str.c_str(), nullptr);
				long double op2 = std::strtold(rhs.toString().c_str(), nullptr);
				if (op2 == 0.0)
					throw Operand::overExcep("Division by zero");
				long double res = std::fmod(op1, op2);
				if (overFlow(res, type))
					throw Operand::overExcep("Overflow | Underlow");
				ss << std::setprecision(pers) << res;
				return (_fact->createOperand(type, ss.str()));
			}
		}
		catch (const std::out_of_range &e)
		{
			e.what();
		}
		return (0);
	}
	bool overFlow(int64_t val, eOperandType type) const
	{
		int sw = static_cast<int>(type);
		switch (sw)
		{
		case 0:
			return (val < CHAR_MIN || val > CHAR_MAX);
		case 1:
			return (val < INT16_MIN || val > INT16_MAX);
		case 2:
			return (val < INT32_MIN || val > INT32_MAX);
		}
		return (false);
	}
	bool overFlow(long double val, eOperandType type) const
	{
		int sw = static_cast<int>(type);
		switch (sw)
		{
		case 3:
			return (val < FLT_MIN || val > FLT_MAX);
		case 4:
			return (val < DBL_MIN || val > DBL_MAX);
		}
		return (false);
	}
};
