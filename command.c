/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/17 14:33:24 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dquote(t_cmd	*str)
{
	int		i;

	i = 0;
	while (str->cmd[i++])
		if (str->cmd[i] == '"')
			str->dquote_count++;
	return (str->dquote_count);
}

int	squote(t_cmd	*str)
{
	int		i;

	i = 0;
	while (str->cmd[i++])
		if (str->cmd[i] == '\'')
			str->squote_count++;
	return (str->squote_count);
}
