/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:20:23 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/03 22:32:26 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_cmd *str, t_env *env_list)
{
	char	*path;
	if (!str->command)
		return (0);
	if (ft_strchr(str->command[0][0], '/'))
		path = str->command[0][0];
	else
		path = search_path(str, env_list);
	execve(path, str->command, env_list);
}

char	*search_path(t_cmd *str, t_env *env_list)
{
	char	**temp;

	temp = take_path(env_list);
	if (!temp)
		return (NULL); //hata da dönecek
	return (temp);
}

char	*take_path(t_env *env_list)
{
	char	*temp;
	char	**split;
	if (!env_list)
		return (NULL);
	temp = get_env_value(env_list, "PATH");
	if (!temp)
		return (NULL);
	split = ft_split(temp, ':');
	return (split);
}
void	read_command(t_cmd *str, t_env *env_list)
{
	int	fd[2];
	backup_fd(fd);
	if (array_count(str) == 0)
		no_run_pipe(str, env_list);
	else
		run_pipe(str, env_list);
}
void	backup_fd(int fd[2])
{
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
}
void	run_pipe(t_cmd *str, t_env *env_list)
{
	int		p_fd[2];
	str->pid = fork();
	while(str)
	{
		if(str->pid == 0)
		{
			if (node_is_null(redirect) == 0)
				only_run_command();
			else
				open_redirect()
		}
	}
}
void	pipe_check(int	fd[2])
{
	if(pipe(fd) == -1)
	{
		perror("Pipe could not be created\n");
		exit(127);
	}
}
int node_is_null(t_redirect *head)
{
	if (head == NULL)
		return (0);
	return (1);
}
void	no_run_pipe(t_cmd *str, t_env *env_list)
{
	if (node_is_null(redirect) == 0)
		only_run_command(str, env_list);
	else
		open_redirect(str, env_list);

}
void	only_run_command(t_cmd *str, t_env *env_list)
{
	str->pid = fork();
	if (temp->pid == 0)
	{
		set_signal(C_PROCESS);
		run_childprocess(str, env_list);
		exit(g_globals_exit);
	}
	none_child_fork(str, env_list);
}

