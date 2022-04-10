#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define FD_TOTAL 2048

typedef struct s_filehold
{
	char	*all_fd[FD_TOTAL];
	char	buf[BUFFER_SIZE + 1];
}				t_filehold;

int		get_next_line(int fd, char **line);

#endif