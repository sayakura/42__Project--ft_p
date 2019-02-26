/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:05:55 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 22:16:51 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char const *s, unsigned int start, unsigned int end)
{
	size_t		size;
	size_t		index;
	char		*ptr;

	index = 0;
	size = (end - start + 1);
	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (index < size)
	{
		ptr[index] = s[start + index];
		index++;
	}
	ptr[index] = 0;
	return (ptr);
}
