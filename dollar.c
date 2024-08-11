/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/11 18:54:11 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

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
				// echo lkjlj | cat a.txt
			{
				if () // dolar tek tırnak içerisinde mi
			}
			j++;
		}
		i++;
	}
}

int		array_in_dollar(char *s);
{
	int i;

	i = 0;
	while (s[i] != NULL)
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}