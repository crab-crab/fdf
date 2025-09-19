/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:52 by crabin            #+#    #+#             */
/*   Updated: 2025/09/18 20:38:04 by crabin           ###   ########.fr       */
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
uint32_t	ft_hextoi(const char *nptr) //move to lib_ft?
{
	uint64_t	result;

	result = 0;
	if (!nptr)
		return (0);
	while (*nptr != 'x' && *nptr)
		nptr++;
	if (!*nptr)
		return (0);
	nptr++;
	while (ft_isdigit(*nptr) || ft_isalpha(*nptr))
	{
		result *= 16;
		if (ft_isdigit(*nptr))
			result += *nptr - '0';
		else if (*nptr >= 'A' && *nptr <= 'F')
			result += (*nptr - 'A') + 10;
		else if (*nptr >= 'a' && *nptr <= 'f')
			result += (*nptr - 'a') + 10;
		nptr++;
	}
	if (result > UINT32_MAX)
		return (0);
	return ((uint32_t)result);
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
			return (*buffer = NULL, -1); // this function does not own buffer, should it be freeing?
		}
		if (bytes_read == 0)
			break ;
		swap = ft_strjoin(*buffer, temp);
		if (!swap)
			return (free(temp), -1);
		*buffer = swap;
	}
	return (free(temp), 1);
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

// t_node *get_node(int32_t x, int32_t y, t_map *map)
// {
// 	return (&map->nodes[y * map->size_x + x]);
// }

uint32_t get_index(int32_t x, int32_t y, t_map *map)
{
	return (y * map->size_x + x);
}

int fill_map(t_map *map, char	**text)
{
	uint32_t	i_y;
	uint32_t	i_x;
	uint32_t	index;
	char **line;

	i_y = 0;
	while (i_y < map->size_y)
	{
		i_x = 0;
		line = ft_split(text[i_y], ' '); // check for split malloc fail return -> confirm it even will return a NULL properly
		while (i_x < map->size_x)
		{
			index = i_y * map->size_x + i_x;
			map->nodes[index].x_orig = i_x;
			map->nodes[index].y_orig = i_y;
			map->nodes[index].z_orig = ft_atoi(line[i_x]);
			map->nodes[index].aa = 255;
			if (map->nodes[index].z_orig > map->max_z)
				map->max_z = map->nodes[index].z_orig;
			if (map->nodes[index].z_orig < map->min_z)
				map->min_z = map->nodes[index].z_orig;
			map->nodes[index].colour = ft_hextoi(line[i_x]);
			set_rgb(ft_hextoi(line[i_x]), &map->nodes[index]);
			map->nodes[index].colour = blend_rgb(map->nodes[index].rr, map->nodes[index].gg, map->nodes[index].bb, map->nodes[index].aa);

			
			//free(line[i_x]); // check usage
			i_x++; //incorporate into while statement increment?
		}
		free(line);
		i_y++;
	}
	return (1);
}

int32_t parse_map(char *filename, t_map *map)
{
	uint32_t	fd;
	char		*path;
	char		*buffer;
	//ssize_t		bytes_read;
	char		**text;

	buffer = NULL;
	path = ft_strjoin(PATH_MAP, filename); // combine this line and the following?
	fd = open(path, O_RDONLY);
	printf("fd:%d, filename: '%s'\n", fd, path); // testing
	if (fd < 0)
		return (free(path), write(1, "file open error\n", 16));
	if (fill_buffer(&buffer, fd) < 0)
		return (free(path), -1);
	text = ft_split(buffer, '\n');
	free(buffer);
	if (!*text)
		return (free(path), -1);
	map->size_y = ft_size(text);
	map->size_x = count_cells(*text, ' ');
	map->min_z = INT32_MAX;
	map->max_z = INT32_MIN;
	map->nodes = (t_node*)ft_calloc(map->size_x * map->size_y, sizeof(t_node));
	fill_map(map, text);
	return (1);
}


