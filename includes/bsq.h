/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:52:58 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/06 20:04:48 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	char			empty;
	char			obsticle;
	char			fill;
	int				columns_count;
	int				lines_count;
	char			**grid;
	unsigned int	**dp;
}	t_map;

#endif