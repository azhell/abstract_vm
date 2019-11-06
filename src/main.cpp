/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:55:23 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/10/30 17:26:24 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Flex.hpp"
#include "Parser.hpp"
#include "Ecxeption.hpp"

int main(int ac, char **av)
{
	try
	{

		if (ac < 2)
		{
			Flex flex;
			flex.createTokens();
			if (!flex.scanError())
			{
				Parser parse(flex.getTokenVec());
				parse.start();
			}
		}
		else if (ac == 2)
		{
			Flex flex(av[1]);
			flex.createTokens();
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
	return (0);
}