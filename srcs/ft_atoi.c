/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansaccar <ansaccar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:36:34 by ansaccar          #+#    #+#             */
/*   Updated: 2025/10/07 09:09:35 by ansaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_char_is_ws(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str && ft_char_is_ws(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
		sign *= -1 + (2 * (*str++ != '-'));
	while (*str && ft_char_is_num(*str))
		num = num * 10 + (*str++ - '0');
	return (num * sign);
}
