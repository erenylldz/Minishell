/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:42 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/25 17:40:43 by eryildiz         ###   ########.fr       */
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
# define HEREDOC 10
# define APPEND 11
# define INPUT 12
# define OUTPUT 13
# define HEREDOC_SIZE 999
# define APPEND_SIZE 999
# define INPUT_SIZE 999
# define OUTPUT_SIZE 999
typedef struct s_cmd
{
	char			*cmd;
	char			**ncmd;
	char			***command;
	char			**args;
	char			**heredoc;
	char			**append;
	char			**input;
	char			**output;
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
	struct s_env	*env_list;
	char			*in_out;
}					t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_token
{
	char	*data;
	struct	s_token	*prev;
	struct	s_token	*next;
}	t_token;

void				shell_loop(t_cmd *str, char **env, t_env *env_list);
void				quote_count(t_cmd *str);
void				cmd_check(t_cmd *str, t_env *env_list);
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
char				*get_env_value(t_env *env_list, char *key);
int					ft_strcmp( char *s1, char *s2);
void				ft_pwd(t_cmd *str);
void				handle_dollar(t_cmd *str, t_env *env_list);
int					array_in_dollar(char *s);
int					dollar_between_quotes(char *s);
void				redirect(t_cmd *str);
int					array_in_redirect(char *s);
void				get_redirect_name(char	**str);
void				take_name_file(char *s, int x);
void				choose_str(t_cmd *str);
char				*swap_command(char *dest, t_cmd *str);
void				print_cmd(t_cmd *str);
int					in_quote_check(char	*s);
void				delete_dollar_value(t_cmd	*str);
char				*dollar_in_dquote(char	*str);
void				dollar_case(t_cmd *str, t_env *env_list);
#endif

