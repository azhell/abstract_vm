/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:55:23 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/21 19:35:39 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//			COPLIEN #############################################################
//

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"
#include <vector>
#include <sstream>

int main()
{
	std::vector<IOperand const *> vec;
	Factory factory;
	IOperand const *ed;

	{
		IOperand const *test = factory.createOperand(Int16, "22");
		IOperand const *test2 = factory.createOperand(Double, "10.222");
		vec.push_back(test);
		vec.push_back(test2);
		IOperand const *test3 = *test % *test2;
		vec.pop_back();
		vec.pop_back();
		vec.push_back(test3);
	}
	for (std::vector<IOperand const *>::reverse_iterator i = vec.rbegin(); i != vec.rend(); ++i)
	{
		ed = *i;
		std::cout << ed->toString() << std::endl;
	}

	system("leaks avm");
	return (0);
}