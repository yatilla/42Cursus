/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:03:06 by yatilla           #+#    #+#             */
/*   Updated: 2022/03/15 17:03:36 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsign(unsigned int u)
{
	static int	i;
	char		c;

	c = u % 10 + 48;
	i = 0;
	if (u)
		if (u / 10 != 0)
			ft_print_unsign(u / 10);
	write(1, &c, 1);
	return (++i);
}
