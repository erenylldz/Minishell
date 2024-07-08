/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:40:09 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:01 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_cmd	*str;

	str = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		retrun(1)
	shell_loop(str)
}
void	shell_loop(t_cmd *str)
{
	while(1)
	{
		str->cmd = readline()
	}
}
