/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:38:05 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/29 17:08:11 by eryildiz         ###   ########.fr       */
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
			j++;
		}
		i++;
	}
}

static int	test(char **str, int i, int j)
{
	if (str[i][j] == '>' && str[i][j + 1]
		&& str[i][j + 1] == '>' && !str[i][j + 2])
	{
		take_name_file(str[i + 1], APPEND);
		return (0);
	}
	else if (str[i][j] == '<' && str[i][j + 1]
		&& str[i][j + 1] == '<' && !str[i][j + 2])
	{
		take_name_file(str[i + 1], HEREDOC);
		return (0);
	}
	else if (str[i][j] == '<' && str[i][j + 1]
		&& str[i][j + 1] == '<' && str[i][j + 2])
	{
		take_name_file(&str[i][j + 2], HEREDOC);
		return (0);
	}
	else if (str[i][j] == '>' && str[i][j + 1]
		&& str[i][j + 1] == '>' && str[i][j + 2])
	{
		take_name_file(&str[i][j + 2], APPEND);
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
				take_name_file(&str[i + 1][j], INPUT);
			else if (str[i][j] == '>' && !str[i][j + 1])
				take_name_file(&str[i + 1][j], OUTPUT);
			else if (str[i][j] == '>' && str[i][j + 1])
				take_name_file(&str[i][j + 1], OUTPUT);
			else if (str[i][j] == '<' && str[i][j + 1])
				take_name_file(&str[i][j + 1], INPUT);
		}
	}
}

void	take_name_file(char *s, int x)
{
	static int	h = 0;
	static int	a = 0;
	static int	o = 0;
	static int	i = 0;

	t_cmd	*str = malloc(sizeof(t_cmd));
	if (!str)
		return ;

	str->heredoc = malloc(sizeof(char *) * HEREDOC_SIZE);
	str->append = malloc(sizeof(char *) * APPEND_SIZE);
	str->input = malloc(sizeof(char *) * INPUT_SIZE);
	str->output = malloc(sizeof(char *) * OUTPUT_SIZE);

	if (!str->heredoc || !str->append || !str->input || !str->output)
		return ;
	if (x == HEREDOC)
		str->heredoc[h++] = ft_strdup(s);
	else if(x == APPEND)
		str->append[a++] = ft_strdup(s);
	else if(x == INPUT)
		str->input[i++] = ft_strdup(s);
	else if (x == OUTPUT)
		str->output[o++] = ft_strdup(s);
}

