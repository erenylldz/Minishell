/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:40:09 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/11 15:15:16 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_cmd	*str;
	t_env	*env_list;

	(void)av;
	env_list = NULL;
	if (ac != 1)
	{
		printf("This program does not accept arguments\n");
		return (EXIT_FAILURE);
	}
	str = (t_cmd *)malloc(sizeof(t_cmd));
	if (!str)
		return (0);
	shell_loop(str, env, env_list);
	free(str);
	return (EXIT_SUCCESS);
}

void	shell_loop(t_cmd *str, char **env, t_env *env_list)
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
			break ;
		}
		else if (strcmp(str->cmd, "env") == 0)
		{
			parse_env(env, &env_list);
			print_env_list(env_list);
			free_env_list(env_list);
		}
		free(str->cmd);
	}
}
