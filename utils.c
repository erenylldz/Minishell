/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:35:43 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/16 18:06:41 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(t_cmd *s1, char *s2, int len)
{
	int	i;

	i = 0;
	if ((!s1->cmd || !s2) || (len == 0))
		return (0);
	while (i < len)
	{
		if (s1->cmd[i] != s2[i])
			return (s1->cmd[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_len(t_cmd	*str)
{
	int	i;

	i = 0;
	while (str->cmd[i])
		i++;
	return (i);
}
