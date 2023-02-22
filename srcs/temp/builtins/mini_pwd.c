/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/21 12:22:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_pwd(t_data *data, t_cmds *cmds)
{
	(void) cmds;
	ft_putendl_fd(data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
