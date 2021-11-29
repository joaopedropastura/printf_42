/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:18:45 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/28 23:15:34 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include"ft_printf.h"

int	ft_type_c(int chr)
{
	return (write(1, &chr, 1));
}

int	ft_type_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, strlen(str)));
}

int	ft_type_p(unsigned int ptr)
{
	char	*str;
	char	*temp;

	if (!ptr && !IS_MACOS)
		return (write(1, "(nil)", 5));
	else if (!ptr)
		return (write(1, "0x0", 3));
	else
	{
		str = ft_base_converter(ptr, HEX);
		temp = ft_strjoin("0x", str);
		str = temp;
		return (write(1, str, ft_strlen(str) * sizeof(char)));
	}
}

int	ft_type_diu(int nbr, char type)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	if (ft_strchr("di", type))
		return (write(1, ft_itoa(nbr), ft_digits_len(nbr)));
	else
	{
		return (write(1, ft_uitoa(nbr), ft_digits_len(nbr)));
	}
}

int	ft_type_Xx(int to_hex, char type)
{
	char	*str;
	if (to_hex == 0)
		return (write(1, "0", 1));
	if (type == 'X')
		str = ft_base_converter(to_hex, HEX_UPPER);
	else
		str = ft_base_converter(to_hex, HEX);
	return (write(1, str, ft_strlen(str) * sizeof(char)));
}
