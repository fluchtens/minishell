/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:21:43 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/17 08:00:04 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_one_cmd(t_data *data, t_cmds *cmd)
{
	int	pid;
	int	status;

	init_expander(data, cmd);
	if (cmd->builtin == ft_cd || cmd->builtin == ft_exit \
	|| cmd->builtin == ft_export || cmd->builtin == ft_unset)
	{
		g_ret_value = cmd->builtin(data, cmd);
		return ;
	}
	heredoc_init(data, cmd, cmd->redirections);
	pid = fork();
	if (pid == -1)
		print_error(ERR_FORK, data);
	if (pid == 0)
		child_process(data, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_ret_value = WEXITSTATUS(status);
}
