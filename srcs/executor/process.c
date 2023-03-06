/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:06:43 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/06 11:37:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_child_process(t_data *data, t_cmds *cmd)
{
	int	result;

	result = 0;
	if (cmd->redirections)
		if (ft_handle_files(cmd->redirections, cmd))
			exit(1);
	if (cmd->builtin)
	{
		result = cmd->builtin(data, cmd);
	}
	else if (cmd->str[0][0])
		result = ft_execution(data, cmd);
	exit(result);
}

void	ft_one_cmd(t_data *data, t_cmds *cmd)
{
	int	pid;
	int	ret;

	if (cmd->builtin == ft_cd || cmd->builtin == ft_exit \
	|| cmd->builtin == ft_export || cmd->builtin == ft_unset)
	{
		g_global.error_num = cmd->builtin(data, cmd);
		return ;
	}
	ft_heredoc_init(data, cmd, cmd->redirections);
	pid = fork();
	if (pid < 0)
		print_error("pid error", data);
	if (pid == 0)
		ft_child_process(data, cmd);
	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret))
		g_global.error_num = WEXITSTATUS(ret);
}

static void	ft_child_init(t_data *data, t_cmds *cmd, int fd_in, int pipefd[2])
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		print_error("Failed to create pipe\n", data);
	close(pipefd[0]);
	if (cmd->next && dup2(pipefd[1], STDOUT_FILENO) < 0)
		print_error("Failed to create pipe\n", data);
	close(pipefd[1]);
	if (cmd->prev)
		close(fd_in);
	ft_child_process(data, cmd);
}

int	ft_process(t_data *data, int pipefd[2], int fd_in, t_cmds *cmd)
{
	if (data->reset == true)
	{
		data->pidindex = 0;
		data->reset = false;
	}
	data->pid[data->pidindex] = fork();
	if (data->pid[data->pidindex] < 0)
		print_error("Failed to fork\n", data);
	if (data->pid[data->pidindex] == 0)
		ft_child_init(data, cmd, fd_in, pipefd);
	data->pidindex++;
	return (EXIT_SUCCESS);
}
