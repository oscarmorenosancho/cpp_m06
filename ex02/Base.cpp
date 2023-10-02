/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:24:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/02 13:32:11 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{}
Base* Base::generate(void)
{
	std::chrono::system_clock::time_point 	cur;
 	static long								*seed;

	cur = std::chrono::system_clock::now();
	seed = (long *)((char *)&cur + 
			sizeof(std::chrono::system_clock::time_point) - sizeof(long));
	srand(*seed);
	int selec = rand() % 3;
    if (selec == 0)
		return (new A);
    if (selec == 1)
		return (new B);
	return (new C);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Not recognized" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e)
	{
		;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch(const std::exception& e)
	{
		;
	}
	std::cout << "Not recognized" << std::endl;
}

// void Base::identify(Base* p)
// {
// 	std::string	t;
// 	int			count;
	
// 	t = typeid(*p).name();
// 	try
// 	{
// 		count = (std::to_string(stoi(t))).length();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		count = 0;
// 	}
// 	std::cout << t.c_str() + count << std::endl;
// }

// void Base::identify(Base& p)
// {
// 	std::string	t;
// 	int			count;
	
// 	t = typeid(p).name();
// 	try
// 	{
// 		count = (std::to_string(stoi(t))).length();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		count = 0;
// 	}
// 	std::cout << t.c_str() + count << std::endl;
// }
