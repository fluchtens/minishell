/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:17:36 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/21 12:17:36 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*call_expander(t_data *data, t_cmds *cmd)
{
	t_lexer	*start;

	cmd->str = expander(data, cmd->str);
	start = cmd->redirections;
	while (cmd->redirections)
	{
		if (cmd->redirections->token != LESS_LESS)
			cmd->redirections->str
				= expander_str(data, cmd->redirections->str);
		cmd->redirections = cmd->redirections->next;
	}
	cmd->redirections = start;
	return (cmd);
}

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}

int	ft_fork(t_data *data, int end[2], int fd_in, t_cmds *cmd)
{
	static int	i = 0;

	if (data->reset == true)
	{
		i = 0;
		data->reset = false;
	}
	data->pid[i] = fork();
	if (data->pid[i] < 0)
		ft_error(5, data);
	if (data->pid[i] == 0)
		dup_cmd(cmd, data, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}

int	check_fd_heredoc(t_data *data, int end[2], t_cmds *cmd)
{
	int	fd_in;

	if (data->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}

int	executor(t_data *data)
{
	int		end[2];
	int		fd_in;

	fd_in = STDIN_FILENO;
	while (data->cmds)
	{
		data->cmds = call_expander(data, data->cmds);
		if (data->cmds->next)
			pipe(end);
		send_heredoc(data, data->cmds);
		ft_fork(data, end, fd_in, data->cmds);
		close(end[1]);
		if (data->cmds->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(data, end, data->cmds);
		if (data->cmds->next)
			data->cmds = data->cmds->next;
		else
			break ;
	}
	pipe_wait(data->pid, data->pipes_count);
	data->cmds = cmds_first(data->cmds);
	return (0);
}
