#include "get_next_line.h"

int	send_new_line(char **line, int fd, t_filehold *file, int pos)
{
	char	*temp;
	int		strlen;

	temp = (char *)malloc(sizeof(char) * pos + 1);
	if (!temp)
	{
		free(file->all_fd[fd]);
		return (-1);
	}
	ft_strlcpy(temp, file->all_fd[fd], pos + 1);
	*line = temp;
	strlen = ft_strlen(file->all_fd[fd]);
	ft_strlcpy(file->all_fd[fd], &file->all_fd[fd][pos + 1], strlen - pos + 1);
	return (1);
}

int	send_EOF(char **line, int fd, t_filehold *file, int pos)
{
	char	*temp;
	int		strlen;

	temp = (char *)malloc(sizeof(char) * pos + 1);
	if (!temp)
	{
		free(file->all_fd[fd]);
		return (-1);
	}
	ft_strlcpy(temp, file->all_fd[fd], pos + 1);
	*line = temp;
	strlen = ft_strlen(file->all_fd[fd]);
	ft_strlcpy(file->all_fd[fd], &file->all_fd[fd][pos + 1], strlen - pos + 1);
	return (0);
}

int	file_stuff(char **line, t_filehold *file, int fd)
{
	int		pos;

	pos = 0;
	while (file->all_fd[fd][pos] != '\n' && file->all_fd[fd][pos] != '\0')
		pos++;
	if (file->all_fd[fd][pos] == '\n')
		return (send_new_line(line, fd, file, pos));
	else if (file->all_fd[fd][pos] == '\0')
		return (send_EOF(line, fd, file, pos));
	return (0);
}

int	process_next_line(int fd, t_filehold *files, int readbytes)
{
	char	*temp;

	files->buf[readbytes] = '\0';
	temp = ft_strjoin(files->all_fd[fd], files->buf);
	if (!temp)
	{
		free(files->all_fd[fd]);
		return (0);
	}
	free(files->all_fd[fd]);
	files->all_fd[fd] = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_filehold	files;
	int					readbytes;

	if (fd == -1 || !line || BUFFER_SIZE < 1 || fd > FD_TOTAL)
		return (-1);
	if (!files.all_fd[fd])
		files.all_fd[fd] = ft_strdup("\0");
	if (!files.all_fd[fd])
		return (-1);
	readbytes = 1;
	files.buf[0] = '\0';
	while (readbytes > 0)
	{
		if (!process_next_line(fd, &files, readbytes))
			return (-1);
		if (ft_strchr(files.all_fd[fd], '\n'))
			break ;
		readbytes = read(fd, files.buf, BUFFER_SIZE);
	}
	if (readbytes == -1)
	{
		free(files.all_fd[fd]);
		return (-1);
	}
	return (file_stuff(line, &files, fd));
}
