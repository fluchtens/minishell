/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:17:39 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 08:00:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(t_cmds *cmd, t_data *data)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, data->envp);
	while (data->paths[i])
	{
		mycmd = ft_strjoin(data->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->str, data->envp);
		free(mycmd);
		i++;
	}
	return (print_unknown_cmd_error(cmd->str[0]));
}

void	handle_cmd(t_cmds *cmd, t_data *data)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(data, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, data);
	exit(exit_code);
}

void	dup_cmd(t_cmds *cmd, t_data *data, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		print_error(MSG_PIPE_ERR, data);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		print_error(MSG_PIPE_ERR, data);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, data);
}

void	single_cmd(t_cmds *cmd, t_data *data)
{
	int	pid;
	int	status;

	data->cmds = call_expander(data, data->cmds);
	if (cmd->builtin == mini_cd || cmd->builtin == mini_exit
		|| cmd->builtin == mini_export || cmd->builtin == mini_unset)
	{
		g_global.error_num = cmd->builtin(data, cmd);
		return ;
	}
	send_heredoc(data, cmd);
	pid = fork();
	if (pid < 0)
		print_error(MSG_FORK_ERR, data);
	if (pid == 0)
		handle_cmd(cmd, data);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}
