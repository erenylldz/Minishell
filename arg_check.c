/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:25:27 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/30 19:01:31 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_check(t_cmd *str)
{
	if (array_count(str) == 0)
		get_cmd(str);
	if (array_count(str) != 0)
		get_multi_cmd(str);
}

int	array_count(t_cmd *str)
{
	int	i;

	i = 0;
	while(str->command[i])
		i++;
	return(i);
}
char	*get_cmd(t_cmd *str)
{
	int		x;
	int		j;
	char	*cmd_temp;
	char	**arg_temp;

	j = 1;
	x = 0;
	cmd_temp = ft_strdup(str->command[0][0]);
	while(str->command[0][j])
	{
		arg_temp[x] = ft_strdup(str->command[0][j]);
		j++;
		x++;
	}
	return (cmd_temp, arg_temp);
}
char	*get_multi_cmd(t_cmd *str)
{
	int	i;
	int	j;
	int	x;
	char	**cmd_temp;
	char	**arg_temp;

	i = 0;
	while(str->command[i])
	{
		j = 1;
		x = 0;
		while(str->command[i][j])
		{
			arg_temp[x] = ft_strdup(str->command[i][j])
			j++;
			x++;
		}
		i++;
	}
}

