/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:06:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 13:13:34 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data 		data;
	Data 		*pRetData;
	uintptr_t	uip;

	uip = Serializer::serialize(&data);
	pRetData = Serializer::deserialize(uip);
	std::cout << "Pointer to Data: " << &data << std::endl;
	std::cout << "uintptr_t: " << uip << std::endl;
	std::cout << "uintptr_t: " << *(int *)uip << std::endl;
	std::cout << "Returned pointer to data: " << pRetData << std::endl;
	std::cout << ((&data == pRetData) ? "Equal" : "Non Equal") << std::endl;
	return (0);
}
