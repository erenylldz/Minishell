/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:04:45 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/02 17:17:19 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		str->ncmd = realloc(str->ncmd, (str->parts_counts + 1) * sizeof(char *));
		str->ncmd[str->parts_counts] = ft_strndup(str->start, str->temp + str->idx - str->start);
		str->parts_counts++;
		str->start = str->temp + str->idx + 1;
	}
}

void	pipe_check(t_cmd	*str)
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
		str->ncmd = realloc(str->ncmd, (str->parts_counts + 1) * sizeof(char *));
		str->ncmd[str->parts_counts] = ft_strndup(str->start, str->temp + str->len - str->start);
		str->parts_counts++;
	}
	// BU FOR SİLİNECEK!!!!!!!!!!!
	for (size_t i = 0; i < str->parts_counts; i++) {
        printf("%s\n", str->ncmd[i]);
        free(str->ncmd[i]);
    }
}
