/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/02 17:26:29 by omoreno-         ###   ########.fr       */
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
	typedef enum e_type
	{
		TYPE_INVALID,
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE
	}	t_type;
	typedef struct s_counts
	{
		size_t alphas;
		size_t digits;
		size_t signs;
		size_t exps;
		size_t floats;
		size_t dots;
		size_t spaces;
	}	t_counts;
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& b);
	ScalarConverter& 	operator=(const ScalarConverter& b);
	static void			print_char(char cV);
	static void			print_int(int iV);
	static void			print_float(float fV);
	static void			print_double(double dV);
	static void			print_all_impossible();
	static void			show_char(std::string trimmed);
	static void			show_int(std::string trimmed);
	static void			show_float(std::string trimmed);
	static void			show_double(std::string trimmed);
	static std::string	trim(std::string value);
	static t_counts		counts(std::string value);
	static t_type		identify(std::string value);
public:
	static void	convert(std::string value);
};

#endif
