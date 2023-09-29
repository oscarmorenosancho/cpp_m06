/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:13:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 12:58:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERILIZER_HPP_
# define _SERILIZER_HPP_

#include <string>
#include "Data.hpp"
#define NON_DISPLAY "Non displayable"
#define IMPOSIBLE "impossible"

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& b);
	Serializer& operator=(const Serializer& b);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif