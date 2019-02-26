/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:05:19 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 23:12:47 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	comptr(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s2[index])
	{
		if ((s1[index] == s2[index]))
			index++;
		else
			return (index);
	}
	return (0);
}

char					*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;

	index = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[index])
	{
		if (haystack[index] == needle[0])
		{
			if (comptr(haystack + index, needle) == 0)
				return (char *)(haystack + index);
		}
		index++;
	}
	return (NULL);
}
