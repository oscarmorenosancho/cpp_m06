/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/28 17:19:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& b)
{
	(void)b;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& b)
{
	(void)b;
	return (*this);
}

void	ScalarConverter::convert(std::string value)
{
	int		iValue = 0;
	float	fValue = 0.0f;
	double	dValue = 0.0;
	char	cValue = 0;
	bool	iFault = false;
	bool	fFault = false;
	bool	dFault = false;
	try
	{
		iValue = std::stoi(value);
	}
	catch(const std::exception& e)
	{
		iFault = true;
	}
	try
	{
		fValue = std::stof(value);
	}
	catch(const std::exception& e)
	{
		fFault = true;
	}
	try
	{
		dValue = std::stod(value);
	}
	catch(const std::exception& e)
	{
		dFault = true;
	}
	if (value.length() == 1)
		cValue = value[0];
	else if ((long)iValue >= 0x80 && (long)iValue <= 0x7F)
		cValue = (char)iValue;
	if (cValue == 0)
		std::cout << "char: " << NON_DISPLAY << std::endl;
	else
		std::cout << "char: '" << cValue << "'" << std::endl;
	std::cout << "int: " << iValue << std::endl;
	std::cout << "float: "<< fValue << std::endl;
	std::cout << "double: "<< dValue << std::endl;
}
