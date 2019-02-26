/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:46:29 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 22:52:57 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	current = *alst;
	if (!current || !alst)
		return ;
	while (current)
	{
		(*del)(current->content, current->content_size);
		next = current->next;
		free(current);
		current = next;
	}
	*alst = NULL;
}
