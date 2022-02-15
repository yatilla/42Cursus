/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42koceali.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:58:08 by yatilla           #+#    #+#             */
/*   Updated: 2022/02/10 12:09:55 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;
	size_t	c;

	c = ((size_t)start);
	if (s == 0)
		return (0);
	b = malloc((len + 1) * sizeof(char));
	if (b == 0)
		return (0);
	a = 0;
	while (a < len && c < ft_strlen(s))
	{
		b[a] = s[c + a];
		a++;
	}
	b[a] = '\0';
	return (b);
}
