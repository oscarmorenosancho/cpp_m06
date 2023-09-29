/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 12:01:59 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

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
	bool	cFault = false;
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
	cFault = (value.length() != 1);
	if (!cFault)
		cValue = value[0];
	else if ((long)iValue >= 0x80 && (long)iValue <= 0x7F)
		cValue = (char)iValue;
	if (cValue == 0)
		std::cout << "char: " << "(" << cFault << ") " << NON_DISPLAY << std::endl;
	else
		std::cout << "char: " << "(" << cFault << ") '" << cValue << "'" << std::endl;
	std::cout << "int: " << "(" << iFault << ") " << std::setw(20) << iValue << std::endl;
	std::cout << "float: " << "(" << fFault << ") " << std::setw(20) << std::setprecision(7) << fValue << std::endl;
	std::cout << "double: " << "(" << dFault << ") " << std::setw(20) << std::setprecision(16) << dValue << std::endl;
}
