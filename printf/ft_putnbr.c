/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:41:41 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/09 13:41:42 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_putnbr(long long int n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		j += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		j += ft_putnbr(n / 10);
	}
	j += write(1, &"0123456789"[n % 10], 1);
	return (j);
}
