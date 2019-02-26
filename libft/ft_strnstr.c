/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:45:14 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 23:07:10 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	comptr(const char *s1, const char *s2, int len)
{
	size_t	index;

	index = 0;
	while (s2[index] && len-- != -1)
	{
		if ((s1[index] == s2[index]))
			index++;
		else
			return (index);
	}
	if (s2[index] != '\0')
		return (1);
	return (0);
}

char			*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	index;

	index = 0;
	if (!*nd)
		return ((char *)hs);
	while (hs[index] && len--)
	{
		if (hs[index] == nd[0])
		{
			if (comptr(hs + index, nd, (int)len) == 0)
				return (char *)(hs + index);
		}
		index++;
	}
	return (NULL);
}
