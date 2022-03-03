#include "get_next_line.h"
#include <stdio.h>









int check	(char *ptr, char car)
{
	if (!ptr)
		return 0;
	while (*ptr != '\0')
	{
		if (*ptr == car)
			return 1;
		ptr++;
	}

	return 0;
}













size_t	stringsay(char *s1)
{
	size_t counter;

	counter = 0;
	if (!s1)
		return 0;
	while (*s1 != '\0')
		{
			counter++;
			s1++;
		}
	return counter;
}









char *birlestir(char *s1, char *s2)
{
	char *ptr;
	char *str;

	ptr = (char *)malloc((stringsay(s1) + stringsay(s2)) * sizeof(char) + 1);
	if (!ptr)
		return NULL;
	str = ptr;
	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr = *s1;
			s1++;
			ptr++;
		}
	}
	if (s2 != NULL)
	{
		while (*s2 != 0)
		{
			*ptr = *s2;
			s2++;
			ptr++;
		}
	}
	*ptr = '\0';
	//free (s1);
	return str ;
}

char	*Sifirla(char *buff)
{
	while(*buff)
	{
		*buff = 0;
		buff++;
	}
return (buff);
}


char *nlöncesi(char *ptr)
{
	int i;
	char *str;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i] != '\n' && ptr[i])
		i++;
	str = malloc(i + 1);
	i = 0;
	while (ptr[i] != '\n' && ptr[i])
	{
		str[i] = ptr[i];
		i++;
	}	
	if (ptr[i] == '\n')
	{
		str[i] = ptr[i];
		i++;
	}
	return(str);
}

char *nlsonrası(char *ptr)
{
	int i;
	int j;
	char *str;

	i = 0;
	if (!ptr)
		return(NULL);
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	str = malloc(stringsay(ptr) - i);
	j = 0;
	i++;
	while (ptr[i])
		str[j++] = ptr[i++];
	str[j] = '\0';
	free(ptr);
	return (str);
}


/*
char **temizle(char *ptr)
{
	char *str;
	char *strreturn;
	char **strstr;
	size_t	counter;

	counter = 0;
	strstr = (char **)malloc(2 * sizeof(char *));
	if (!strstr)
		return NULL;
	if (!check(ptr, '\n'))
	{
		
		strstr[0] = ptr;
		strstr[1] = NULL;
		//free (ptr);
		return strstr;
	}
	while (ptr[counter] != '\n')
		counter++;
	str = (char *)malloc(counter * sizeof(char) + 1);
	if (!str)
		return NULL;
	strreturn = str;
	while (*ptr != '\n' && *ptr != 0)
	{
		*str = *ptr;
		ptr++;
		str++;
	}
	*str = '\0';
	strstr[0] = strreturn;
	if (stringsay(ptr) > 1)
		strstr[1] = ptr + 1;
	else 
		strstr[1] = NULL;
	//free(ptr);
	return strstr;
}

*/


char	*get_next_line(int fd)
{
	static char	 *ptr;
	int error;
	
	char *buffer;
	char *str;
//	char **strstr;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	error = 1;
	buffer = (char *)calloc(1, (BUFF_SIZE + 1 * sizeof(char)));
	if (!buffer)
		return NULL;
	while (!(check(ptr, '\n') && (error != 0)))
	{
		Sifirla(buffer);
		error = read(fd, buffer, 3);//read arka planda size kadar alan olusturur, olusturulan alanın ilk adresini pointera atiyor(!ayni alanı kullanıyor surekli)
		if (error < 1)
		{
			break ;
		}
		//buffer[error] = '\0';
		ptr = birlestir(ptr, buffer);
	} 
	str = nlöncesi(ptr);
	ptr = nlsonrası(ptr);
	free(buffer);
	return (str);
}


int main()
{
	int	fd;

	fd = open("text", O_RDONLY);
	//read(fd, ptr, 3);
	int i = 0;

	while (i++ < 2)
		printf("%s", get_next_line(fd));
}