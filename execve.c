/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:20:23 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/28 18:37:06 by eryildiz         ###   ########.fr       */
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
		//hata dönecek

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
