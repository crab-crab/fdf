/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:52 by crabin            #+#    #+#             */
/*   Updated: 2025/09/15 18:06:57 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strlchr(char *s, int c, size_t l)
{
	if (!s)
		return (NULL);
	while (l > 0 && *s)
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

/*The atoi() function converts the initial portion of the string pointed to by
nptr to int. Returns the converted value or 0 on error.*/
int	ft_hextoi(const char *nptr)
{
	long	result;

	result = 0;
	if (!nptr)
		return (0);
	while (*nptr != 'x')
	{
		if (!*nptr) //redundant?
			return (0);
		nptr++;
	}
	nptr++;
	while (ft_isdigit(*nptr) || ft_isalpha(*nptr))
	{
		result *= 16;
		if (ft_isdigit(*nptr))
			result += *nptr - '0';
		else if (*nptr >= 'A' && *nptr <= 'F')
			result += (*nptr - 'A') + 11;
		else if (*nptr >= 'a' && *nptr <= 'f')
			result += (*nptr - 'a') + 11;
		nptr++;
	}
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}

int	fill_buffer(char **buffer, int fd)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*swap;

	temp = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (-1);
	while (!ft_strlchr(*buffer, '\0', __SIZE_MAX__))
	{
		ft_memset(temp, 0, BUFFER_SIZE + 1); // redundant due to calloc?
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0) // make a free function?
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

int32_t 	ft_size(char **arr)
{
	int32_t size;

	size = 0;
	if (!arr)
		return (-1);
	while (*arr)
	{
		size++;
		arr++;
	}
	return (size);
}

int32_t		count_cells(char *txt, char c)
{
	char	prev;
	int		i;

	i = 0;
	prev = c;
	while (*txt)
	{
		if (ft_isalnum(*txt) && prev == c)
		{
			i++;
		}
		prev = *txt;
		txt++;
	}
	return (i);
}

int32_t parse_map(char *filename, t_map *map)
{
	uint32_t	fd;
	char		*path;
	char		*buffer;
	//ssize_t		bytes_read;
	char		**text;
	char		**line;
	uint32_t	i;
	uint32_t	j;

	buffer = NULL;
	path = ft_strjoin(PATH_MAP, filename) // combine this line and the following?
	fd = open(path, O_RDONLY);
	return(printf("fd:%d, filename: %s", fd, path));
	if (fd < 0)
		return (free(path), write(1, "file open error\n", 16));
	if (fill_buffer(&buffer, fd) < 0)
		return (-1);
	text = ft_split(buffer, '\n');
	free(buffer);
	if (!*text)
		return (-1);
	
	map->size_y = ft_size(text);
	map->size_x = count_cells(*text, ' ');
	map->node_arr = ft_calloc(map->size_y, sizeof(t_node *));
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		map->node_arr[i] = ft_calloc(map->size_x, sizeof(t_node)); // guard with adding a NULL on the end of each row/column?
		line = ft_split(text[i], ' '); // check for split malloc fail return -> confirm it even will return a NULL properly
		while (j < map->size_x) // split into a fill_map helper -> consider storing x and y directly
		{
			map->node_arr[i][j].z = ft_atoi(line[j]);
			if (map->node_arr[i][j].z > map->max_z)
				map->max_z = map->node_arr[i][j].z;
			if (map->node_arr[i][j].z < map->min_z)
				map->min_z = map->node_arr[i][j].z;
			map->node_arr[i][j].colour = ft_hextoi(line[j]);
			free(line[j]);
			j++;
		}
		i++;
	}
	return (1);
}

int fill_map(t_map *map, char	**text)
{
	int	i;
	int j;
	char *line;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		map->node_arr[i] = ft_calloc(map->size_x, sizeof(t_node)); // guard with adding a NULL on the end of each row/column?
		line = ft_split(text[i], ' '); // check for split malloc fail return -> confirm it even will return a NULL properly
		if (!line || !map->node_arr[i])
			return (free(line), -1);
		while (j < map->size_x) // split into a fill_map helper -> consider storing x and y directly
		{
			map->node_arr[i][j].z = ft_atoi(line[j]);
			if (map->node_arr[i][j].z > map->max_z)
				map->max_z = map->node_arr[i][j].z;
			if (map->node_arr[i][j].z < map->min_z)
				map->min_z = map->node_arr[i][j].z;
			map->node_arr[i][j].colour = ft_hextoi(line[j]);
			free(line[j]);
			j++; //incorporate into while statement increment?
		}
		i++;
	}
	return (1);
}
