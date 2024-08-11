/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:42 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/11 17:34:22 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define BUILTIN 9

typedef struct s_cmd
{
	char			*cmd;
	char			**ncmd;
	char			***command;
	char			**args;
	int				dquote_count;
	int				squote_count;
	int				i;
	int				j; // make atılmıyordu
	int				ncmd_count;
	bool			squote;
	bool			dquote;
	bool			single_quote;
	bool			double_quote;
	int				status; // İşlem durumu için
}					t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

void				shell_loop(t_cmd *str, char **env, t_env *env_list);
void				quote_count(t_cmd *str);
void				cmd_check(t_cmd *str);
size_t				ft_strnlen(const char *src, size_t i);
char				*ft_strndup(const char *s, size_t n);
void				ft_exit(t_cmd *str);
void				ft_split_space(t_cmd *str);
char				**ft_split2(char const *s, char c);
void				print_env_list(t_env *env_list);
void				parse_env(char **envp, t_env **env_list);
void				add_env_node(t_env **env_list, char *key, char *value);
t_env				*create_env_node(char *key, char *value);
void				free_env_list(t_env *env_list);
void	ft_pwd(t_cmd *str);
#endif
