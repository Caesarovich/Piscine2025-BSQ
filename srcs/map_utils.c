/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:15:59 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 17:37:31 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**create_grid(unsigned int w, unsigned int h)
{
	size_t	line_size;
	size_t	tab_size;
	size_t	i;
	char	**grid;

	line_size = sizeof(char) * (w + 1);
	tab_size = sizeof(char *) * (h + 1);
	grid = ft_calloc(tab_size + (line_size * h));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < h)
	{
		grid[i] = ((char *)grid + tab_size) + line_size * i;
		i++;
	}
	return (grid);
}

unsigned int	**create_dp(unsigned int w, unsigned int h)
{
	size_t			line_size;
	size_t			tab_size;
	size_t			i;
	unsigned int	**dp;

	line_size = sizeof(unsigned int) * (w + 1);
	tab_size = sizeof(unsigned int *) * (h + 1);
	dp = ft_calloc(tab_size + (line_size * h));
	if (!dp)
		return (NULL);
	i = 0;
	while (i < h)
	{
		dp[i] = ((unsigned int *)dp + tab_size) + line_size * i;
		i++;
	}
	return (dp);
}

t_map	*create_map(unsigned int w, unsigned int h)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = w;
	map->heigth = h;
	map->empty = 'E';
	map->fill = 'F';
	map->obsticle = 'O';
	map->grid = create_grid(w, h);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	map->dp = create_dp(w, h);
	if (!map->grid)
	{
		free(map->grid);
		free(map);
		return (NULL);
	}
	return (map);
}

void	print_int_tab(unsigned int **tab, size_t w, size_t h)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			ft_putnbr(tab[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	map_print(t_map *map)
{
	size_t	i;

	ft_putstr("---- MAP ----\n");
	ft_putstr("Size: ");
	ft_putnbr(map->width);
	ft_putstr(" x ");
	ft_putnbr(map->heigth);
	ft_putstr("\nEmpty char: ");
	ft_putchar(map->empty);
	ft_putstr("\nObsticle char: ");
	ft_putchar(map->obsticle);
	ft_putstr("\nFill char: ");
	ft_putchar(map->fill);
	ft_putstr("\n");
	ft_putstr(">>>>> CHARS\n");
	i = -1;
	while (++i < map->heigth)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
	}
	ft_putstr(">>>>> DYNAMIC\n");
	print_int_tab(map->dp, map->width, map->heigth);
	ft_putstr("\n-------------\n");
}
