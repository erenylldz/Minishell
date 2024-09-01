/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handle_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:39:46 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/01 14:22:03 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*overwrite_value(char *array, char *value)
{
	char	*dollar_after;
	char	*dollar_before;
	char	*join;
	int		idx;
	int		len;
	if (find_dollar_index(array) != -1)
	{
		len = find_dollar_index(array);
		dollar_before = ft_substr(array, 0, len);
	}
	if (key_end_index(array) != -1)
	{
		idx = key_end_index(array) + find_dollar_in_quotes_idx(array);
		len = after_key_chars_number(array, idx);
		dollar_after = ft_substr(array, idx, len);
	}
	join = ft_strjoin(dollar_before, value);
	join = ft_strjoin(join, dollar_after);
	return (join);
}
char	*delete_dollar_value(char *array)
{
	char	*dollar_after;
	char	*dollar_before;
	char	*join;
	int		idx;
	int		len;
	if (find_dollar_index(array) != -1)
	{
		len = find_dollar_index(array);
		dollar_before = ft_substr(array, 0, len);
	}
	if (key_end_index(array) != -1)
	{
		idx = key_end_index(array) + find_dollar_in_quotes_idx(array);
		len = after_key_chars_number(array, idx);
		dollar_after = ft_substr(array, idx, len);
	}
	join = ft_strjoin(dollar_before, dollar_after);
	return (join);
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
