/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 01:06:36 by qpeng             #+#    #+#             */
/*   Updated: 2018/11/16 11:16:11 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		index;
	char	c;

	c = ch;
	index = 0;
	while (str[index] != '\0' && str[index] != ch)
		index++;
	return (str[index] == ch) ? (char *)(str + index) : (NULL);
}
