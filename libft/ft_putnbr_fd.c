/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 04:12:25 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 04:14:23 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		temp;
	int		n_size;

	n_size = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		else
			n = ~(n) + 1;
	}
	temp = n;
	while ((temp /= 10))
		n_size = (n_size << 4) - (n_size << 2) - (n_size << 1);
	while (n_size > 0)
	{
		ft_putchar_fd(n / n_size + '0', fd);
		n %= n_size;
		n_size /= 10;
	}
}
