/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:46:53 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/16 20:12:22 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	index;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (index < len)
	{
		ptr[index] = (*f)(s[index]);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
