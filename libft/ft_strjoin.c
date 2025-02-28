/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:42:51 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/09 13:42:52 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft.h"
#include <stdlib.h>

static char	*ft(char *str, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (ft_strdup(""));
		else
			return (ft_strdup(s2));
	}
	if (s2 == NULL)
	{
		if (s1 == NULL)
			return (ft_strdup(""));
		else
			return (ft_strdup(s1));
	}
	str = (char *)malloc((ft_strlen(s1)+ ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft(str, s1, s2);
	return (str);
}
