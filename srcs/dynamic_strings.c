/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:13:11 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 18:54:50 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_dstring	*dstring_create(void)
{
	t_dstring	*dstr;

	dstr = malloc(sizeof(t_dstring));
	if (!dstr)
		return (NULL);
	dstr->size = DSTRING_BASE_SIZE;
	dstr->len = 0;
	dstr->str = ft_calloc(dstr->size);
	if (!dstr->str)
	{
		free(dstr);
		return (NULL);
	}
	return (dstr);
}

char	*dstring_free(t_dstring *dstr)
{
	if (!dstr)
		return (NULL);
	if (dstr->str)
		free(dstr->str);
	free(dstr);
	return (NULL);
}

int	dstring_grow(t_dstring *dstr)
{
	size_t	new_size;
	char	*new_buf;

	new_size = dstr->size * DSTRING_GROW_MULT;
	new_buf = malloc(new_size);
	if (!new_buf)
		return (0);
	ft_strlcpy(new_buf, dstr->str, dstr->len + 1);
	ft_bzero(new_buf + dstr->len, new_size - dstr->len);
	free(dstr->str);
	dstr->str = new_buf;
	dstr->size = new_size;
	return (1);
}

int	dstring_append(t_dstring *dstr, char *append_str, size_t append_len)
{
	if (append_len == 0)
		return (1);
	if ((dstr->len + append_len) >= dstr->size)
	{
		if (!dstring_grow(dstr))
			return (0);
	}
	ft_memcpy(dstr->str + dstr->len, append_str, append_len);
	dstr->len += append_len;
	return (1);
}
