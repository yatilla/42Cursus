/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42koceali.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:24:21 by yatilla           #+#    #+#             */
/*   Updated: 2022/02/09 17:08:49 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int val, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)s;
	while (n-- > 0)
			*x++ = val;
	return (s);
}
