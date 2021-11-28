/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:48 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/28 11:36:11 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INT 4294967296

#if __APPLE__
#define IS_MACOS 1
#else
#define IS_MACOS 0
#endif

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

static long int ft_digits_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *result;
	long int len;
	unsigned int number;

	len = ft_digits_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		result[0] = '-';
	}
	else
		number = n;
	while (number > 0)
	{
		result[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (result);
}

static long int ft_digits_ulen(unsigned int n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		len = MAX_INT - (n * -1);
		return (len);
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char *ft_uitoa(unsigned int n)
{
	char *result;
	unsigned int len;
	unsigned int number;

	len = ft_digits_ulen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		number = MAX_INT - (n * -1);
		result[0] = '-';
	}
	else
		number = n;
	while (number > 0)
	{
		result[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (result);
}

// --------------------------------------------------------
// |                                                      |
// |                                                      |
// |                   ∆ function aux ∆                   |
// |                                                      |
// |                                                      |
// --------------------------------------------------------

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

int ft_type_p(unsigned long ptr)
{
	if (!ptr && !IS_MACOS)
		return (write(1, "(nil)", 5));
	else if (!ptr)
		return (write(1, "0x0", 3));
}

int ft_type_diu(int nbr, char type)
{
	if (ft_strchr("di", type))
		return (write(1, ft_itoa(nbr), ft_digits_len(nbr)));
	else
		return (write(1, ft_uitoa(nbr), ft_digits_ulen(nbr)));
}

// --------------------------------------------------------
// |                                                      |
// |                                                      |
// |               ∆ types of imput ∆                     |
// |                                                      |
// |                                                      |
// --------------------------------------------------------

int ft_type(va_list args, const char *format)
{
	char type;

	type = *ft_strchr("cspdiuxX%", *format);
	if (type == 'c')
		return (ft_type_c(va_arg(args, int)));
	if (type == 's')
		return (ft_type_s(va_arg(args, char *)));
	if (type == 'p')
		return (ft_type_p(va_arg(args, unsigned long)));
	if (ft_strchr("diu", type))
		return (ft_type_diu(va_arg(args, int), type));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
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
	int a = -100;
	char *b = "paoComCarneE4Queijo";
	char *c = 'o';

	printf("%d\n", printf("test printf: %s\n", b));
	printf("%d\n", ft_printf("test ft_printf: %s\n", b));
}
