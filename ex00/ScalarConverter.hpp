/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/28 17:02:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#define NON_DISPLAY "Non displayable"
#define IMPOSIBLE "impossible"

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& b);
	ScalarConverter& operator=(const ScalarConverter& b);
public:
	static void	convert(std::string value);
};
