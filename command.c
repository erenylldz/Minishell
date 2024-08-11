/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/10 11:41:58 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_check(t_cmd *str)
{
	quote_count(str);
	str->ncmd = ft_split2(str->cmd, '|');
	ft_split_space(str);
}

void	quote_count(t_cmd *str)
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
	if (str->dquote_count % 2 != 0 || str->squote_count % 2 != 0)
		printf("error\n");
}

// void ft_set_quote_type(int *quote, char c)
// {
//     if (*quote == -1 && (c == '\'' || c == '\"'))
//         *quote = (int)c;
//     else if (*quote == (int)(c))
//         *quote = -1;
// }

void	ft_split_space(t_cmd *str)
{
	int	x;
	int	y;

	str->double_quote = false;
	str->single_quote = false;
	str->i = 0;
	str->j = 0;
	str->ncmd_count = 0;
	while (str->ncmd[str->ncmd_count] != NULL)
		str->ncmd_count++;
	str->command = (char ***)malloc((str->ncmd_count + 1) * sizeof(char **));
	while (str->ncmd[str->i])
	{
		str->command[str->i] = ft_split2(str->ncmd[str->i], ' ');
		str->i++;
	}
	str->command[str->ncmd_count] = NULL;

	// AŞAĞIDAKİ DÖNGÜ KONTROL AMAÇLI YAZILDI SİLİNECEK!!!!!!!!!!!!
	x = 0;
	while (str->command[x] != NULL)
	{
		y = 0;
		printf("Command %d:\n", x);
		while (str->command[x][y] != NULL)
		{
			printf("  Arg %d: %s\n", y, str->command[x][y]);
			y++;
		}
		x++;
	}
}
