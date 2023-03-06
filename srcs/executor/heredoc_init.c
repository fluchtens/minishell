/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:06:05 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/06 14:00:45 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*filename(t_data *data)
{
	char	*file;
	char	*index;

	data->heredocindex = 0;
	index = ft_itoa(data->heredocindex++);
	file = ft_strjoin("/tmp/.tempfile.", index);
	free(index);
	return (file);
}

static int	hd_stoplen(char *line, char *stop)
{
	int	linelen;
	int	stoplen;

	linelen = ft_strlen(line);
	stoplen = ft_strlen(stop);
	if (linelen < stoplen)
		return (stoplen);
	return (linelen);
}

static int	here_doc(t_data *data, char *stop_heredoc, char *file)
{
	char	*line;
	int		fd;

	(void)data;
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (true)
	{
		line = readline(MSG_HEREDOC);
		if (ft_strncmp(line, stop_heredoc, \
			hd_stoplen(line, stop_heredoc)) == 0 || g_global.stop_heredoc)
		{
			free(line);
			free(stop_heredoc);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (g_global.stop_heredoc)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	heredoc_init(t_data *data, t_cmds *cmd, t_lexer *redirection)
{
	char	*stop_heredoc;

	while (redirection)
	{
		if (redirection->token == LESS_LESS)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = filename(data);
			stop_heredoc = ft_remove_quotes(redirection->str);
			g_global.stop_heredoc = 0;
			g_global.in_heredoc = 1;
			data->heredoc = true;
			if (here_doc(data, stop_heredoc, cmd->hd_file_name))
			{
				g_global.error_num = 1;
				reset_data(data);
				return (1);
			}
		}
		redirection = redirection->next;
	}
	return (EXIT_SUCCESS);
}

int	heredoc_ver(t_data *data, int pipefd[2], char *filename)
{
	int	fd;

	if (data->heredoc)
	{
		close(pipefd[0]);
		fd = open(filename, O_RDONLY);
	}
	else
		fd = pipefd[0];
	return (fd);
}
