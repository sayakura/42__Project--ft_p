/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:15:01 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/15 13:22:30 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	const char	*s;
	char		*d;

	s = (const char*)(src);
	d = (char*)(dst);
	index = 0;
	if (s < d)
		while ((int)--len >= 0)
			d[len] = s[len];
	else
		while (len--)
		{
			d[index] = s[index];
			index++;
		}
	return (d);
}
