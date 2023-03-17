/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:16:07 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/17 17:16:36 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str, int *invalid)
{
	size_t	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	(*invalid) = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
				sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if ((sign < 0 && res > (size_t)LONG_MAX + 1) \
		|| (sign > 0 && res > LONG_MAX))
		{
			(*invalid) = 1;
			return (0);
		}
	}
	return ((long)(sign * res));
}
