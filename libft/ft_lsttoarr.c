/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:15:44 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 22:57:53 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttoarr(t_list **lst)
{
	char			**ptr;
	size_t			size;
	size_t			index;
	t_list			*temp;

	index = 0;
	size = ft_lstsize(lst);
	ptr = (char **)malloc(sizeof(char *) * size + 1);
	if (!ptr)
		return (NULL);
	temp = *lst;
	while (index < size)
	{
		if (!(ptr[index] = (char *)malloc(sizeof(char) *\
						(size_t)temp->content_size + 1)))
			ptr[index] = (NULL);
		ft_memcpy(ptr[index], (char *)temp->content,\
				(size_t)temp->content_size);
		temp = temp->next;
		index++;
	}
	ptr[index] = (NULL);
	return (ptr);
}
