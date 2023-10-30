/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:59 by framador          #+#    #+#             */
/*   Updated: 2023/10/30 16:39:01 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef DEC
#  define DEC "0123456789"
# endif

# ifndef L_HEX
#  define L_HEX "0123456789abcdef"
# endif

# ifndef H_HEX
#  define H_HEX "0123456789ABCDEF"
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_lencount(unsigned long n, int blen);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
char	*ft_itoa(unsigned long n, char *base, int blen);
#endif
