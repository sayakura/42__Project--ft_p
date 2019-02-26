/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:07:09 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 22:15:16 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list **alst)
{
	t_list	*head;
	size_t	len;

	len = 0;
	if (!*alst || !alst)
		return (0);
	head = *alst;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
