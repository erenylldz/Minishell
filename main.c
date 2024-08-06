/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:40:09 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/06 17:08:12 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_cmd	*str;
	if(ac != 1)
	{
		printf("This program does not accept arguments\n");
		return EXIT_FAILURE;
	}
	str = (t_cmd *)malloc(sizeof(t_cmd));
	if (!str)
		return (0);
	shell_loop(str);
	free(str);
	return EXIT_SUCCESS;
}

void	shell_loop(t_cmd *str)
{
	while (1)
	{
		str->cmd = readline("minishell>");
		add_history(str->cmd);
		cmd_check(str);
		
		str->args = NULL;
		
		if (strcmp(str->cmd, "exit") == 0)
        {
            ft_exit(str);
            break;
        }
        free(str->cmd); 
	}
}
