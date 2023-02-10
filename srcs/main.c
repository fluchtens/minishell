/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/10 08:34:29 by fluchten         ###   ########.fr       */
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
