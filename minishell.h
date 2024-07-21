/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:42 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/21 19:28:39 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define CMD_CHECK 1

typedef struct s_cmd
{
	char	*cmd;
	int		dquote_count;
	int		squote_count;
}	t_cmd;

void	shell_loop(t_cmd *str);
int		ft_strncmp(t_cmd *s1, char *s2, int len);
int		ft_len(t_cmd	*str);
void	quote_count(t_cmd	*str);
#endif
