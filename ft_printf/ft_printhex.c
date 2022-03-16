/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:33:13 by yatilla           #+#    #+#             */
/*   Updated: 2022/03/16 12:03:57 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned int num)
{
	unsigned int	a;

	a = 0;
	while (num != 0)
	{
		num /= 16;
		a++;
	}
	return (a);
}

int	check_x(char x)
{
	if (x == 'X')
		return (0);
	else
		return (1);
}

void	ft_printbig(unsigned int num, int len, char *str)
{
	if ((num % 16) > 9)
		str[len] = ((num % 16) % 10) + 'A';
	else
		str[len] = '0' + (num % 16);
}

void	ft_printsm(unsigned int num, int len, char *str)
{
	if ((num % 16) > 9)
		str[len] = ((num % 16) % 10) + 'a';
	else
		str[len] = '0' + (num % 16);
}

int	ft_printhex(unsigned int num, char format)
{
	char	*str;
	int		newlen;
	int		len;

	len = hexlen(num);
	newlen = len;
	str = calloc(newlen, sizeof(char));
	if (num == 0)
		return (ft_putchar('0'));
	str = (char *)malloc(sizeof(char) * newlen + 1);
	while (num != 0)
	{
		len--;
		if (check_x(format) == 1)
			ft_printsm(num, len, str);
		else
			ft_printbig(num, len, str);
	num /= 16;
	}
	ft_printstr(str);
	free(str);
	return (newlen);
}
