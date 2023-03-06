/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:05:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/06 11:05:48 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	infile(char *infilename)
{
	int	fd;

	fd = open(infilename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\nici infile \n", 2);
		perror(infilename);
		return (EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
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
		ft_putstr_fd("\nici infil10101010e \n", 2);
		perror(outfile);
		return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_handle_files(t_lexer *redirections, t_cmds *cmd)
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
			return (EXIT_FAILURE);
		redirections = redirections->next;
	}
	return (EXIT_SUCCESS);
}
