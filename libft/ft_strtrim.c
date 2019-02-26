/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:26:25 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/17 23:33:04 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char				*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	if (!(*s))
		return ("");
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && (ft_isspace(s[len])))
		len--;
	if (len < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - i + 1));
}
