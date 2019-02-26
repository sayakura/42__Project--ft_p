/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:03:05 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 04:23:06 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*ptr;

	index = 0;
	if (!s)
		return (NULL);
	if (!(ptr = ft_strnew(len)))
		return (ptr);
	s = s + start;
	while (index < len)
	{
		ptr[index] = s[index];
		index++;
	}
	return (ptr);
}
