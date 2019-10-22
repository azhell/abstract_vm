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

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"
#include <vector>
#include <sstream>


int main(int ac, char **av)
{
//	int32_t number = Int8;
	std::vector<IOperand const*> vec;
	Factory factory;
	IOperand const *ed;


	IOperand const *test = factory.createOperand(Int8, "22");
	IOperand const *test2 = factory.createOperand(Int8, "22");
	vec.push_back(test);
	vec.push_back(test2);
	ed = *(vec.rend());



	system("leaks avm");
	return (0);
}