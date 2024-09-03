/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:38:05 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/03 18:06:37 by eryildiz         ###   ########.fr       */
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
				get_redirect_name(str, i, j);
				delete_redirect_value(str, i, j);
			}
			j++;
		}
		i++;
	}
}


t_redirect *take_name_file(const char *s, int x, int loc)
{
    t_redirect *str;
    size_t len;
    size_t i;

	printf("%s\n",s);
    str = malloc(sizeof(t_redirect));
    if (!str)
        return (NULL);
    len = ft_strlen(s);
    str->data = malloc(len + 1);
    if (!str->data)
    {
        free(str);
        return (NULL);
    }
    i = 0;
    while (i < len)
    {
        str->data[i] = s[i];
        i++;
    }
    str->data[i] = '\0';
    str->type = x;
	str->location = loc;
    str->prev = NULL;
    str->next = NULL;
	printf("Redirect: %s, Type: %d\n", str->data, str->type);
    return (str);
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
	int		x;
	int		y;
	int		temp_size;
	char	*temp;

	x = 0;
	y = 0;
	temp_size = redirect_array_idx(str->command[i][j]);
	temp = malloc((temp_size + 1) * sizeof(char));
	if (!temp)
		return;
	while (str->command[i][j][x])
	{
		if ((str->command[i][j][x] == '>' && str->command[i][j][x + 1] == '>') ||
			(str->command[i][j][x] == '<' && str->command[i][j][x + 1] == '<'))
			break ;
		else if (str->command[i][j][x] == '>' || str->command[i][j][x] == '<')
			break ;
		if (y < temp_size)
			temp[y++] = str->command[i][j][x];
		x++;
	}
	temp[y] = '\0';
	free(str->command[i][j]);
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

void	get_redirect_name(t_cmd *str, int i, int j)
{
	int	x;
	char	*file;

	x = 0;
	if(is_only_redirection_symbols(str->command[i][j]) == 1 && redirection_type(str->command[i][j]) != 0)
	{
		x = redirection_type(str->command[i][j]);
		file = copy_chars_next_array(str->command[i][j + 1]);
		take_name_file(file, x, i);
	}
	else if(is_only_redirection_symbols(str->command[i][j]) == 0 && redirection_type(str->command[i][j]) != 0)
	{
		x = redirection_type(str->command[i][j]);
		file = copy_after_redirection(str->command[i][j]);
		take_name_file(file, x, i);
	}
}

int	redirection_type(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == '>' && array[i + 1] == '>')
			return (APPEND);
		else if (array[i] == '<' && array[i + 1] == '<')
			return (HEREDOC);
		else if (array[i] == '>')
			return (OUTPUT);
		else if (array[i] == '<')
			return (INPUT);
		i++;
	}
	return (0);
}

int	skip_redirection(char *array, int i)
{
	if ((array[i] == '>' && array[i + 1] == '>') || (array[i] == '<' && array[i + 1] == '<'))
		i += 2;
	else if (array[i] == '>' || array[i] == '<')
		i++;
	return (i);
}

char *copy_after_redirection(char *array)
{
    int i;
    int j;
    char *file;
    bool inside_double_quotes;
    bool inside_single_quotes;

	i = 0;
	j = 0;
	inside_double_quotes = false;
	inside_single_quotes = false;
    while (array[i])
    {
        i = skip_redirection(array, i);
        if (array[i - 1] == '>' || array[i - 1] == '<')
        {
            file = (char *)malloc(sizeof(char) * (strlen(array) - i + 1));
            if (!file)
                return (NULL);

            while (array[i])
            {
                if (array[i] == '\"' && !inside_single_quotes)
                {
                    inside_double_quotes = !inside_double_quotes;
                    i++;
                    continue;
                }
                if (array[i] == '\'' && !inside_double_quotes)
                {
                    inside_single_quotes = !inside_single_quotes;
                    i++;
                    continue;
                }
                if (inside_double_quotes && array[i] == '\'')
                {
                    i++;
                    continue;
                }
                if (inside_single_quotes && array[i] == '\"')
                {
                    i++;
                    continue;
                }
                file[j++] = array[i++];
            }
            file[j] = '\0';
            return (file);
        }
        i++;
    }
    return (NULL);
}

char	*copy_chars_next_array(char *str)
{
    int i;
	int	j;
    int double_quote_seen;
    int single_quote_seen;
    char *result;

	result = malloc(strlen(str) + 1);
	single_quote_seen = 0;
	double_quote_seen = 0;
	i = 0;
	j = 0;
    if (!result)
        return (NULL);
    while (str[i])
	{
        if (str[i] == '\"' && !single_quote_seen)
		{
            double_quote_seen = !double_quote_seen;
            i++;
            continue;
        }
        if (str[i] == '\'' && !double_quote_seen)
		{
            single_quote_seen = !single_quote_seen;
            i++;
            continue;
        }
        if ((double_quote_seen && str[i] == '\'') || (single_quote_seen && str[i] == '\"'))
		{
            i++;
            continue;
        }
        result[j++] = str[i++];
    }
    result[j] = '\0';
    return (result);
}
