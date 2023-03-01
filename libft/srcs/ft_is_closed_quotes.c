/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_closed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/01 13:35:02 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_closed_quotes(char *str)
{
	int	s_quotes_count;
	int	d_quotes_count;
	int	i;

	s_quotes_count = 0;
	d_quotes_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			s_quotes_count++;
		if (str[i] == 34)
			d_quotes_count++;
		i++;
	}
	return ((s_quotes_count % 2 == 0) && (d_quotes_count % 2 == 0));
}
