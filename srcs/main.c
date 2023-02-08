/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/08 10:50:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_lexer	*list;
	int		i;

	(void)ac;
	(void)av;
	i = 0;
	while (i < 1)
	{
		data.line = readline("minishell$ ");
		list = parser(ft_split(data.line, ' '));
		print_list(list);
		i++;
	}
}
