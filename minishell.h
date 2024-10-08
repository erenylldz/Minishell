/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:42 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/03 19:42:12 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0
# define BUILTIN 9
# define HEREDOC 10
# define APPEND 11
# define INPUT 12
# define OUTPUT 13
# define C_PROCESS 101
# define M_PROCESS 100
# define HEREDOC_PROECESS 102
typedef struct s_cmd
{
	char			*cmd;
	char			**ncmd;
	char			***command;
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
	pid_t			pid;
}					t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_redirect
{
	int		type;
	int		location;
	char	*data;
	struct	s_redirect	*prev;
	struct	s_redirect	*next;
}	t_redirect;

extern int	g_globals_exit;

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
void				get_redirect_name(t_cmd *str, int i, int j);
t_redirect 			*take_name_file(const char *s, int x, int loc);
void				choose_str(t_cmd *str);
char				*swap_command(char *dest, t_cmd *str);
void				print_cmd(t_cmd *str);
int					in_quote_check(char	*s);
char				*delete_dollar_value(char *array);
char				*dollar_in_dquote(char	*str);
void				dollar_case(t_cmd *str, t_env *env_list);
int					count_quotes(char *str);
char				*find_start_in_quotes(char *str);
char				*find_dollar_in_quotes(char *str);
char				*copy_acceptable_chars(char *start);
int					key_end_index(char *s);
int					after_key_chars_number(char *s, int idx);
int					find_dollar_index(char *s);
char				*overwrite_value(char *array, char	*value);
char				*dollar_not_dquote(char *str);
int					find_dollar_in_quotes_idx(char *str);
void				delete_redirect_value(t_cmd *str, int i, int j);
int					is_only_redirection_symbols(char *array);
void				not_dquote_process(t_cmd *str, t_env *env_list, int i, int j);
void				in_dquote_process(t_cmd *str, t_env *env_list, int i, int j);
bool				is_outside_quotes(const char *str);
void				delete_only_redirect(t_cmd *str, int i, int j);
int					redirect_array_idx(char	*str);
int					redirection_type(char *array);
int					skip_redirection(char *array, int i);
char				*copy_after_redirection(char *array);
char				*copy_chars_next_array(char *str);
#endif

