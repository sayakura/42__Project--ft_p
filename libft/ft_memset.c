/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:32:04 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/12 03:08:26 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int		index;
	char	*str;

	str = (char *)(ptr);
	index = 0;
	while (num--)
	{
		str[index] = (unsigned char)(value);
		index++;
	}
	return (str);
}
