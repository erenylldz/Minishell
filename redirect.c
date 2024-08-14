/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:38:05 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/14 16:46:58 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"

 void	redirect(t_cmd *str)
 {
	int	i;
	int	j;

	i = 0;
	while (str->command[i])
	{
		j = 0;
		while (str->command[i][j])
		{
			if (array_in_redirect(str->command[i][j]) == 1)
				get_redirect_name(str->command[i]);
			else if(array_in_redirect(str->command[i][j]) == 2)
				get_redirect_name(str->command[i]);
			else
				break;
			j++;
		}
		i++;
	}
}

static int	test(char *s, int i, int j)
{
	if (str[i][j] == '>' && str[i][j + 1]
		&& str[i][j + 1] == '>' && !str[i][j + 2])
	{
		take_name_file(str[i + 1]);
		return (0);
	}
	else if (str[i][j] == '<' && str[i][j + 1]
		&& str[i][j + 1] == '<' && !str[i][j + 2])
	{
		take_name_file(str[i + 1]);
		return (0);
	}
	else if (str[i][j] == '<' && str[i][j + 1]
		&& str[i][j + 1] == '<' && str[i][j + 2])
	{
		take_name_file(&str[i][j + 2]);
		return (0);
	}
	else if (str[i][j] == '>' && str[i][j + 1]
		&& str[i][j + 1] == '>' && str[i][j + 2])
	{
		take_name_file(&str[i][j + 2]);
		return (0);
	}
	return (1);
}

int	array_in_redirect(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '>' || s[i] == '<')
			return (1);
		else if ((s[i] == '>' || s[i] == '<') && s[i + 1] == '\0')
			return (2);
		i++;
	}
	return (0);
}
void	get_redirect_name(char	**str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (test(str, i, j) == 0)
				break ;
			else if (str[i][j] == '<' && !str[i][j + 1])
				take_name_file(str[i + 1]);
			else if (str[i][j] == '>' && !str[i][j + 1])
				take_name_file(&str[i + 1][j]);
			else if (str[i][j] == '>' && str[i][j + 1])
				take_name_file(&str[i][j + 1]);
			else if (str[i][j] == '<' && str[i][j + 1])
				take_name_file(&str[i][j + 1]);
		}
	}
}

void	take_name_file(char *s)
{
	int	i;

	i = 0;
	printf("%s\n",s);
}

