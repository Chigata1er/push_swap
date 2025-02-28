/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:14:23 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/04 14:28:35 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "./libft.h"

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (*c++ != '\0')
		i++;
	return (i);
}
/*
int	main()
{
	printf("%d", ft_strlen("hgduhf "));
		return 0;
}*/
