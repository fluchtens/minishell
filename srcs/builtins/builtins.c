/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:34 by fluchten          #+#    #+#             */
/*   Updated: 2024/06/06 09:50:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	(*get_builtin(char *str))(t_data *data, t_cmds *cmds)
{
	if (!str)
		return (NULL);
	else if (!ft_strcmp(str, "echo"))
		return (ft_echo);
	else if (!ft_strcmp(str, "cd"))
		return (ft_cd);
	else if (!ft_strcmp(str, "pwd"))
		return (ft_pwd);
	else if (!ft_strcmp(str, "export"))
		return (ft_export);
	else if (!ft_strcmp(str, "unset"))
		return (ft_unset);
	else if (!ft_strcmp(str, "env"))
		return (ft_env);
	else if (!ft_strcmp(str, "exit"))
		return (ft_exit);
	return (NULL);
}
