/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:46:20 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 16:06:33 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*head;

	if (alst && *alst)
	{
		head = *alst;
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
	else
		*alst = new;
}
