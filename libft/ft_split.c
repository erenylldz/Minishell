/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:45 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/07 16:15:39 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	str_i;
	size_t	start;
	size_t	end;
	char	**str;

	start = 0;
	str_i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	if (!str)
		return (NULL);
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (str_i == ft_count(s, c))
			break ;
		str[str_i++] = ft_substr(s, start, end - start);
		start = end;
	}
	str[str_i] = 0;
	return (str);
}
