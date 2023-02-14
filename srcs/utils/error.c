/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/14 11:50:46 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

void	exit_and_free(t_data *data, char *str, int error)
{
	free_everything(data);
	if (error == 1)
	{
		ft_putendl_fd(str, 2);
		exit(EXIT_FAILURE);
	}
	else if (error == 0)
	{
		ft_putendl_fd(str, 1);
		exit(EXIT_SUCCESS);
	}
}
