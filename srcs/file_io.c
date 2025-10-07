/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:10:51 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/07 11:25:48 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_open_file(char *path)
{
	if (ft_strcmp(path, "-") == 0)
		return (0);
	return (open(path, O_RDONLY));
}

char	*read_whole_file(char *path)
{
	ssize_t	read_size;
	char	*file_content;
	int		fd;

	file_content = malloc(READ_BUFFER_SIZE);
	fd = ft_open_file(path);
	read_size = read(fd, file_content, READ_BUFFER_SIZE);
	return (file_content);
}
