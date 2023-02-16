/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:09:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/15 08:36:37 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_quote_check(t_data *data, char c)
{
	if (c == '"' && data->quote.sing == 0 && data->quote.doub == 0)
		data->quote.doub = 1;
	else if (c == '"' && data->quote.doub == 1)
		data->quote.doub = 0;
	if (c == '\'' && data->quote.sing == 0 && data->quote.doub == 0)
		data->quote.sing = 1;
	else if (c == '\'' && data->quote.sing == 1)
		data->quote.sing = 0;
	if (data->quote.doub == 1 || data->quote.sing == 1)
		return (1);
	return (0);
}
