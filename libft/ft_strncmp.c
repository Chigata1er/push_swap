/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:32:30 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/05 19:40:55 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "./libft.h"

int	ft_strncmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	c1 = ((const unsigned char *)s1)[i];
	c2 = ((const unsigned char *)s2)[i];
	if (n == 0)
		return (0);
	while (i < n)
	{
		c1 = ((const unsigned char *)s1)[i];
		c2 = ((const unsigned char *)s2)[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (c1 - c2);
}
