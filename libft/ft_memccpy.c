/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:32:44 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/15 17:06:09 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, \
		int c, size_t n)
{
	size_t				index;
	unsigned const char	*s;
	unsigned char		*d;
	unsigned char		ch;

	index = 0;
	ch = c;
	s = src;
	d = dst;
	while (index < n)
	{
		d[index] = s[index];
		if (d[index] == ch)
			return (d + index + 1);
		index++;
	}
	return (NULL);
}
