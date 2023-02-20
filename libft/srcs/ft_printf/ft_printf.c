/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:02:41 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/19 11:20:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list ap, char c, int len)
{
	if (c == 'c')
		len = print_char(va_arg(ap, int));
	else if (c == 's')
		len = print_str(va_arg(ap, char *));
	else if (c == 'p')
		len = print_ptr(va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		len = print_nbr(va_arg(ap, int));
	else if (c == 'u')
		len = print_unbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		len = print_nbr_base(va_arg(ap, unsigned int), HEXA_LOWER);
	else if (c == 'X')
		len = print_nbr_base(va_arg(ap, unsigned int), HEXA_UPPER);
	else if (c == '%')
		len = print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] != '%')
			len += print_char(str[i]);
		else if (str[i] == '%')
		{
			i++;
			len += print_format(ap, str[i], len);
		}
	}
	va_end(ap);
	return (len);
}
