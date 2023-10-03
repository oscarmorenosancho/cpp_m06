/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/03 11:47:00 by omoreno-         ###   ########.fr       */
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

std::string	ScalarConverter::trim(std::string value)
{
	std::string res = "";
	size_t start = 0;
	size_t end = value.length();

	if (end == 0)
		return (res);
	else
		end--;
	while (value[start] && start < end && value[start] <= ' ')
		start++;
	while (end >= 0 && start < end && value[end] <= ' ')
		end--;
	for (size_t i = start; i <= end; i++)
		res += value[i];
	return (res);
}

ScalarConverter::t_counts	ScalarConverter::counts(std::string value)
{
	ScalarConverter::t_counts	counts;
	size_t						i;
	size_t						len = value.length();

	counts.alphas = 0;
	counts.digits = 0;
	counts.exps = 0;
	counts.floats = 0;
	counts.signs = 0;
	counts.spaces = 0;
	counts.dots = 0;
	for (i = 0; i < len; i++)
	{
		char c = value[i];
		if (c <= ' ')
		{
			counts.spaces++;
			continue;
		}
		if (c > '0' && c < '9')
		{
			counts.digits++;
			continue;
		}
		if (c == 'e' || c == 'E')
		{
			counts.exps++;
			continue;
		}
		if (c == 'f' || c == 'F')
		{
			counts.floats++;
			continue;
		}
		if (c == '+' || c == '-')
		{
			counts.signs++;
			continue;
		}
		if (c == '.')
		{
			counts.dots++;
			continue;
		}
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			counts.alphas++;
			continue;
		}
	}
	return (counts);
}

void ScalarConverter::split_exp(std::string value, std::string& man, std::string& exp)
{
	size_t	i = 0;
	bool	e_found = false;

	man = "";
	exp = "";
	while (value[i])
	{
		if (value[i] == 'e' || value[i] == 'E')
			e_found = true;
		else
		{
			if (!e_found)
				man += value[i];
			else
				exp += value[i];
		}
		i++;
	}	
}

ScalarConverter::t_type	ScalarConverter::identify_exp(std::string value)
{
	std::string	man;
	std::string	exp;

	split_exp(value, man, exp);
	t_counts man_counted = counts(man);
	t_counts exp_counted = counts(exp);
	if (man_counted.signs > 1 || (man_counted.signs == 1 && !(man[0] == '-' || man[0] == '+'))
		|| (exp_counted.signs > 1 || (exp_counted.signs == 1 && !(exp[0] == '-' || exp[0] == '+')))
		|| exp_counted.dots > 0 || man_counted.floats > 0)
		return (TYPE_INVALID);
	if (exp_counted.floats == 0)
		return (TYPE_DOUBLE);
	if (exp_counted.floats == 1 && (exp[exp.length()-1] == 'f' || (exp[exp.length()-1] == 'F')))
		return (TYPE_FLOAT);
	return (TYPE_INVALID);
}

ScalarConverter::t_type	ScalarConverter::identify(std::string value)
{
	if (value.length() == 1)
		return (TYPE_CHAR);
	t_counts counted = counts(value);
	if (counted.spaces > 0 || counted.alphas > 0 || counted.exps > 1
		|| counted.floats > 1 || counted.dots > 1 || counted.signs > 2)
		return (TYPE_INVALID);
	if (counted.exps == 0)
	{
		if (counted.floats == 0 && counted.digits > 0
			&& (counted.signs == 0 || (counted.signs == 1 && (value[0] == '-' || value[0] == '+')))
			&& counted.dots == 0)
			return (TYPE_INT);
		if (counted.floats == 1
			&& (value[value.length()-1] == 'f' || (value[value.length()-1] == 'F'))
			&& (counted.signs == 0 || (counted.signs == 1 && (value[0] == '-' || value[0] == '+')))
			&& counted.dots < 2)
			return (TYPE_FLOAT);
		if (counted.floats == 0
			&& (counted.signs == 0 || (counted.signs == 1 && (value[0] == '-' || value[0] == '+')))
			&&	counted.dots < 2)
			return (TYPE_DOUBLE);
	}
	return (identify_exp(value));
}

void	ScalarConverter::print_char(char cV)
{
	if ((cV > ' ') && (cV < 127))
		std::cout << "char: " << cV << std::endl;
	else
		std::cout << "char: " << NON_DISPLAY << std::endl;
}

