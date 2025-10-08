/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:53:32 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 16:59:11 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map_error()
{
	ft_putstr("map error\n");
}

int	main(void)
{
	t_map	*map;
	
	map = parse_file("map.txt");
	if (!map)
	{
		print_map_error();
		return 1;
	}
	solver(map);
	map_print(map);
}
