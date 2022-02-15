/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42koceali.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:08:27 by yatilla           #+#    #+#             */
/*   Updated: 2022/02/15 09:25:20 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int x)
{
	char	*last_pos;

	last_pos = (0);
	while (*s)
	{
		if (*s == x)
			last_pos = (char *)s;
		++s;
	}
	if (last_pos)
		return (last_pos);
	if (x == '\0')
		return ((char *)s);
	return (0);
}
