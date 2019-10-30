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
//TODO		COPLIEN #############################################################
//TODO		LEX_ECXEPT #########
//

#include "Flex.hpp"
#include "Parser.hpp"
#include "Ecxeption.hpp"

int main(int ac, char **av)
{
	/* std::vector<IOperand const *> vec;
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
	} */
	try
	{

		if (ac < 2)
		{
			Flex flex;
			flex.createTokens();
			std::vector<Token> &tok = flex.getTokenVec();
			if (!flex.scanError())
			{
			}
		}
		else if (ac == 2)
		{
			Flex flex(av[1]);
			flex.createTokens();
			std::vector<Token> &tok = flex.getTokenVec();
			if (!flex.scanError())
			{
				Parser parse(flex.getTokenVec());
				parse.start();
			}
		}
		else
		{
			std::cout << "Usage: avm  || avm [file command.avm]" << std::endl;
		}
	}
	catch (const Exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	system("leaks avm");
	return (0);
}