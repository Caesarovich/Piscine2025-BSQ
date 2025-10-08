/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:53:32 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 17:20:38 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map_error(void)
{
	char	*err;

	err = "map error\n";
	write(STDERR_FILENO, err, ft_strlen(err));
}

void	ft_handle_file(char *path)
{
	t_map	*map;

	map = parse_file(path);
	if (!map)
	{
		print_map_error();
		return ;
	}
	solver(map);
	map_print(map);
	map_free(map);
}

int	main(int argc, char **argv)
{
	t_file_queue	queue;
	size_t			i;

	queue.len = argc - 1;
	queue.files = argv + 1;
	if (argc == 1)
	{
		queue.len = 1;
		queue.files[0] = NULL;
	}
	i = 0;
	while (i < queue.len)
	{
		ft_handle_file(queue.files[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
