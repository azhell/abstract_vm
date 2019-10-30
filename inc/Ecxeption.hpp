/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ecxeption.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:28:45 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/30 13:30:09 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class Exception : public std::exception
{
public:
	Exception(){};
	Exception(const Exception &);
	const Exception &operator=(const Exception &);
	virtual const char *what() const throw()
	{
		return _msg.c_str();
	}

	virtual ~Exception() throw() {}

private:
	std::string _msg;
};