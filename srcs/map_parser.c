/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:19:03 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/07 11:44:00 by ansaccar         ###   ########.fr       */
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
	if (!ft_char_is_printable(map->fill) || map->fill == map->empty || map->fill == map->obsticle)
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
	// if (file_content[offset + (j * map->width)] != '\0')
	// 	return (0);
	return (1);
}

t_map	*parse_file(char *path)
{
	t_map			*map;
	char			*file_content;
	unsigned int	width;
	unsigned int	height;
	int				i;

	file_content = read_whole_file(path);
	if (!file_content)
		return (NULL);
	height = ft_atoi(file_content);
	i = 0;
	while (file_content[i] && file_content[i] != '\n')
		i++;
	i++;
	width = 0;
	while (file_content[i + width] && file_content[i + width] != '\n')
		width++;
	map = create_map(width, height);
	if (!map)
	{
		free(file_content);
		return (NULL);
	}
	if (!parse_header(file_content, map))
	{
		printf("CANT PARSE HEADER");
		free(file_content);
		free(map);
		return (NULL);
	}
	if (!parse_grid(file_content, map))
	{
		printf("CANT PARSE GRID");
		free(file_content);
		free(map);
		return (NULL);
	}
	return (map);
}
