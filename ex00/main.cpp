/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:06:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/28 17:09:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: " << std::endl;
		std::cerr << "Usage " << argv[0] << "value_to_convert" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
