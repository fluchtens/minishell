/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:06:05 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/17 07:37:56 by mgomes-d         ###   ########.fr       */
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

static int	stop_here_doc(char *line, char *stop)
{
	int	linelen;
	int	stoplen;
	int	len;

	if (!stop || !line)
		return (1);
	linelen = ft_strlen(line);
	stoplen = ft_strlen(stop);
	if (linelen < stoplen)
		len = stoplen;
	else
		len = linelen;
	if (ft_strncmp(line, stop, len) == 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

static int	here_doc(t_data *data, char *stop_hd, char *file, char *hd_str)
{
	char	*line;
	int		fd;

	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (true)
	{
		line = readline(MSG_HEREDOC);
		if (stop_here_doc(line, stop_hd))
			break ;
		if (ft_have_quotes(hd_str))
			line = ft_expander_heredoc(&line, data);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (EXIT_SUCCESS);
}

void	heredoc_init(t_data *data, t_cmds *cmd, t_lexer *redirection)
{
	char	*stop_heredoc;

	init_signals(0);
	while (redirection)
	{
		if (redirection->token == LESS_LESS)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = filename(data);
			stop_heredoc = ft_remove_quotes(redirection->str);
			data->heredoc = true;
			if (here_doc(data, stop_heredoc, cmd->hd_file_name,\
			 redirection->str))
			{
				g_ret_value = 1;
				reset_data(data);
				return ;
			}
		}
		redirection = redirection->next;
	}
	init_signals(1);
	return ;
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
