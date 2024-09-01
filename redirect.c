/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:38:05 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/01 17:50:59 by eryildiz         ###   ########.fr       */
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
			if (is_outside_quotes(str->command[i][j]) == true)
			{
				get_redirect_name(str->command[i]);
				delete_redirect_value(str, i, j);
			}
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
	t_redirect	*str = malloc(sizeof(t_redirect));
	if (!str)
		return ;
	if(x == OUTPUT)
	{
		str->data = s;
		str->type = OUTPUT;
	}
	else if(x == INPUT)
	{
		str->data = s;
		str->type = INPUT;
	}
	else if(x == HEREDOC)
	{
		str->data = s;
		str->type = HEREDOC;
	}
	else if(x == APPEND)
	{
		str->data = s;
		str->type = APPEND;
	}
}

void	delete_redirect_value(t_cmd *str, int i, int j)
{
		if (is_only_redirection_symbols(str->command[i][j]) == 1)
		{
			str->command[i][j] = "";
			str->command[i][j + 1] = "";
		}
		else
			delete_only_redirect(str, i, j);
}

int	is_only_redirection_symbols(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == '>' || array[i] == '<')
		{
			if (array[i] == '>' && array[i+1] == '>')
				i++;
			else if (array[i] == '<' && array[i+1] == '<')
				i++;
		}
		else
			return (0);
		i++;
	}
	return (1);
}
bool	is_outside_quotes(const char *str)
{
	bool single_quote;
	bool double_quote;
	int i;

	single_quote = false;
	double_quote = false;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !double_quote)
			single_quote = !single_quote;
		else if (str[i] == '\"' && !single_quote)
			double_quote = !double_quote;
		if (!single_quote && !double_quote)
		{
			if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
				return (true);
			else if (str[i] == '>' || str[i] == '<')
			 return (true);
		}
		i++;
	}
	return (false);
}

void	delete_only_redirect(t_cmd *str, int i, int j)
{
	int	x;
	int	y;
	char	*temp;

	x = 0;
	y = 0;
	temp = malloc(redirect_array_idx(str->command[i][j]) * sizeof(char));
	while(str->command[i][j][x])
	{
		if ((str->command[i][j][x] == '>' && str->command[i][j][x] == '>') || (str->command[i][j][x] == '<' && str->command[i][j][x] == '<'))
			break;
		else if (str->command[i][j][x] == '>' || str->command[i][j][x] == '<')
			break;
		temp[y] = str->command[i][j][x];
		x++;
		y++;
	}
	temp[y] = '\0';
	str->command[i][j] = temp;
}
int	redirect_array_idx(char	*str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
			break;
		else if (str[i] == '>' || str[i] == '<')
		break;
		i++;
	}
	return (i);
}
