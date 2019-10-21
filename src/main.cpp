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


int main(int ac, char **av)
{
//	int32_t number = Int8;
	std::vector<IOperand> vec;
	Factory factory;

	IOperand *test = new Operand<int8_t>;

	return (0);
}