//
//
//
//
//
//
//

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