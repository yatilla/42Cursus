#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char    *NewTemizle(char *new);
char    *BufferSaydır(int fd);
//test
char	*ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *s);

#endif
