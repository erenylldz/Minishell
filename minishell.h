/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:42 by eryildiz          #+#    #+#             */
/*   Updated: 2024/07/17 14:27:38 by eryildiz         ###   ########.fr       */
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
int		dquote(t_cmd	*str);
int		squote(t_cmd	*str);
#endif
