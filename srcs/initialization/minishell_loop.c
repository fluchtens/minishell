/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:58 by fpolycar          #+#    #+#             */
/*   Updated: 2023/02/20 08:57:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_data(t_data *data)
{
	free(data->line);
	free_array(data->paths);
	initialization(data);
	minishell_loop(data);
	return (1);
}

int	minishell_loop(t_data *data)
{
	char	*temp;

	data->line = readline("minisell$ ");
	temp = ft_strtrim(data->line, " ");
	free(data->line);
	data->line = temp;
	if (!data->line)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!data->line[0])
		return (reset_data(data));
	add_history(data->line);
	if (!ft_is_closed_quotes(data->line))
		return (print_shell_error("quotes are not closed\n", data));
	if (!init_lexer(data))
		return (print_shell_error("lexer allocation failure\n", data));
	print_lexer(data);
	reset_data(data);
	return (1);
}
