/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:48:40 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/12 04:34:37 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int num)
{
	unsigned int	index;

	index = 0;
	while (index < num)
	{
		if (src[index] != '\0')
			dest[index] = src[index];
		else
			while (index < num)
				dest[index++] = '\0';
		index++;
	}
	return (dest);
}
