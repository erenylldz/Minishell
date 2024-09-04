/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:51:18 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/03 18:56:00 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_globals_exit = 130;
	}
}

void	heredoc_process(int status)
{
	if (status == SIGINT)
	{
		g_globals_exit = 999;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	set_signal(int c)
{
	if (c == M_PROCESS)
	{
		signal(SIGINT, &handle_signal);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (c == C_PROCESS)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (c == HEREDOC_PROECESS)
	{
		signal(SIGINT, &heredoc_process);
		signal(SIGQUIT, SIG_IGN);
	}
}
