/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/21 14:55:39 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dquote(t_cmd	*str)
{
	int		i;

	i = 0;
	str->dquote_count = 0;
	while (str->cmd[i++] != '\0')
		if (str->cmd[i] == '\"')
			str->dquote_count++;
	return (str->dquote_count);
}

int	squote(t_cmd	*str)
{
	int		i;

	i = 0;
	str->squote_count = 0;
	while (str->cmd[i++] != '\0')
		if (str->cmd[i] == '\'')
			str->squote_count++;
	return (str->squote_count);
}

void	quote_check(t_cmd	*str)
{
	int	i;

	i = 0;
	while (str->cmd[i] != '\0')
	{
		if (str->cmd[i] == '\"'
			|| (str->cmd[i] == '\"' && str->cmd[i + 1] == '\''))
			dquote(str);
		else if (str->cmd[i] == '\''
			|| (str->cmd[i] == '\'' && str->cmd[i + 1] == '\"'))
			squote(str);
		i++;
	}
	printf("%s\n", str->cmd);
	printf("%d\n\n", str->dquote_count);
}
