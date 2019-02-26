/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 22:46:45 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/18 00:06:07 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;
	const char	*s;
	const char	*d;

	s = s1;
	d = s2;
	index = 0;
	if (n == 0)
		return (0);
	while (s[index] == d[index] && --n)
		index++;
	return ((unsigned char)(s[index]) - (unsigned char)(d[index]));
}
