/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:48 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/29 09:35:34 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
# define MAX_LONG_INT 4294967296
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	len = malloc(size + 1 * sizeof(char));
	if (len == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		len[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		len[i] = s2[j];
		i++;
		j++;
	}
	len[i] = '\0';
	return (len);
}

char	*ft_base_converter(unsigned long int nbr, char *base)
{
	unsigned int	aux;
	char			*str;
	int				base_len;
	int				len;

	aux = nbr;
	base_len = ft_strlen(base);
	len = 0;
	if (aux == 0)
		len = 1;
	while (aux)
	{
		aux = aux / base_len;
		len++;
	}
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (!str[0])
	{
		str[len--] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	return (str);
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
		len = MAX_LONG_INT - (n * -1);
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
		number = MAX_LONG_INT - (n * -1);
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

int	ft_type_p(unsigned long int ptr)
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

int ft_type_diu(int nbr, char type)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	if (ft_strchr("di", type))
		return (write(1, ft_itoa(nbr), ft_digits_len(nbr)));
	else
	{
		return (write(1, ft_uitoa(nbr), ft_digits_ulen(nbr)));
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
		return (ft_type_p(va_arg(args, unsigned long int)));
	if (ft_strchr("diu", type))
		return (ft_type_diu(va_arg(args, int), type));
	if (ft_strchr("Xx", type))
		return (ft_type_Xx(va_arg(args, int), type));
	if (type == '%')
		return (write(1, "%", 1));
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
		if (*format == '%' && ft_strchr("cspudixX%", *(format + 1)))
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
	int a = 2300;
	char *b = "paoComCarneE4QueijoEFarofa";
	char *c = "oi";

	printf("%d\n", printf("test printf: %X\n", a));
	printf("%d\n", ft_printf("test printf: %X\n", a));
}
