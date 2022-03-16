/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:01:57 by yatilla           #+#    #+#             */
/*   Updated: 2022/03/15 22:34:06 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_wrt(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_wrt(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr_wrt(nbr / 10);
		ft_putchar('0' + (nbr % 10));
	}
	else
		ft_putchar('0' + (nbr % 10));
}

int	ft_putnbr(int nbr)
{
	int	len;

	len = 0;
	ft_putnbr_wrt(nbr);
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
