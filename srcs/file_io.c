/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:10:51 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 17:38:42 by ansaccar         ###   ########.fr       */
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

	file_content = ft_calloc(READ_BUFFER_SIZE);
	if (path)
		fd = ft_open_file(path);
	else
		fd = 0;
	if (fd == -1)
	{
		free(file_content);
		return (NULL);
	}
	read_size = read(fd, file_content, READ_BUFFER_SIZE);
	return (file_content);
}
