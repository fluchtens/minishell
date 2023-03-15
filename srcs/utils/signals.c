/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:04:51 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/15 11:56:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint_handler(int sig)
{
	(void) sig;
	if (!g_global.in_heredoc)
		ft_putchar_fd('\n', 2);
	if (g_global.in_cmd)
	{
		g_global.stop_heredoc = 1;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;
	}
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	sigquit_handler(int sig)
{
	ft_putstr_fd("Quit: ", 2);
	ft_putnbr_fd(sig, 2);
	ft_putchar_fd('\n', 2);
}

void	init_signals(int value)
{
	if (value == 0)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	if (value == 1)
		signal(SIGQUIT, sigquit_handler);
}
