/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:04:45 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:29 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





// BU FONKSİYONLAR YEDEK OLARAK DURUYOR KULLANILMIYOR!!!!!!!!!!!


#include "minishell.h"

void	process_quotes(t_cmd *str)
{
	if (str->temp[str->idx] == '\'' && !str->double_quote)
		str->single_quote = !str->single_quote;
	else if (str->temp[str->idx] == '\"' && !str->single_quote)
		str->double_quote = !str->double_quote;
}

void	split_commands(t_cmd *str)
{
	if (str->temp[str->idx] == '|' && !str->double_quote && !str->single_quote)
	{
		str->ncmd = realloc(str->ncmd, (str->parts_counts + 1)
				* sizeof(char *));
		str->ncmd[str->parts_counts] = ft_strndup(str->start, str->temp
				+ str->idx - str->start);
		str->parts_counts++;
		str->start = str->temp + str->idx + 1;
	}
}

void	pipe_check(t_cmd *str)
{
	str->temp = str->cmd;
	str->len = ft_strlen(str->temp);
	str->double_quote = false;
	str->single_quote = false;
	str->ncmd = NULL;
	str->parts_counts = 0;
	str->idx = 0;
	str->start = str->temp;
	while (str->idx < str->len)
	{
		process_quotes(str);
		split_commands(str);
		str->idx++;
	}
	if (str->start <= str->temp + str->len)
	{
		str->ncmd = realloc(str->ncmd, (str->parts_counts + 1)
				* sizeof(char *));
		str->ncmd[str->parts_counts] = ft_strndup(str->start, str->temp
				+ str->len - str->start);
		str->parts_counts++;
	}
	str->ncmd[str->parts_counts] = NULL;
// 	// BU FOR SİLİNECEK!!!!!!!!!!!
	// for (size_t i = 0; i < str->parts_counts; i++)
	// 	printf("%s\n", str->ncmd[i]);
}


char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	len = ft_strnlen(s, n);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

size_t	ft_strnlen(const char *src, size_t i)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && idx < i)
	{
		idx++;
	}
	return (idx);
}