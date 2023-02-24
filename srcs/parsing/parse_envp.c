/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:49:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 09:49:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_envp(t_data *data, char **envp)
{
	data->envp = ft_array_dup(envp);
	if (!data->envp)
		return (0);
	return (1);
}
