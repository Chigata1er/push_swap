/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:31:35 by ibyeo             #+#    #+#             */
/*   Updated: 2024/11/23 15:31:40 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int	hexa_base(long long int s, int base, int c);
int	ft_putcharr(int s);
int	ft_putnbr(long long int n);
int	ft_putstr(char *s);
int	ft_printf(const char *s, ...);
int	ft_putnbr_uns(unsigned long n);
int	hexa_base_p(unsigned long long s, int base, int c);

#endif
