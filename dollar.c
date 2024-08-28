/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/28 18:53:54 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str, t_env *env_list)
{
	int		i;
	int		j;

	i = 0;

	while (str->command[i] != NULL)
	{
		j = 0;
		while (str->command[i][j])
		{
			if (array_in_dollar(str->command[i][j]) != -1)
			{
				if (dollar_between_quotes(str->command[i][j]) != 1)
					dollar_case(str, env_list);
			}
			else
				break;
			j++;
		}
		i++;
	}
}

void	replace_or_delete_value(char **command, t_env *env_list, char *key)
{
	char *temp;
	char *change_val;

	if (get_env_value(env_list, key) != NULL)
	{
		temp = get_env_value(env_list, key);
		if (overwrite_value(*command, temp) != NULL)
		{
			change_val = overwrite_value(*command, temp);
			*command = change_val;
		}
		else
		{
			change_val = delete_dollar_value(*command);
			*command = change_val;
		}
	}
	else
	{
		change_val = delete_dollar_value(*command);
		*command = change_val;
	}
}

void	handle_dollar_within_quotes(t_cmd *str, t_env *env_list, int i, int j)
{
	char *key;

	key = dollar_in_dquote(str->command[i][j]);
	if (key != NULL)
	{
		replace_or_delete_value(&(str->command[i][j]), env_list, key);
	}
}

void	handle_dollar_outside_quotes(t_cmd *str, t_env *env_list, int i, int j)
{
	char *key;

	key = dollar_not_dquote(str->command[i][j]);
	if (key != NULL)
	{
		replace_or_delete_value(&(str->command[i][j]), env_list, key);
	}
}

void	dollar_case(t_cmd *str, t_env *env_list)
{
	int	i;
	int	j;

	i = 0;
	while (str->command[i])
	{
		j = 0;
		while (str->command[i][j])
		{
			if (dollar_in_dquote(str->command[i][j]) != NULL)
				handle_dollar_within_quotes(str, env_list, i, j);
			else
				handle_dollar_outside_quotes(str, env_list, i, j);
			j++;
		}
		i++;
	}
}


















