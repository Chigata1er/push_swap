/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:38:47 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/09 13:38:50 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./libft.h"
#include <stdint.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*m;

	if (num > SIZE_MAX / size)
	{
		return (NULL);
	}
	m = malloc(num * size);
	if (m == NULL)
	{
		return (NULL);
	}
	ft_memset(m, 0, num * size);
	return (m);
}
