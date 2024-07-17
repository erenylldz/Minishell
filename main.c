/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:40:09 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/17 14:42:05 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_cmd	*temp;

	temp = (t_cmd *)malloc(sizeof(t_cmd));
	if (!temp)
		return (0);
	shell_loop(temp);
}

void	shell_loop(t_cmd *str)
{
	t_cmd	*read;

	while (1)
	{
		read->cmd = readline("minishell>");
		add_history(read->cmd);
		dquote(&read->cmd);
		squote(&read->cmd);
		printf("%s", read->cmd);
	}
}
