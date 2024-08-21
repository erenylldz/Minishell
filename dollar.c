/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/21 20:43:57 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str)
{
	char	*env_value;
	int	i;
	int k=0;
	int	j;

	i = 0;
	while (str->command[i] != NULL)
	{
		j = 0;
		while (str->command[i][j])
		{
			if (array_in_dollar(str->command[i][j]) == 1)
			{
				if (get_env_value(str->env_list, str->command[i][j]) != NULL)
				{
					env_value = get_env_value(str->env_list, &str->command[i][j][k + 1]);
					printf("%s\n", env_value);//change_dollar_value(str, env_value, 1);
				}
				else
					printf("ENV YOK\n");//change_dollar_value(str, env_value, 1);
					//change_dollar_value(str, env_value, 2);

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
// void	change_dollar_value(t_cmd *str, char *value, int process)
// {
// 	if
// }
