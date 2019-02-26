/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 22:42:51 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/18 00:07:20 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;
	size_t				index;

	str = s;
	index = 0;
	ch = (unsigned char)c;
	while (n--)
	{
		if (str[index] == ch)
			return ((void *)(str + index));
		index++;
	}
	return (NULL);
}
