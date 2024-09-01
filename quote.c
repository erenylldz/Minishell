/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:40:12 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/01 16:03:08 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	choose_str(t_cmd *str)
{
	char	*temp;
	int		i = 0;
	int		j;

	while(str->command[i])
	{
		j = 0;
		while (str->command[i][j])
		{
			if (in_quote_check(str->command[i][j]) == 1)
			{
				temp = swap_command(str->command[i][j], str);
				str->command[i][j] = temp;
			}
			j++;
		}
		i++;
	}
}
int	in_quote_check(char	*s)
{
	int i = 0;

	while(s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}
char	*swap_command(char *dest, t_cmd *str)
{
	char	*src;
	int		len;
	int		j;
	int		i;

	i = 0;
	j = 0;
	str->single_quote = false;
	str->double_quote = false;
	len = ft_strlen(dest);
	src = malloc(sizeof(char) * (ft_strlen(dest) + 1));
	if (!src)
		return (NULL);
	while (i < len)
	{
		if (dest[i] == '\"' && str->single_quote != true)
		{
			str->double_quote = true;
			i++;
		}
		if (dest[i] == '\'' && str->double_quote != true)
		{
			str->single_quote = true;
			i++;
		}
		src[j] = dest[i];
		j++;
		i++;
	}
	return(src);
}
