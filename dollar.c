/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/24 15:31:33 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str)
{
	char	*env_value;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (str->command[i] != NULL)
	{
		j = 0;
		while (str->command[i][j])
		{
			if (array_in_dollar(str->command[i][j]) == 1)
			{
				if (dollar_between_quotes(str->command[i][j]) != 1)
				{
					if (get_env_value(str->env_list, str->command[i][j]) != NULL)
					{
						env_value = get_env_value(str->env_list, &str->command[i][j][k + 1]);
						str->command[i][j] = env_value;
					}
					else if (get_env_value(str->env_list, str->command[i][j]) == NULL)
						delete_dollar_value(str);
				}
			}
			else
				break;
			j++;
		}
		i++;
	}
}

int	array_in_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
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
void	delete_dollar_value(t_cmd	*str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while(str->command[i])
	{
		j = 0;
		while(str->command[i][j])
		{
			k = 0;
			while(str->command[i][j][k])
			{
				str->command[i][j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
}
