/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/11 15:25:50 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_cmd(t_cmd *str)
{
	if (ft_strncmp(str, "ls", ft_len(str)) != 0)
		printf("not cmd\n");
	else if (ft_strncmp(str, "echo", ft_len(str)) != 0)
		printf("not cmd\n");
	else if (ft_strncmp(str, "export", ft_len(str)) != 0)
		printf("not cmd\n");
	else if (ft_strncmp(str, "env", ft_len(str)) != 0)
		printf("not cmd\n");
	else if (ft_strncmp(str, "pwd", ft_len(str)) != 0)
		printf("not cmd\n");
	else
		printf("please entry cmd\n");
}
