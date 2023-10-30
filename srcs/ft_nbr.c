/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:32:27 by framador          #+#    #+#             */
/*   Updated: 2023/10/30 16:39:56 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lencount(unsigned long n, int blen)
{
	int	count;

	count = 1;
	while (n > (unsigned long)blen - 1)
	{
		n /= blen;
		count++;
	}
	return (count);
}

char	*ft_itoa(unsigned long n, char *base, int blen)
{
	char	*str;
	int		len;

	len = ft_lencount(n, blen);
	str = (char *)malloc((len-- + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + 1] = 0;
	while (len >= 0)
	{
		str[len--] = base[n % blen];
		n = n / blen;
	}
	return (str);
}
