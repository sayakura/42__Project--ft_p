/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:47:56 by qpeng             #+#    #+#             */
/*   Updated: 2018/11/16 11:11:19 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int		index;
	char	ch;

	ch = c;
	index = 0;
	while (str[index])
		index++;
	while (index >= 0)
	{
		if (str[index] == ch)
			return ((char *)str + index);
		index--;
	}
	return (NULL);
}
