/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 18:15:28 by omoreno-         ###   ########.fr       */
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

void	ScalarConverter::convert_char(char value)
{
	int		iValue = 0;
	float	fValue = 0.0f;
	double	dValue = 0.0;

	if (!std::isprint(value))
		std::cout << "char: " << NON_DISPLAY << std::endl;
	else
		std::cout << "char: '" << value << "'" << std::endl;
	iValue = static_cast<int>(value);
	fValue = static_cast<float>(iValue);
	dValue = static_cast<double>(iValue);
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout << std::setprecision(1);
	std::cout << "int: " << std::setw(20) << iValue << std::endl;
	std::cout << "float: " << std::setw(20) << fValue << "f" << std::endl;
	std::cout << "double: " << std::setw(20) << dValue << std::endl;
}

bool ScalarConverter::convert_to_int(int *i, std::string value)
{
	try
	{
		*i = std::stoi(value);
		return (false);
	}
	catch(const std::exception& e)
	{
		*i = 0;
		return (true);
	}
}

bool ScalarConverter::convert_to_double(double *d, std::string value)
{
	try
	{
		*d = std::stod(value);
		return (false);
	}
	catch(const std::exception& e)
	{
		*d = 0.0;
		return (true);
	}
}

void	ScalarConverter::convert_not_char(std::string value)
{
	int		iValue = 0;
	float	fValue = 0.0f;
	double	dValue = 0.0;
	char	cValue = 0;
	bool	iFault = false;
	bool	dFault = false;

	dFault = convert_to_double(&dValue, value);
	if (dFault)
	{
		std::cout << "char: " << IMPOSSIBLE << std::endl;
		std::cout << "int: " << IMPOSSIBLE << std::endl;
		std::cout << "float: " << IMPOSSIBLE << std::endl;
		std::cout << "double: " << IMPOSSIBLE << std::endl;
		return ;
	}
	fValue = static_cast<float>(dValue);
	iFault = convert_to_int(&iValue, value);
	if (iFault)
	{
		std::cout << "char: " << IMPOSSIBLE << std::endl;
		std::cout << "int: " << IMPOSSIBLE << std::endl;
		std::cout.setf(std::ios::fixed);
		std::cout.setf(std::ios::showpoint);
		std::cout << "float: " << std::setprecision(1) << fValue << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << dValue << std::endl;
		return ;
	}
	if (dValue >= static_cast<double>(-2147483648) && dValue <= static_cast<double>(2147483647))
	{
		iValue = static_cast<int>(dValue);
		cValue = static_cast<char>(iValue);
		if (iValue > 255 || !std::isprint(cValue))
			std::cout << "char: " << NON_DISPLAY << std::endl;
		else
			std::cout << "char: '" << cValue << "'" << std::endl;
		std::cout << "int: " << iValue << std::endl;
	}
	else
	{
		std::cout << "char: " << IMPOSSIBLE << std::endl;
		std::cout << "int: " << IMPOSSIBLE << std::endl;
	}
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout << "float: " << std::setprecision(1) << fValue << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << dValue << std::endl;
}

void	ScalarConverter::convert(std::string value)
{
	if (value.length() == 1)
		return (convert_char(value[0]));
	return (convert_not_char(value));
}