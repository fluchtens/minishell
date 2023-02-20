/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:23:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/19 16:09:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_lexer(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->line[i])
	{
		j = 0;
		if (ft_iswhitespace(data->line[i]))
			i++;
		if (is_token(data->line[i]))
			j = read_token(data->line, i, &data->lexer);
		else
			j = read_string(data->line, i, &data->lexer);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
