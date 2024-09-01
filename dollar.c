/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/09/01 14:49:55 by eryildiz         ###   ########.fr       */
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
				in_dquote_process(str, env_list, i, j);
			else
				not_dquote_process(str, env_list, i, j);
			j++;
		}
		i++;
	}
}

void	in_dquote_process(t_cmd *str, t_env *env_list, int i, int j)
{
	char	*key;
	char	*change_val;
	char	*temp;

	key = dollar_in_dquote(str->command[i][j]);
	if(get_env_value(env_list, key) != NULL)
	{
		temp = get_env_value(env_list, key);
		if (overwrite_value(str->command[i][j], temp) != NULL)
		{
			change_val = overwrite_value(str->command[i][j], temp);
			str->command[i][j] = change_val;
		}
		else
		{
			change_val = delete_dollar_value(str->command[i][j]);
			str->command[i][j] = change_val;
		}
	}
	else
	{
		change_val = delete_dollar_value(str->command[i][j]);
		str->command[i][j] = change_val;
	}
}

void	not_dquote_process(t_cmd *str, t_env *env_list, int i, int j)
{
	char	*key;
	char	*change_val;
	char	*temp;

	key = dollar_not_dquote(str->command[i][j]);
	if (get_env_value(env_list, key) != NULL)
		{
			temp = get_env_value(env_list, key);
			if (overwrite_value(str->command[i][j], temp) != NULL)
			{
				change_val = overwrite_value(str->command[i][j], temp);
				str->command[i][j] = change_val;
			}
			else
			{
				change_val = delete_dollar_value(str->command[i][j]);
				str->command[i][j] = change_val;
			}
		}
	else
	{
		change_val = delete_dollar_value(str->command[i][j]);
		str->command[i][j] = change_val;
	}
}
















