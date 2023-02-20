/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:02:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/19 11:20:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	print_nbr(int nb)
{
	long	n;
	int		len;

	len = 0;
	n = (long)nb;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += print_nbr(n / 10);
		len += print_nbr(n % 10);
	}
	else
		len += print_char(n + 48);
	return (len);
}

int	print_unbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += print_nbr(nb / 10);
		len += print_nbr(nb % 10);
	}
	else
		len += print_char(nb + 48);
	return (len);
}
