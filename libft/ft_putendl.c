/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 02:37:28 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 02:39:15 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t	index;

	index = ft_strlen(s) - 1;
	if (!(s[index] == '\n'))
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
	else
		ft_putstr(s);
}
