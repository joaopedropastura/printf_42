/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:16:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/29 10:45:38 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

int ft_printf(const char *format, ...);
int ft_type_c(int chr);
int ft_type_s(char *str);
int	ft_type_p(unsigned long int ptr);
int ft_type_diu(int nbr, char type);
int	ft_type_Xx(int to_hex, char type);

#endif
