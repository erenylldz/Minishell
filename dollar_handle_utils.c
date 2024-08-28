/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handle_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:39:43 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/28 18:44:46 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_dollar_in_quotes_idx(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '$')
	{
		i++;
	}
	if (str[i] == '$')
		return (i);
	return (-1);
}
char	*dollar_not_dquote(char *str)
{
	char	*dollar_str;

	dollar_str = find_dollar_in_quotes(str);
	if (!dollar_str)
		return (NULL);
	return (copy_acceptable_chars(dollar_str));
}
int	key_end_index(char *s)
{
	int	i;
	char	*dollar_str;

	i = 0;
	dollar_str = find_dollar_in_quotes(s);
	while (dollar_str[i] && (ft_isalnum(dollar_str[i]) || dollar_str[i] == '_' || dollar_str[i] == ' '))
		i++;
	return(i + 1);
}
int	after_key_chars_number(char *s, int idx)
{
	int	i;

	i = 0;
	while (s[idx])
	{
		idx++;
		i++;
	}
	return (i);
}
int	find_dollar_index(char *s)
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
char	*find_start_in_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\"')
	{
		i++;
	}
	return (&str[++i]);
}
