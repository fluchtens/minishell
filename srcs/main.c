/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 13:35:40 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(t_data *data)
{
	char	*temp;

	while (1)
	{
		data->line = readline(MSG_READLINE);
		temp = ft_strtrim(data->line, " ");
		free(data->line);
		data->line = temp;
		if (!data->line)
			exit_minishell(data);
		if (!data->line[0])
			reset_data(data);
		if (!ft_is_closed_quotes(data->line))
			print_error(MSG_QUOTES_ERR, data);
		if (!init_lexer(data))
			print_error(MSG_MALLOC_ERR, data);
		parser(data);
		prepare_executor(data);
		reset_data(data);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	if (!parse_envp(&data, envp))
	{
		ft_putstr_fd("error: envp parsing error", 2);
		return (1);
	}
	if (!parse_pwd(&data))
	{
		ft_putstr_fd("error: pwd parsing error", 2);
		free(data.envp);
		return (1);
	}
	initialization(&data);
	loop(&data);
	return (0);
}
