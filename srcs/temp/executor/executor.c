#include "minishell.h"

t_simple_cmds	*call_expander(t_data *data, t_simple_cmds *cmd)
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

int	ft_fork(t_data *data, int end[2], int fd_in, t_simple_cmds *cmd)
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

int	check_fd_heredoc(t_data *data, int end[2], t_simple_cmds *cmd)
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
	while (data->simple_cmds)
	{
		data->simple_cmds = call_expander(data, data->simple_cmds);
		if (data->simple_cmds->next)
			pipe(end);
		send_heredoc(data, data->simple_cmds);
		ft_fork(data, end, fd_in, data->simple_cmds);
		close(end[1]);
		if (data->simple_cmds->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(data, end, data->simple_cmds);
		if (data->simple_cmds->next)
			data->simple_cmds = data->simple_cmds->next;
		else
			break ;
	}
	pipe_wait(data->pid, data->pipes_count);
	data->simple_cmds = ft_simple_cmdsfirst(data->simple_cmds);
	return (0);
}
