/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:23:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 12:35:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_lexer(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	while (data->line[i])
	{
		len = 0;
		if (ft_iswhitespace(data->line[i]))
			i++;
		if (is_token(data->line[i]))
			len = read_token(data->line, i, &data->lexer);
		else
			len = read_string(data->line, i, &data->lexer);
		if (len < 0)
			return (0);
		i += len;
	}
	return (1);
}
