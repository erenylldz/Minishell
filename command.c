/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/21 19:31:26 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_count(t_cmd	*str)
{
	int	i;

	i = 0;
	
	str->dquote_count = 0;
	str->squote_count = 0;
	while (str->cmd[i] != '\0')
	{
		if (str->cmd[i] == '"'
			|| (str->cmd[i] == '"' || str->cmd[i + 1] == '\''))
			str->dquote_count++;
		else if (str->cmd[i] == '\''
			|| (str->cmd[i] == '\'' || str->cmd[i + 1] == '"'))
			str->squote_count++;
		i++;
	}
	if(str->dquote_count % 2 != 0 || str->squote_count % 2 != 0)
		printf("error");
}
//Deneme