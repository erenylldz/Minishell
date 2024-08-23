/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:40:12 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/23 19:52:00 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    choose_str(t_cmd *str)
{
    char    *temp;
    int i = 0;
    int j;

    while(str->command[i])
    {
        j = 0;
        while (str->command[i][j])
        {
            temp = swap_command(str->command[i][j], str);
            str->command[i][j] = temp;
            j++;
        }
        i++;
    }
	free(temp);
}

char    *swap_command(char *dest, t_cmd *str)
{
    char    *src;

	int	len = ft_strlen(dest);
    // src = malloc(sizeof(char) * (ft_strlen(dest) /*- (str->squote_count + str->dquote_count))*/));
    // if (!src)
    //     return (NULL);
    int i = 0;
    int j = 0;
    str->double_quote = false;
    str->single_quote = false;
    while (i < len)
    {
        if (dest[i] == '\"' && !str->single_quote)
        {
            str->double_quote = !str->double_quote;
            i++;
        }
        else if (dest[i] == '\'' && !str->double_quote)
        {
            str->single_quote = !str->single_quote;
            i++;
        }
        src = ft_strdup(dest);
		j++;
		i++;
    }
	printf("%s\n",src );
    return(src);
}
