/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 02:04:17 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 23:32:06 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_abs(int n)
{
	if (n < 0)
		return (size_t)(~(n) + 1);
	else
		return (size_t)(n);
}

char			*ft_itoa(int n)
{
	size_t	size;
	char	*ptr;
	int		temp;
	char	neg;

	temp = n;
	neg = (n < 0) ? 1 : 0;
	size = (n < 0) ? 2 : 1;
	while ((temp /= 10) != 0)
		size++;
	if (!(ptr = ft_strnew(size)))
		return (NULL);
	ptr[--size] = ft_abs(n % 10) + '0';
	while ((n /= 10) != 0)
		ptr[--size] = ft_abs(n % 10) + '0';
	if (neg == 1)
		ptr[--size] = '-';
	return (ptr);
}
