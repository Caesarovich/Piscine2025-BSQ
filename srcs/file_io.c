/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:10:51 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 18:48:40 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_open_file(char *path)
{
	if (path == NULL)
		return (0);
	return (open(path, O_RDONLY));
}

char	*read_whole_file_panic(int fd, t_dstring *dstr)
{
	if (fd > 0)
		close(fd);
	dstring_free(dstr);
	return (NULL);
}

char	*read_whole_file(char *path)
{
	t_dstring	*dstr;
	ssize_t		read_size;
	char		read_buffer[READ_BUFFER_SIZE];
	int			fd;
	char		*file_content;

	dstr = dstring_create();
	if (!dstr)
		return (NULL);
	fd = ft_open_file(path);
	if (fd == -1)
		return (dstring_free(dstr));
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, read_buffer, READ_BUFFER_SIZE);
		if (!dstring_append(dstr, read_buffer, read_size))
			return (read_whole_file_panic(fd, dstr));
	}
	if (fd > 0)
		close(fd);
	file_content = dstr->str;
	free(dstr);
	return (file_content);
}
