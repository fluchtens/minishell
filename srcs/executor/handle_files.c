/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:05:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/08 10:27:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	infile(char *infilename)
{
	int	fd;

	fd = open(infilename, O_RDONLY);
	if (fd == -1)
	{
		perror(infilename);
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	outfile(char *outfile, bool type)
{
	int	fd;

	if (type)
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(outfile);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_files(t_lexer *redirections, t_cmds *cmd)
{
	int	result;

	result = 0;
	while (redirections)
	{
		if (redirections->token == LESS)
			result = infile(redirections->str);
		else if (redirections->token == LESS_LESS)
			result = infile(cmd->hd_file_name);
		else if (redirections->token == GREAT)
			result = outfile(redirections->str, 0);
		else if (redirections->token == GREAT_GREAT)
			result = outfile(redirections->str, 1);
		if (result)
			return (1);
		redirections = redirections->next;
	}
	return (0);
}
