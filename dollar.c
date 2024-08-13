/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/13 19:49:06 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str->command[i] != NULL)
	{
		while (str->command[i][j])
		{
			if (array_in_dollar(str->command[i][j]) == 1)
			{
				if (dollar_between_quotes(str->command[i][j]) == 1)
					printf("DOLAR\n");//print_dollar(str->command[i][j]);//dolardan sonra gelen değeri metin olarak yazdıracak işlem
				else
					printf("status\n");
					dollar_case(str->command[i][j], str->env_list);
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
	while (s[i++])
		if (s[i] == '$')
			return (1);
	return(0);
}

int	dollar_between_quotes(char *s)
{
	int	i;
	t_cmd	*str;
	str = malloc(sizeof(t_cmd));
	if (!str)
		return (0);

	i = 0;
	str->dquote = false;
	while (s[i])
	{
		if (s[i] == '\"')
			str->dquote = true;
		else if (s[i] == '\'' && !str->dquote)
			return (1);
		i++;
	}
	return (0);
}

void	dollar_case(char *s, t_env *env_list)
{
	char	*get_value;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
			printf("STATUS\n"); //print_exit_value();
		else
		{
			get_value = get_env_value(env_list, s);
			printf("%s\n", get_value);
		}
		i++;
	}
}

