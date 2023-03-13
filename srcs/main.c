/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/13 09:30:14 by fluchten         ###   ########.fr       */
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
	parse_pwd(&data);
	initialization(&data);
	loop(&data);
	return (0);
}
