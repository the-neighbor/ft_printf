/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:04:13 by adaly             #+#    #+#             */
/*   Updated: 2017/06/08 02:52:30 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char *str;

	str = ft_strdup("michael!");
	printf("yours:{%3*p}\n", 10, 0);
	ft_printf("mine:{%3*p}\n", 10, 0);
//	printf("yours{%3c}\n", 0);
//	ft_printf("mine{%3c}\n", 0);
//	ft_printf("drop%n that shit right now %n\n");
//	ft_printf("%#08x\nU is %U\n", 42, 5564);
//	ft_printf("hello %s number %c%0d\n", str, '#', 2);
}
