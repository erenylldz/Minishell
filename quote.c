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
            temp = copy_command(str->command[i][j], str);
            str->command[i][j] = temp;
            j++;
        }
        i++;
    }
}

char    *copy_command(char  *copy, t_cmd *str)
{
    char    *swap;
    swap = malloc(sizeof(ft_strlen(copy) - str->squote_count - str->dquote_count + 1));
    if (!swap)
        return (NULL);
    swap = swap_command(copy, str);
    return (swap);
}

char    *swap_command(char *dest, t_cmd *str)
{
    char    *src;
    src = malloc(sizeof(ft_strlen(dest) - str->squote_count - str->dquote_count + 1));
    if (!src)
        return (NULL);
    int i = 0;
    int j = 0;
    str->double_quote = false;
    str->single_quote = false;
    while (dest[i] != '\0')
    {
        if (dest[i] == '\"' && !str->single_quote)
        {
            str->double_quote = !str->double_quote;
            i++;
        }
        if (dest[i] == '\'' && !str->double_quote)
        {
            str->single_quote = !str->single_quote;
            i++;
        }
        src[j] = dest[i];
        i++;
        j++;
    }
    src[j] = '\0';
    return(src);
}
