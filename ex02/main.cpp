/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:00:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 15:17:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	int		i = 0;
	Base	*base;

	while (i < 20)
	{
		base = Base::generate();
		Base::identify(base);
		i++;
	}
	return (0);
}
