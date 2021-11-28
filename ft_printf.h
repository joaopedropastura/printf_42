/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:16:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/26 15:20:52 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

int ft_printf(const char *format, ...);
int ft_type(va_list args, const char *format);

#endif
