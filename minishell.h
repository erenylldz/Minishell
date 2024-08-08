/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:42 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/08 15:03:04 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
#include  <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TRUE 1
# define FALSE 0

// typedef struct s_pipe
// {
// 	size_t	parts_counts;
// 	size_t	idx;
// 	size_t	len;
// 	char	*start;
// 	char	*temp;
// 	bool	single_quote;
// 	char	**ncmd;
// 	bool	double_quote;
// }	t_pipe;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	int		dquote_count;
	int		squote_count;
	bool	squote;
	bool	dquote;
	int		i;
	int		ncmd_count;
	char	***command;
//	t_pipe data;
	size_t	parts_counts;
	size_t	idx;
	size_t	len;
	char	**ncmd;
	char	*start;
	char	*temp;
	bool	single_quote;
	bool	double_quote;
}	t_cmd;


void	shell_loop(t_cmd *str, char **env);
void	quote_count(t_cmd	*str);
void	pipe_check(t_cmd	*str);
void	cmd_check(t_cmd *str);
int		is_line_empty(t_cmd *str);
void	split_commands(t_cmd *str);
void	process_quotes(t_cmd *str);
size_t	ft_strnlen(const char *src, size_t i);
char	*ft_strndup(const char *s, size_t n);
void	ft_exit(t_cmd *str);
void	print_env(char **env, int status);
void	ft_split_space(t_cmd *str);
#endif
