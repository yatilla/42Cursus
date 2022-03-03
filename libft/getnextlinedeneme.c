/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextlinedeneme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42koceali.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:52 by yatilla           #+#    #+#             */
/*   Updated: 2022/02/23 17:43:14 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int x;
	char *new;
	int end;

	x = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s1 && !s2)
		return (NULL);
	while (s1)
	{
		new[x] = s1[x];
		x++;
	}
	end = x;
	x = 0;
	while (s2 != NULL)
	{
		new[end + x] = s2[x];
		x++;
	}
	new[end + x] = 0;
	return (new);
}

char	*ft_strchr(const char *ptr, int a)
{
	int	x;

	x = 0;
	while (ptr[x] != '\0')
	{
		if (ptr[x] == a)
			return ((char *)ptr);
		ptr++;
	}
	if (ptr[x] == '\0')
		return ((char *)ptr);
	return (0);
}

char	*KalanSatır(char *k)
{
	int i;
	char *str;
	int j;

	while (k[i] != '\n' || k[i] != '\0')
	{
		i++;
	}
	if (!k)
		free(k);
		return (NULL);
	i++;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(k) - i));
	while (k)
	{
		str[j] = k[i + j];
		j++;
	}
	str[j] = '\0';
	free(k);
	return (str);

}

char	*AnaSatır(char *a)
{
	int c;
	int i;
	char *satır;

	i = 0;
	if (!a)
		return (NULL);
	while (a[i] != '\n' || a[i] != '\0')
		{
			c++;
		}
	satır = (char *)malloc(sizeof(char) * c + 2);
	i = 0;
	while (a[i] != '\n' || a[i] != '\0')
	{
		satır[i] = a[i];
		i++;
	}
	if (a[i] == '\n')
		satır[i] = a[i];
	i++;
	satır[i] = '\0';
	return (satır);

}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*ptr;
	char	*str;
	int error;

	buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0)
		return (NULL);
	error = 1;
	while (!ft_strchr(ptr, '\n') && (error !=  0))
	{
		error = read(fd, buffer, BUFF_SIZE);
		if (error < 0)
			free(buffer);
			return (NULL);
		buffer[error] = '\0';
		ptr = ft_strjoin(ptr, buffer);
	}	
	free(buffer);
	str = AnaSatır(ptr);
	ptr = KalanSatır(ptr);
	return (str);
}

int	main()
{
	int fd;
	int a;

	fd = open("text", O_RDONLY);

	while (a <= 10)
	{
		printf("%s", get_next_line(fd));
		a++;
	}
	return (0);
}





























