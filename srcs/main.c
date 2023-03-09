/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 08:12:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(t_data *data)
{
	while (1)
	{
		data->line = readline(MSG_READLINE);
		if (!data->line)
			exit_loop(data);
		if (!data->line[0])
		{
			reset_data(data);
			continue ;
		}
		add_history(data->line);
		if (!ft_is_closed_quotes(data->line))
			print_error(ERR_QUOTES, data);
		init_lexer(data);
		init_parser(data);
		init_executor(data);
		reset_data(data);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	if (!parse_envp(&data, envp))
		return (ft_print_error(ERR_ENVP));
	if (!parse_pwd(&data))
	{
		free_array(data.envp);
		return (ft_print_error(ERR_PWD));
	}
	initialization(&data);
	loop(&data);
	return (0);
}
