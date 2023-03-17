/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:06:43 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/17 06:58:25 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_data *data, t_cmds *cmd)
{
	int	code;

	code = 0;
	if (cmd->redirections)
		if (handle_files(cmd->redirections, cmd))
			exit(1);
	if (cmd->builtin)
		code = cmd->builtin(data, cmd);
	else if (cmd->str[0])
		code = execution(data, cmd);
	exit(code);
}

static void	child_init(t_data *data, t_cmds *cmd, int fd_in, int pipefd[2])
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		print_error(ERR_DUP2, data);
	close(pipefd[0]);
	if (cmd->next && dup2(pipefd[1], STDOUT_FILENO) < 0)
		print_error(ERR_DUP2, data);
	close(pipefd[1]);
	if (cmd->prev)
		close(fd_in);
	child_process(data, cmd);
}

void	process(t_data *data, int pipefd[2], int fd_in, t_cmds *cmd)
{
	data->pid[data->pidindex] = fork();
	if (data->pid[data->pidindex] < 0)
		print_error(ERR_FORK, data);
	if (data->pid[data->pidindex] == 0)
		child_init(data, cmd, fd_in, pipefd);
	data->pidindex++;
	return ;
}
