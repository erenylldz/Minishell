/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/08 17:50:58 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_check(t_cmd *str)
{
	quote_count(str);
	pipe_check(str);

}

// int	is_line_empty(t_cmd *str)
// {
// 	str->i = 0;
// 	while (str->cmd[str->i])
// 	{
// 		if (str->cmd[str->i] != ' ' || str->cmd[str->i] != '\t')
// 			return (FALSE);
// 		str->i++;
// 	}
// 	return (TRUE);
// }

void	quote_count(t_cmd	*str)
{
	str->i = 0;
	str->dquote = false;
	str->squote = false;
	str->dquote_count = 0;
	str->squote_count = 0;
	while (str->cmd[str->i] != '\0')
	{
		if (str->cmd[str->i] == '\"' && str->squote != true)
		{
			str->dquote = true;
			str->dquote_count++;
			if (str->dquote_count % 2 == 0)
				str->dquote = false;
		}
		else if (str->cmd[str->i] == '\'' && str->dquote != true)
		{
			str->squote = true;
			str->squote_count++;
			if (str->squote_count % 2 == 0)
				str->squote = false;
		}
		str->i++;
	}
	if(str->dquote_count % 2 != 0 || str->squote_count % 2 != 0)
		printf("error\n");
}

void	ft_split_space(t_cmd *str)
{
	str->i = 0;
	str->ncmd_count = 0;
	while (str->ncmd[str->ncmd_count] != NULL)
		str->ncmd_count++;
	str->command = (char ***)malloc((str->ncmd_count + 1) * sizeof(char **));
	while (str->ncmd[str->i])
	{
		str->command[str->i] = ft_split(str->ncmd[str->i], ' ');
		str->i++;
	}
	str->command[str->ncmd_count] = NULL;

	// 	int x = 0;
    // int y;

    // while (str->command[x] != NULL)  // command[i] alt dizisi NULL olmadığı sürece devam et.
    // {
    //     y = 0;
    //     printf("Command %d:\n", x);
    //     while (str->command[x][y] != NULL)  // command[i][j] NULL olmadığı sürece devam et.
    //     {
    //         printf("  Arg %d: %s\n", y, str->command[x][y]);
    //         y++;
    //     }
    //     x++;
    // }

}
