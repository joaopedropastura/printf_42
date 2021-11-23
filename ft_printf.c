/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:48 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/23 10:52:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char )c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int type_flag(va_list args, const char *format)
{
	char flag;

	flag = *ft_strchr("cspdiuxX%", *format);
	if(flag == 'c')
		return (write(1, args, 1));
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
			len += type_flag(args, format);
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
	printf("%s\n", "mac");
	a = ft_printf("%c\n", 'o');
}

// printf("macarrao%s")
