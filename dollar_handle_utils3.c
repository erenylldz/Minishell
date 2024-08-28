/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handle_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:45:22 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/28 18:45:50 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quotes(char *str)
{
	int quote_count;
	int i;

	i = 0;
	quote_count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			quote_count++;
		i++;
	}
	return (quote_count);
}
int	dollar_between_quotes(char *s)
{
	int		i;
	bool	quote;

	quote = false;
	i = 0;
	while(s[i])
	{
		if (s[i] == '\"')
			quote = !quote;
		else if (s[i] == '\'' && !quote)
			return (1);
		i++;
	}
	return (0);
}
int	array_in_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}
