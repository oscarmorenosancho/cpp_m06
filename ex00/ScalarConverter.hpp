/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 18:15:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALARCONVERTER_HPP_
# define _SCALARCONVERTER_HPP_

#include <string>
#define NON_DISPLAY "Non displayable"
#define IMPOSSIBLE "impossible"

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& b);
	ScalarConverter& operator=(const ScalarConverter& b);
	static void	convert_char(char value);
	static void	convert_not_char(std::string value);
	static bool convert_to_int(int *i, std::string value);
	static bool convert_to_double(double *d, std::string value);
public:
	static void	convert(std::string value);
};

#endif
