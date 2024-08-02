/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:40:09 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/02 15:53:48 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_cmd	*str;
	if(ac != 1)
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	str = (t_cmd *)malloc(sizeof(t_cmd));
	if (!str)
		return (0);
	shell_loop(str);
}

void	shell_loop(t_cmd *str)
{
	while (1)
	{
		str->cmd = readline("minishell>");
		add_history(str->cmd);
		cmd_check(str);
	}
}
