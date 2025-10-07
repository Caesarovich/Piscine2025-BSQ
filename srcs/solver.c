/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaurent <alaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:52:25 by alaurent          #+#    #+#             */
/*   Updated: 2025/10/07 14:53:04 by alaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

void	solver(t_map *map)
{
	size_t	x;
	size_t	y;
	size_t		max_side;

	y = 0;
	max_side = 0;
	while (y < map->heigth - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] != map->obsticle)
			{
				if (x == 0 || y == 0)
					map->dp[y][x] = 1;
				map->dp[y][x] = ft_min(ft_min(map->dp[y - 1][x], map->dp[y][x - 1]),
					map->dp[y - 1][x - 1]) + 1;
				max_side = ft_max(max_side, map->dp[y][x]);
				x++;
			}
		}
		y++;
	}
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