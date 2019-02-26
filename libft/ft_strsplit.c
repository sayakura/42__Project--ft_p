/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:21:45 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 23:06:34 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	next_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static inline size_t	world_count(const char *str, char c)
{
	size_t	wc;
	size_t	index;

	index = 0;
	wc = 0;
	while (str && str[index] != '\0')
	{
		while (str[index] && str[index] == c)
			index++;
		if (str[index] && str[index] != c)
		{
			wc++;
			while (str[index] && str[index] != c)
				index++;
		}
	}
	return (wc);
}

char					**ft_strsplit(char const *s, char c)
{
	size_t	wc;
	char	**ptr;
	size_t	index;
	size_t	len;

	index = 0;
	wc = world_count(s, c);
	if (!(ptr = malloc(sizeof(char *) * wc + 1)))
		return (0);
	wc = 0;
	while (s && s[index] != '\0')
	{
		while (s[index] && s[index] == c)
			index++;
		len = next_word_len(s + index, c);
		if (len == 0)
			break ;
		ptr[wc] = malloc(sizeof(char) * len + 1);
		ptr[wc][len] = '\0';
		ft_strncpy(ptr[wc], s + index, len);
		index += len;
		wc++;
	}
	ptr[wc] = NULL;
	return (ptr);
}
