/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 07:49:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/15 07:47:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reset_datas(t_data *data)
{
	if (data->line)
		free(data->line);
	if (data->paths)
		free_array(data->paths);
}

static void	init_minishell(t_data *data)
{
	char	*temp;

	data->line = readline("minisell$ ");
	temp = ft_strtrim(data->line, " ");
	free(data->line);
	data->line = temp;
	if (!data->line)
		exit_and_free(data, "exit", 0);
	add_history(data->line);
	reset_datas(data);
}

void	init_everything(t_data *data)
{
	if (!parse_paths(data))
		exit_and_free(data, "Error: paths parsing failed.", 1);
	if (!parse_pwd(data))
		exit_and_free(data, "Error: pwd parsing failed.", 1);
	init_minishell(data);
}
