/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:38:05 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/13 20:33:15 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"

 void	redirect(t_cmd *str)
 {
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str->command[i][j])
	{
		while (str->command[i][j])
		{
			if (array_in_redirect(str->command[i][j]) == 1)
			{

			}
		}
	}
}


int	array_in_redirect(char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		if (s[i] == '>' || s[i] == '<')
			return (1);
	return (0);
}
void	get_redirect_name(char	*str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' && str[i + 1] != '>')
			take_name_file(str + (i + 1)) // meta karakter sonrası file adını alacak fonksiyon
		if (str[i] == '>' && str[i + 1] == '>')
			take_name_file(str + (i + 2)) // meta karakter sonrası file adını alacak fonksiyon
		if (str[i] == '<' && str[i + 1] != '<')
			take_name_file(str + (i + 1)) // meta karakter sonrası file adını alacak fonksiyon
		if (str[i] == '<' && str[i + 1] == '<')
			take_name_file(str + (i + 2)) // meta karakter sonrası file adını alacak fonksiyon
	}
}

void	take_name_file(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		
	}
}

