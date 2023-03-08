/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:05:20 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/08 11:57:10 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_execve(char **cmd, char *path, char **env)
{
	if (!access(cmd[0], X_OK))
		return (1);
	if (execve(path, cmd, env) == -1)
		return (1);
	return (0);
}

static int	not_cmd(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	if (errno == 14)
		ft_putendl_fd(": command not found", 2);
	else if (errno == 22)
		ft_putendl_fd(": No such file or directory", 2);
	return (127);
}

int	execution(t_data *data, t_cmds *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	paths = data->paths;
	i = 0;
	if (paths[0])
	{
		while (paths[i++])
		{
			path = ft_strjoin(paths[i], cmd->str[0]);
			if (!access(path, F_OK))
				ft_execve(cmd->str, path, data->envp);
			free(path);
		}	
	}
	return (not_cmd(cmd->str[0]));
}

static void	ft_waitpid(int *pid, int pipes)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipes)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
	return ;
}

int	execute_multiple_cmd(t_data *data)
{
	int		pipefd[2];
	int		fd_in;
	t_cmds	*cmds;

	fd_in = STDIN_FILENO;
	cmds = data->cmds;
	while (cmds)
	{
		if (cmds->next)
			pipe(pipefd);
		cmds->str = expander(data, cmds->str);
		heredoc_init(data, data->cmds, data->cmds->redirections);
		process(data, pipefd, fd_in, cmds);
		close(pipefd[1]);
		if (data->cmds->prev)
			close(fd_in);
		fd_in = heredoc_ver(data, pipefd, cmds->hd_file_name);
		if (cmds->next)
			cmds = cmds->next;
		else
			break ;
	}
	ft_waitpid(data->pid, data->pipes_count);
	return (0);
}
