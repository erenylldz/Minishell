/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:20:23 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/31 19:57:20 by eryildiz         ###   ########.fr       */
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
	return (0);
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
		non_pipe()
	else
		// pipe var demektir

}
void	backup_fd(int fd[2])
{
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
}
