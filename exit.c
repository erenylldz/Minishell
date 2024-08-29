/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:54:30 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/29 17:49:35 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_cmd *str)
{
	int	exit_status;
	int	i;

	exit_status = 0;
	if (str->cmd && strcmp(str->cmd, "exit") == 0)
	{
		if (str->args && str->args[1])
			exit_status = atoi(str->args[1]);
		free(str->cmd);
		if (str->args)
		{
			i = 0;
			while (str->args[i])
			{
				free(str->args[i]);
				i++;
			}
			free(str->args);
		}
		exit(exit_status);
	}
}
