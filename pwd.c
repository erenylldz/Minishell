/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:41:08 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/27 17:41:12 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_cmd *str)
{
	char	*c;

	c = getcwd(NULL, 0);
	if (!c)
	{
		perror("getcwd");
		str->status = BUILTIN;
		return;
	}
	printf("%s\n", c);
	free(c);
}
