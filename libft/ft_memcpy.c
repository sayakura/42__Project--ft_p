/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:16:36 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/15 17:04:11 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t				index;
	const unsigned char	*s;
	unsigned char		*d;

	d = dst;
	s = src;
	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (d);
}
