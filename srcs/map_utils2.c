/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:15:59 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 17:41:28 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_free(t_map *map)
{
	if (map->dp)
		free(map->dp);
	if (map->grid)
		free(map->grid);
	free(map);
}
