/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:27:11 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/23 16:27:15 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

static int	ft_ex(int c)
{
	if (c == 'u')
		return (write(1, "ffffffff", 8));
	else
		return (write(1, "FFFFFFFF", 8));
}

int	hexa_base(long long int s, int base, int c)
{
	int		i;
	int		j;
	char	str[100];

	i = 0;
	j = 0;
	if (s == 0 || s == LONG_MIN)
		return (write(1, "0", 1));
	if (s == LONG_MAX)
		ft_ex(c);
	while (s != 0)
	{
		if (c == 'u')
			str[i++] = "0123456789abcdef"[s % base];
		else
			str[i++] = "0123456789ABCDEF"[s % base];
		s = s / base;
	}
	while (i > 0)
		j += write(1, &str[--i], 1);
	return (j);
}

int	hexa_base_p(unsigned long long s, int base, int c)
{
	int		i;
	int		j;
	char	str[100];

	i = 0;
	j = 0;
	if (s == 0)
		return (write(1, "(nil)", 5));
	j = write(1, "0x", 2);
	while (s != 0)
	{
		if (c == 'u')
			str[i++] = "0123456789abcdef"[s % base];
		else
			str[i++] = "0123456789ABCDEF"[s % base];
		s = s / base;
	}
	while (i > 0)
		j += write(1, &str[--i], 1);
	return (j);
}
