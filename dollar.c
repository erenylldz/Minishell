/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/25 19:08:46 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str, t_env *env_list)
{
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
void	dollar_case(t_cmd *str, t_env *env_list)
{
	int	i;
	int	j;
	int	k;
	char	*key;
	char	*temp;

	i = 0;
	k = 0;
	while (str->command[i])
	{	j = 0;
		while(str->command[i][j])
		{
			if (dollar_in_dquote(str->command[i][j]) != NULL)
			{
				key = dollar_in_dquote(str->command[i][j]);
				if(get_env_value(env_list, key) != NULL)
				{
					temp = get_env_value(env_list, key);
					str->command[i][j] = temp;
				}
				else
					delete_dollar_value(str);
			}
			else if (get_env_value(env_list, &str->command[i][j][k + 1 + array_in_dollar(str->command[i][j])]) != NULL)
			{
				temp = get_env_value(env_list, &str->command[i][j][k + 1 + array_in_dollar(str->command[i][j])]);
				str->command[i][j] = temp;
			}
			else
				delete_dollar_value(str);
			j++;
		}
		i++;
	}
}

char *dollar_in_dquote(char *str)
{
	int	i;
	int	dq;

	i = 0;
	dq = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			dq++;
		i++;
	}
	find_dollar(str, dq)
}
char	*find_dollar(char *str, int dq)
{
	int	i;

	i = 0;

	if (dq % 2 == 0)
	{
		while(str[i])
		{

		}
	}
}
int	dollar_ascii(char c)
{
	if (c )
}
