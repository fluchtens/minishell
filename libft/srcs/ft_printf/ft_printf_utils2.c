/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:14:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/19 11:20:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_base(unsigned long nb, char *base)
{
	int	res;

	res = 0;
	if (nb >= 16)
		res += print_nbr_base(nb / 16, base);
	res += print_char(base[nb % 16]);
	return (res);
}

int	print_ptr(unsigned long nb)
{
	int	res;

	write(1, "0x", 2);
	res = print_nbr_base(nb, HEXA_LOWER);
	return (res + 2);
}
