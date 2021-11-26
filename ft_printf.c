/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:48 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/26 11:01:37 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char )c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int ft_type_c(int chr)
{
	return(write(1, &chr, 1));
}

int ft_type_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, strlen(str)));
}

int ft_type(va_list args, const char *format)
{
	char type;

	type = *ft_strchr("cspdiuxX%", *format);
	if(type == 'c')
		return (ft_type_c(va_arg(args, int)));
	if(type == 's')
		return (ft_type_s(va_arg(args, char *)));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int len;

	va_start(args, format);
	len = 0;
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			len += ft_type(args, format);
			format++;
		}
		else
		{
			len += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (len);
}

int main(void)
{
	int a;
	char *b = "paoComCarneE4Queijo";
	// printf("%c%c%c%c%c\n", 'm', 'a', 'c', 'l', 'a');
	// a = ft_printf("%c%c%c%c%c\n", 'm', 'a', 'c', 'l', 'a');
	printf("%c\n%s\n", 'a', b);
	ft_printf("%c\n%s\n", 'a', b);
	write(1, b, strlen(b));
}

