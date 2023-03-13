/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/13 12:19:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_data *data, t_cmds *cmds)
{
	char	*temp;

	(void) data;
	(void) cmds;
	temp = getcwd(NULL, sizeof(NULL));
	ft_putendl_fd(temp, 1);
	free(temp);
	return (0);
}
