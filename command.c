/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/02 17:16:55 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_check(t_cmd *str)
{
	pipe_check(str);
	quote_count(str);
}
int	is_line_empty(t_cmd *str)
{
	str->i = 0;
	while (str->cmd[str->i])
	{
		if (str->cmd[str->i] != ' ' || str->cmd[str->i] != '\t')
			return (FALSE);
		str->i++;
	}
	return (TRUE);
}
void	quote_count(t_cmd	*str)
{
	str->i = 0;
	str->dquote = false;
	str->squote = false;
	str->dquote_count = 0;
	str->squote_count = 0;
	while (str->cmd[str->i] != '\0')
	{
		if (str->cmd[str->i] == '\"' && str->squote != true)
		{
			str->dquote = true;
			str->dquote_count++;
			if (str->dquote_count % 2 == 0)
				str->dquote = false;
		}
		else if (str->cmd[str->i] == '\'' && str->dquote != true)
		{
			str->squote = true;
			str->squote_count++;
			if (str->squote_count % 2 == 0)
				str->squote = false;
		}
		str->i++;
	}
	if(str->dquote_count % 2 != 0 || str->squote_count % 2 != 0)
		printf("error\n");
}
