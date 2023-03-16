/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:04:51 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/16 10:17:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reset_handler(int sig)
{
	(void) sig;
	g_error_num = 1;
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	ctrl_c_handler(int sig)
{
	(void) sig;
	g_error_num = 130;
	ft_putendl_fd("^C", 1);
}

static void	back_slash_handler(int sig)
{
	g_error_num = 131;
	ft_putstr_fd("Quit: ", 1);
	ft_putnbr_fd(sig, 1);
	ft_putchar_fd('\n', 1);
}

void	init_signals(int value)
{
	struct termios	term;

	if (value == 0)
	{
		signal(SIGINT, reset_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	if (value == 1)
	{
		signal(SIGINT, ctrl_c_handler);
		signal(SIGQUIT, back_slash_handler);
	}
	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}
