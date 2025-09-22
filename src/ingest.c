/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:52 by crabin            #+#    #+#             */
/*   Updated: 2025/09/22 18:28:23 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		ft_memset(temp, 0, BUFFER_SIZE + 1);
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

void fill_node(t_map *map, t_node *node, int32_t x, int32_t y)
{
	node->x_orig = x;
	node->y_orig = y;
	node->aa = 255;
	if (node->z_orig > map->max_z)
		map->max_z = node->z_orig;
	if (node->z_orig < map->min_z)
		map->min_z = node->z_orig;
}

int fill_map(t_map *map, char	**text)
{
	int32_t		i_y;
	int32_t		i_x;
	t_node		*node;
	char		**line;

	i_y = -1;
	while (++i_y < map->size_y)
	{
		i_x = -1;
		line = ft_split(text[i_y], ' '); // check for split malloc fail return -> confirm it even will return a NULL properly
		while (++i_x < map->size_x)
		{
			node = &map->nodes[i_y * map->size_x + i_x];
			fill_node(map, node, i_x, i_y);
			node->z_orig = ft_atoi(line[i_x]);
			node->colour = ft_hextoi(line[i_x]);
			set_rgb(ft_hextoi(line[i_x]), node);
			node->colour = blend_rgb(node->rr, node->gg, node->bb, node->aa);
			free(line[i_x]); // check usage
			// i_x++; //incorporate into while statement increment?
		}
		free(line);
		// i_y++;
	}
	return (1);
}

int32_t parse_map(char *filename, t_map *map)
{
	uint32_t	fd;
	char		*buffer;
	char		**text;

	buffer = NULL;
	fd = open(ft_strjoin(PATH_MAP, filename), O_RDONLY);
	if (fd < 0)
		return (write(2, "File open error\n", 16));
	if (fill_buffer(&buffer, fd) < 0)
		return (-1);
	text = ft_split(buffer, '\n');
	free(buffer);
	if (!*text)
		return (-1);
	map->size_y = ft_size(text);
	map->size_x = count_cells(text[0], ' ');
	map->min_z = INT32_MAX;
	map->max_z = INT32_MIN;
	map->nodes = (t_node*)ft_calloc(map->size_x * map->size_y, sizeof(t_node));
	fill_map(map, text);
	return (1);
}


