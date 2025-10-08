/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:19:03 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 16:18:53 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

//TODO: Reverse order
int	parse_header(char *file_content, t_map *map)
{
	size_t	i;

	if (ft_atoi(file_content) == 0)
		return (0);
	i = 0;
	while (ft_char_is_num(file_content[i]))
		i++;
	map->empty = file_content[i++];
	if (!ft_char_is_printable(map->empty))
		return (0);
	map->obsticle = file_content[i++];
	if (!ft_char_is_printable(map->obsticle) || map->obsticle == map->empty)
		return (0);
	map->fill = file_content[i++];
	if (!ft_char_is_printable(map->fill)
		|| map->fill == map->empty || map->fill == map->obsticle)
		return (0);
	if (file_content[i] != '\n')
		return (0);
	return (1);
}

int	parse_line(t_map *map, char *line, size_t line_n)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < map->width)
	{
		c = line[i];
		if (c != map->empty && c != map->fill && c != map->obsticle)
			return (0);
		map->grid[line_n][i] = c;
		map->dp[line_n][i] = 0;
		i++;
	}
	if (line[i] != '\n')
		return (0);
	return (1);
}

int	parse_grid(char *file_content, t_map *map)
{
	size_t	offset;
	size_t	j;

	offset = 0;
	while (file_content[offset] != '\n')
		offset++;
	offset++;
	j = 0;
	while (j < map->heigth)
	{
		if (!parse_line(map, file_content + offset + (j * (map->width + 1)), j))
			return (0);
		j++;
	}
	if (file_content[offset + (j * map->width)] != '\0')
		return (0);
	return (1);
}

int	get_initial_dimensions(char *file_content, size_t *width, size_t *height)
{
	char	first_line[32];
	int		w;
	int		h;
	size_t	i;

	ft_strlcpy(first_line, file_content, 32);
	i = 0;
	while (first_line[i] && first_line[i] != '\n')
		i++;
	w = i + 1;
	if (i < 3)
		return (0);
	i -= 3;
	first_line[i] = '\0';
	h = ft_atoi(first_line);
	if (h < 1)
		return (0);
	*height = h;
	i = 0;
	while (file_content[i + w] && file_content[i + w] != '\n')
		i++;
	if (i < 1)
		return (0);
	*width = i;
	return (1);
}

t_map	*parse_file(char *path)
{
	t_map	*map;
	char	*file_content;
	size_t	width;
	size_t	height;

	file_content = read_whole_file(path);
	if (!file_content)
		return (NULL);
	if (!get_initial_dimensions(file_content, &width, &height))
	{
		free(file_content);
		return (NULL);
	}
	map = create_map(width, height);
	if (!map || !parse_header(file_content, map)
		|| !parse_grid(file_content, map))
	{
		if (map)
			free(map);
		map = NULL;
	}
	free(file_content);
	return (map);
}
