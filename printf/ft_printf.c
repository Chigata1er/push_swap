/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:09:30 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/21 13:09:34 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_format(int s, va_list var)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putcharr(va_arg(var, int));
	else if (s == 's')
		count += ft_putstr(va_arg(var, char *));
	else if (s == 'p')
		count += hexa_base_p(va_arg(var, unsigned long long), 16, 'u');
	else if (s == 'd')
		count += ft_putnbr(va_arg(var, int));
	else if (s == 'i')
		count += ft_putnbr(va_arg(var, int));
	else if (s == 'u')
		count += ft_putnbr(va_arg(var, unsigned int));
	else if (s == 'x')
		count += hexa_base(va_arg(var, unsigned int), 16, 'u');
	else if (s == 'X')
		count += hexa_base(va_arg(var, unsigned int), 16, 'l');
	else if (s == '%')
		count += ft_putcharr('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	var;

	i = 0;
	count = 0;
	va_start(var, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			count += ft_format(s[i + 1], var);
			i++;
		}
		else
			count += ft_putcharr(s[i]);
		i++;
	}
	return (count);
}
/*
int	main()
{
	int i = 42;
	ft_printf("essayons  d ecrire : %%d \n", i);
	return 0;
}*/
