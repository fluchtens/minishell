/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:41:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/14 12:00:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_envp(char **envp)
{
	char	**final;
	size_t	len;
	size_t	i;

	len = 0;
	while (envp[len])
		len++;
	final = malloc(sizeof(char *) * (len + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		final[i] = ft_strdup(envp[i]);
		if (!final[i])
		{
			free_array(final);
			return (NULL);
		}
		i++;
	}
	return (final);
}
