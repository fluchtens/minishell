/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 07:49:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/13 08:15:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_everything(t_data *data)
{
	if (!parse_envp(data))
		return (0);
	data->line = readline("minishell$ ");
	return (1);
}
