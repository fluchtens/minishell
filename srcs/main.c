/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/08 09:14:19 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	int i = 0;
	while (i < 8)
	{
		data.line = readline("minishell$ ");
		if (ft_strncmp(data.line, "hello", 5) == 0)
		{
			printf("hello44\n");
			continue;
			printf("nothere\n");
		}
		if (!data.line)
		{
			printf("exit\n");
			exit(0);
		}
		i++;
	}
}
