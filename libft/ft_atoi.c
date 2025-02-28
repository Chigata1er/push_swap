/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:38:14 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/09 13:38:21 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./libft.h"

static long	ft_help_atoi(long sign, long value, const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (value == 0)
				value += (str[i] - 48);
			else
				value = value * 10 + (str[i] - 48);
		}
		i++;
	}
	return (value * sign);
}

long	ft_atoi(const char *str)
{
	long	sign;
	long	value;
	long	retour;

	sign = 1;
	value = 0;
	retour = ft_help_atoi(sign, value, str);
	return (retour);
}
/*
int main()
{
    // Cas de test
    char *str1 = "++1";
     printf("Test 8: %s -> %d\n", str1, ft_atoi(str1));  // Devrait afficher 0

    return 0;
}*/
