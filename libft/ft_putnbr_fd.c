/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:41:41 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/09 13:41:42 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./libft.h"
#include <stdlib.h>

static void	f2(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &str[i], 1);
		i--;
	}
}

static void	f3(int n, int fd)
{
	int		d;
	int		i;
	char	str[12];

	d = 0;
	i = 0;
	while (n > 0)
	{
		d = n % 10;
		n = n / 10;
		str[i] = d + '0';
		i++;
	}
	str[i] = '\0';
	f2(str, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		f3(n, fd);
	}
}
