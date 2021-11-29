/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:18:45 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/29 15:39:13 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int ft_type_c(int chr)
{
	return (write(1, &chr, 1));
}

int ft_type_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str) * sizeof(char)));
}

int	ft_type_p(unsigned long int ptr)
{
	char	*str;
	char	*temp;
	int		write_len;

	if (!ptr && !IS_MACOS)
		return (write(1, "(nil)", 5));
	else if (!ptr)
		return (write(1, "0x0", 3));
	else
	{
		str = ft_base_converter(ptr, HEX);
		temp = str;
		str = ft_strjoin("0x", temp);
		free(temp);
		write_len = write(1, str, ft_strlen(str) * sizeof(char));
		free(str);
		return (write_len);
	}
}

int ft_type_diu(int nbr, char type)
{
	char	*str;
	int		write_len;

	if (nbr == 0)
		return (write(1, "0", 1));
	if (ft_strchr("di", type))
		str = ft_itoa(nbr);
	else
		str = ft_uitoa(nbr);
	write_len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (write_len);
}
int	ft_type_Xx(unsigned int to_hex, char type)
{
	char	*str;
	int		write_len;

	if (to_hex == 0)
		return (write(1, "0", 1));
	if (type == 'X')
		str = ft_base_converter(to_hex, HEX_UPPER);
	else
		str = ft_base_converter(to_hex, HEX);
	write_len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (write_len);
}
