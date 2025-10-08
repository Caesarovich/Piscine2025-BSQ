/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaurent <alaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:52:25 by alaurent          #+#    #+#             */
/*   Updated: 2025/10/08 17:51:05 by alaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	update_max_square(t_square *square, size_t x, size_t y, size_t size)
{
	if (size <= square->size)
		return ;
	square->size = size;
	square->x = x - size;
	square->y = y - size;
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
					map->dp[y][x] = ft_min(ft_min(map->dp[y - 1][x], map->dp[y][x - 1]),
						map->dp[y - 1][x - 1]) + 1;
				update_max_square(&square, x,  y, map->dp[y][x]);
			}
			x++;
		}
		y++;
	}
}


void	init_solver(t_map *map)
{
	t_square max_sq;
	
	max_sq.size = 0;
	max_sq.x = 0;
	max_sq.y = 0;
	solver(map, &max_sq);
	if (max_sq.size > 0)
	
}
// def maximalSquare(matrix):
//     if not matrix:
//         return 0

//     rows, cols = len(matrix), len(matrix[0])
//     dp = [[0] * cols for _ in range(rows)]
//     max_side = 0
//     for i in range(rows):
//         for j in range(cols):
//             if matrix[i][j] == '1':
//                 if i == 0 or j == 0:
//                     dp[i][j] = 1
//                 else:
//                     dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
//                 max_side = max(max_side, dp[i][j])
//     return max_side * max_side