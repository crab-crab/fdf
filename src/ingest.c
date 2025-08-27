#include "fdf.h"

char	*ft_strlchr(char *s, int c, size_t l)
{
	if (!s)
		return (NULL);
	while (*s && l > 0)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
		l--;
	}
	return (NULL);
}

int	fill_buffer(char **buffer, int fd)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*swap;

	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (-1);
	while (!ft_strlchr(*buffer, '\0', __SIZE_MAX__))
	{
		ft_memset(temp, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (*buffer)
				free(*buffer);
			free(temp);
			return (*buffer = NULL, -1);
		}
		if (bytes_read == 0)
			break ;
		swap = ft_strjoin(*buffer, temp);
		*buffer = swap;
	}
	free(temp);
	return (1);
}

uint32_t parse_map(char *filename, char ***map)
{
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;
	char	*text;

	fd = open(filename, O_RDONLY);
	if (fill_buffer(&buffer, fd) < 0)
		return (-1);
	*map = ft_split(buffer, '\n');
	if (!*map)
		return (-1);

	return (1);
}