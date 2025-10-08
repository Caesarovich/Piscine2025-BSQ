/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:52:58 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/08 19:34:01 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define READ_BUFFER_SIZE 2048
# define DSTRING_BASE_SIZE 2048
# define DSTRING_GROW_MULT 2

typedef struct s_map
{
	char			empty;
	char			obsticle;
	char			fill;
	size_t			width;
	size_t			heigth;
	char			**grid;
	unsigned int	**dp;
}	t_map;

typedef struct s_square
{
	size_t	x;
	size_t	y;
	size_t	size;
}	t_square;

t_map			*create_map(unsigned int w, unsigned int h);
void			map_print(t_map *map);
t_map			*parse_file(char *path);
void			map_free(t_map *map);

typedef struct s_file_queue
{
	size_t	len;
	char	**files;
}	t_file_queue;

typedef struct s_dstring
{
	size_t	size;
	size_t	len;
	char	*str;
}	t_dstring;

t_dstring		*dstring_create(void);
char			*dstring_free(t_dstring *dstr);
int				dstring_append(t_dstring *dstr,
					char *append_str, size_t append_len);

void			ft_putchar(char c);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int nbr);
int				ft_strcmp(char *s1, char *s2);
int				ft_char_is_num(char c);
int				ft_char_is_ws(char c);
int				ft_char_is_printable(char c);
int				ft_atoi(char *str);
int				ft_min(unsigned int a, unsigned int b);
int				ft_max(unsigned int a, unsigned int b);
char			*read_whole_file(char *path);
void			ft_memcpy(void *dest, void *src, size_t size);
void			ft_bzero(void *dest, size_t size);
void			*ft_calloc(size_t size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			init_solver(t_map *map);

#endif