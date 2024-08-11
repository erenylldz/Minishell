/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/11 19:19:41 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str->command[i][j])
	{
		while (str->command[i][j])
		{
			if (array_in_dollar(str->command[i][j]) == 1)
			{
				if (dollar_between_quotes(str->command[i][j]) == 1)
					print_dollar(str->command[i][j])//dolardan sonra gelen değeri metin olarak yazdıracak işlem
				else
					dollar_case(str->command[i][j])
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

	i = 0;
	str->dquote = false;
	str->squote = false;
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

void	dollar_case(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] == '$')
			print_current_pid();
		else if (s[i] == '$' && s[i + 1] == '?')
			//EXIT STATUSU BASTIRACAK FONKSİYON
		else
			//envden key arayıp valueyi yazdıracak fonskiyon
	}
}
void	print_current_pid()
{
	pid_t pid = getpid();
	printf("%d: command not found\n", pid);
}
