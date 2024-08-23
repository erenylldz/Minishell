/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:54 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/23 20:15:02 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_check(t_cmd *str)
{
	quote_count(str);
	str->ncmd = ft_split2(str->cmd, '|');
	ft_split_space(str);
	handle_dollar(str);
	redirect(str);
	choose_str(str);
	print_cmd(str);
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
	str->double_quote = false;
	str->single_quote = false;
	str->i = 0;
	str->j = 0;
	str->ncmd_count = 0;
	while (str->ncmd[str->ncmd_count] != NULL)
		str->ncmd_count++;
	str->command = (char ***)malloc((str->ncmd_count + 1) * sizeof(char **));
	//silinebilir ↓
	if (!str->command) // malloc'ın başarısız olma durumu kontrol ediliyor
		return;
	//
	while (str->ncmd[str->i])
	{
		str->command[str->i] = ft_split2(str->ncmd[str->i], ' ');
		//silinebilir ↓
		if (!str->command[str->i]) // malloc'ın başarısız olma durumu kontrol ediliyor
		{
			while (str->i-- > 0)
				free(str->command[str->i]);
			free(str->command);
			return;
		}
		str->i++;
	}
	str->command[str->ncmd_count] = NULL;
	// // AŞAĞIDAKİ DÖNGÜ KONTROL AMAÇLI YAZILDI SİLİNECEK!!!!!!!!!!!!
	// int z;
    // int y;
    // z = 0;
	// while (str->command[z] != NULL)
	// {
	// 	y = 0;
	// 	printf("Command %d:\n", z);
	// 	while (str->command[z][y] != NULL)
	// 	{
	// 		printf("  Arg %d: %s\n", y, str->command[z][y]);
	// 		y++;
	// 	}
	// 	z++;
	// }
}
