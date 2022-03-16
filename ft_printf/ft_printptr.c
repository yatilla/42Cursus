/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:58:48 by yatilla           #+#    #+#             */
/*   Updated: 2022/03/16 00:48:18 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrlen(unsigned long long num)
{
	int	a;

	a = 0;
	while (num != 0)
	{
		num /= 16;
		a++;
	}
	return (a);
}

int	ft_printptr(unsigned long long num)
{
	char	*str;
	int		newlen;
	int		len;

	if (num == 0)
		return (ft_printstr("0x0"));
	len = ptrlen(num) + 2;
	newlen = len;
	str = malloc(sizeof(char) * len + 1);
	str[0] = '0';
	str[1] = 'x';
	while (num != '\0' && len > 2)
	{
		len--;
		if ((num % 16) > 9)
		str[len] = ((num % 16) % 10) + 'a';
		else
		str[len] = '0' + (num % 16);
		num /= 16;
	}
	ft_printstr(str);
	free(str);
	return (newlen);
}
