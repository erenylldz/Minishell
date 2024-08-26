/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:48 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/25 20:04:10 by eryildiz         ###   ########.fr       */
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
void	delete_dollar_value(t_cmd	*str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while(str->command[i])
	{
		j = 0;
		while(str->command[i][j])
		{
			k = 0;
			while(str->command[i][j][k])
			{
				str->command[i][j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
}
void	dollar_case(t_cmd *str, t_env *env_list)
{
	int	i;
	int	j;
	int	k;
	char	*key;
	char	*temp;

	i = 0;
	k = 0;
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
					str->command[i][j] = temp;
				}
				else
					delete_dollar_value(str);
			}
			else if (get_env_value(env_list, &str->command[i][j][k + 1 + array_in_dollar(str->command[i][j])]) != NULL)
			{
				temp = get_env_value(env_list, &str->command[i][j][k + 1 + array_in_dollar(str->command[i][j])]);
				str->command[i][j] = temp;
			}
			else
				delete_dollar_value(str);
			j++;
		}
		i++;
	}
}

// Çift tırnak sayısını kontrol ediyor
int count_quotes(char *str)
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

// Çift tırnak içindeki ilk karakterin adresini dönüyor
char *find_start_in_quotes(char *str)
{
    int i;
	
	i = 0;
    while (str[i] && str[i] != '\"')
	{
        i++;
    }
    return (&str[++i]);
}

// '$' karakterini bulup ve dolardan sonraki metni dönüyor
char *find_dollar_in_quotes(char *str) 
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

// Kabul edilebilir karakterlerin hepsini kopyalar
char *copy_acceptable_chars(char *start) 
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

char *dollar_in_dquote(char *str) 
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
