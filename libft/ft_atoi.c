/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:13:48 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 23:33:21 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_atoi_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline int	ft_atoi_isspace(char c)
{
	return (c == ' ' ||
			c == '\t' ||
			c == '\n' ||
			c == '\f' ||
			c == '\v' ||
			c == '\r' ||
			c == '\t');
}

int					ft_atoi(const char *str)
{
	unsigned long long	result;
	size_t				index;
	char				sign;

	index = 0;
	result = 0;
	sign = 1;
	while (ft_atoi_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = 0;
		index++;
	}
	while (ft_atoi_isdigit(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		if (result >= 9223372036854775807)
			return ((sign) ? (-1) : (0));
		index++;
	}
	return (int)((sign) ? (result) : (-result));
}