void			ScalarConverter::print_int(int iV)
{
	std::cout << "int: " << iV << std::endl;
}

void			ScalarConverter::print_float(float fV)
{
	if (fV >= 1.0 && fV < 9.0e6)
	{
		std::cout.setf(std::ios::showpoint);
		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(1);
	}
	else
		std::cout << std::setprecision(6);
	std::cout << "float: " << fV << "f" << std::endl;
}

void			ScalarConverter::print_double(double dV)
{
	if (dV >= 1.0 && dV < 9.0e15)
	{
		std::cout.setf(std::ios::showpoint); 
		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(1);
	}
	else
		std::cout << std::setprecision(15);
	std::cout << "double: " << dV << std::endl;
}

void	ScalarConverter::print_all_impossible()
{
	std::cout << "char: " << IMPOSSIBLE << std::endl;
	std::cout << "int: " << IMPOSSIBLE << std::endl;
	std::cout << "float: " << IMPOSSIBLE << std::endl;
	std::cout << "double: " << IMPOSSIBLE << std::endl;
}

void	ScalarConverter::show_char(std::string trimmed)
{
	char	cV;
	int		iV;
	float	fV;
	double	dV;
	cV = trimmed[0];
	iV = static_cast<int>(cV);
	fV = static_cast<float>(cV);
	dV = static_cast<double>(cV);
	// std::cout << "identified as char: \n";
	print_char(cV);
	print_int(iV);
	print_float(fV);
	print_double(dV);
}

void	ScalarConverter::show_int(std::string trimmed)
{
	char	cV;
	int		iV;
	float	fV;
	double	dV;
	try
	{
		iV = std::stoi(trimmed);
	}
	catch(const std::exception& e)
	{
		print_all_impossible();
		return ;
	}
	cV = static_cast<char>(iV);
	fV = static_cast<float>(iV);
	dV = static_cast<double>(iV);
	// std::cout << "identified as int: \n";
	if (iV < 0 || iV > 255)
		std::cout << "char: " << IMPOSSIBLE << std::endl;
	else
		print_char(cV);
	print_int(iV);
	print_float(fV);
	print_double(dV);
}

void	ScalarConverter::show_float(std::string trimmed)
{
	char	cV;
	int		iV;
	float	fV;
	double	dV;
	try
	{
		fV = std::stof(trimmed);
	}
	catch(const std::exception& e)
	{
		print_all_impossible();
		return ;
	}
	cV = static_cast<char>(fV);
	iV = static_cast<int>(fV);
	dV = static_cast<double>(fV);
	// std::cout << "identified as float: \n";
	if (fV < 0.0f || fV > 255.0f)
		std::cout << "char: " << IMPOSSIBLE << std::endl;
	else
		print_char(cV);
	if (fV < -2147483648.0 || fV > 2147483647.0)
		std::cout << "int: " << IMPOSSIBLE << std::endl;
	else
		print_int(iV);
	print_float(fV);
	print_double(dV);
}

void	ScalarConverter::show_double(std::string trimmed)
{
	char	cV;
	int		iV;
	float	fV;
	double	dV;
	try
	{
		dV = std::stod(trimmed);
	}
	catch(const std::exception& e)
	{
		print_all_impossible();
		return ;
	}
	cV = static_cast<char>(dV);
	iV = static_cast<int>(dV);
	fV = static_cast<float>(dV);
	// std::cout << "identified as double: \n";
	if (dV < 0.0 || dV > 255.0)
		std::cout << "char: " << IMPOSSIBLE << std::endl;
	else
		print_char(cV);
	if (dV < -2147483648.0 || dV > 2147483647.0)
		std::cout << "int: " << IMPOSSIBLE << std::endl;
	else
		print_int(iV);
	print_float(fV);
	print_double(dV);
}

void	ScalarConverter::convert(std::string value)
{
	std::string trimmed = trim(value);
	t_type t = identify(trimmed);
	switch (t)
	{
	case TYPE_CHAR:
		show_char(trimmed);
		break;
	case TYPE_INT:
		show_int(trimmed);
		break;
	case TYPE_FLOAT:
		show_float(trimmed);
		break;
	case TYPE_DOUBLE:
		show_double(trimmed);
		break;
	default:
		print_all_impossible();
		return ;
	}
}
