/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:18:45 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/28 11:46:12 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include"ft_printf.h"

int ft_type_c(int chr)
{
	return (write(1, &chr, 1));
}
int ft_type_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, strlen(str)));
}
int ft_type_p(unsigned int ptr)
{
	if (!ptr && !IS_MACOS)
		return (write(1, "(nil)", 5));
	else if (!ptr)
		return (write(1, "0x0", 3));
	else
	{

	}

}
int ft_type_diu(int nbr, char type)
{
	if (ft_strchr("di", type))
		return (write(1, ft_itoa(nbr), ft_digits_len(nbr)));
	else
	{
		return (write(1, ft_uitoa(nbr), ft_digits_len(nbr)));
	}
}
