/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/20 09:00:40 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

int	print_shell_error(char *str, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	reset_data(data);
	return (1);
}
