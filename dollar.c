/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/27 18:23:51 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar(t_cmd *str, t_env *env_list)
{
	int		i;
	int		j;

	i = 0;

	while (str->command[i] != NULL)
	{
		j = 0;
		while (str->command[i][j])
		{
			if (array_in_dollar(str->command[i][j]) != -1)
			{
				if (dollar_between_quotes(str->command[i][j]) != 1)
					dollar_case(str, env_list);
			}
			else
				break;
			j++;
		}
		i++;
	}
}

int	array_in_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}
int	dollar_between_quotes(char *s)
{
	int		i;
	bool	quote;

	quote = false;
	i = 0;
	while(s[i])
	{
		if (s[i] == '\"')
			quote = !quote;
		else if (s[i] == '\'' && !quote)
			return (1);
		i++;
	}
	return (0);
}
void	dollar_case(t_cmd *str, t_env *env_list)
{
	int	i;
	int	j;

	char	*key;
	char	*temp;
	char	*change_val;
	i = 0;
	while (str->command[i])
	{	j = 0;
		while(str->command[i][j])
		{
			if (dollar_in_dquote(str->command[i][j]) != NULL)
			{
				key = dollar_in_dquote(str->command[i][j]);
				if(get_env_value(env_list, key) != NULL)
				{
					temp = get_env_value(env_list, key);
					if (overwrite_value(str->command[i][j], temp) != NULL)
					{
						change_val = overwrite_value(str->command[i][j], temp);
						str->command[i][j] = change_val;
					}
					else
					{
						change_val = delete_dollar_value(str->command[i][j]);
						str->command[i][j] = change_val;
					}
				}
				else
					delete_dollar_value(str->command[i][j]);
			}
			else
			{
				key = dollar_not_dquote(str->command[i][j]);
				if (get_env_value(env_list, key) != NULL)
				{
					temp = get_env_value(env_list, key);
					if (overwrite_value(str->command[i][j], temp) != NULL)
					{
						change_val = overwrite_value(str->command[i][j], temp);
						str->command[i][j] = change_val;
					}
					else
					{
						change_val = delete_dollar_value(str->command[i][j]);
						str->command[i][j] = change_val;
					}
				}
				else
				{
					change_val = delete_dollar_value(str->command[i][j]);
					str->command[i][j] = change_val;
				}
			}
			j++;
		}
		i++;
	}
}

int	count_quotes(char *str)
{
	int quote_count;
	int i;

	i = 0;
	quote_count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			quote_count++;
		i++;
	}
	return (quote_count);
}


char	*find_start_in_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\"')
	{
		i++;
	}
	return (&str[++i]);
}


char	*find_dollar_in_quotes(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '$')
	{
		i++;
	}
	if (str[i] == '$')
		return (&str[++i]);
	return (NULL);
}

char	*copy_acceptable_chars(char *start)
{
	int i;

	i = 0;
	while (start[i] && (ft_isalnum(start[i]) || start[i] == '_' || start[i] == ' '))
		i++;
	char *temp;
	temp = (char *)malloc(i + 1);
	if (!temp)
		return (NULL);
	int j;

	j = 0;
	while (j < i)
	{
		temp[j] = start[j];
		j++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*dollar_in_dquote(char *str)
{
	if (count_quotes(str) != 2)
		return (NULL);
	char *start;
	char *dollar_str;

	start = find_start_in_quotes(str);
	dollar_str = find_dollar_in_quotes(start);
	if (!dollar_str)
		return (NULL);
	return (copy_acceptable_chars(dollar_str));
}
char	*delete_dollar_value(char *array)
{
	char	*dollar_after;
	char	*dollar_before;
	char	*join;
	int		idx;
	int		len;
	if (find_dolllar_index(array) != -1)
	{
		len = find_dolllar_index(array);
		dollar_before = ft_substr(array, 0, len);
	}
	if (key_end_index(array) != -1)
	{
		idx = key_end_index(array);
		len = after_key_chars_number(array, idx);
		dollar_after = ft_substr(array, idx, len);
	}
	join = ft_strjoin(dollar_before, dollar_after);
	return (join);
}
char	*overwrite_value(char *array, char *value)
{
	char	*dollar_after;
	char	*dollar_before;
	char	*join;
	int		idx;
	int		len;
	if (find_dolllar_index(array) != -1)
	{
		len = find_dolllar_index(array);
		dollar_before = ft_substr(array, 0, len);
	}
	if (key_end_index(array) != -1)
	{
		idx = key_end_index(array);
		len = after_key_chars_number(array, idx);
		dollar_after = ft_substr(array, idx, len);
	}
	join = ft_strjoin(dollar_before, value);
	join = ft_strjoin(join, dollar_after);
	return (join);
}

int	find_dolllar_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}
int	after_key_chars_number(char *s, int idx)
{
	int	i;

	i = 0;
	while (s[idx])
	{
		idx++;
		i++;
	}
	return (i);
}
int	key_end_index(char *s)
{
	int	i;
	char	*dollar_str;

	i = 0;
	dollar_str = find_dollar_in_quotes(s);
	while (dollar_str[i] && (ft_isalnum(dollar_str[i]) || dollar_str[i] == '_' || dollar_str[i] == ' '))
		i++;
	return(i);
}
char	*dollar_not_dquote(char *str)
{
	char	*dollar_str;

	dollar_str = find_dollar_in_quotes(str);
	if (!dollar_str)
		return (NULL);
	return (copy_acceptable_chars(dollar_str));
}
