/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:52:25 by alaurent          #+#    #+#             */
/*   Updated: 2025/10/08 19:45:48 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	update_max_square(t_square *square, size_t x, size_t y, size_t size)
{
	if (size <= square->size)
		return ;
	square->size = size;
	square->x = x - (size - 1);
	square->y = y - (size - 1);
}

void	solver(t_map *map, t_square *square)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] != map->obsticle)
			{
				if (x == 0 || y == 0)
					map->dp[y][x] = 1;
				else
					map->dp[y][x] = ft_min(ft_min(map->dp[y - 1][x],
								map->dp[y][x - 1]), map->dp[y - 1][x - 1]) + 1;
				update_max_square(square, x, y, map->dp[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	fill_square(t_map *map, t_square *square)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < square->size)
	{
		x = 0;
		while (x < square->size)
		{
			map->grid[y + square->y][x + square->x] = map->fill;
			x++;
		}
		y++;
	}
}

void	print_solved(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->heigth)
	{
		write(STDOUT_FILENO, map->grid[i], map->width);
		ft_putchar('\n');
		i++;
	}
}

void	init_solver(t_map *map)
{
	t_square	max_sq;

	max_sq.size = 0;
	max_sq.x = 0;
	max_sq.y = 0;
	solver(map, &max_sq);
	if (max_sq.size > 0)
	{
		fill_square(map, &max_sq);
	}
	print_solved(map);
}
