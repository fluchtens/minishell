/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/09 11:21:48 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	//t_lexer	*list;
	int		i;

	(void)ac;
	(void)av;
	(void)env;
	i = 0;
	while (i < 1)
	{
		data.line = readline("minishell$ ");
		//list = parser(ft_split(data.line, ' '));
		parsing(&data);
		//print_list(list);
		i++;
	}
}
