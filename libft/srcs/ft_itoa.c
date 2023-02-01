/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:27:07 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:01:37 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits_length(int nb)
{
	size_t	len;

	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	write_string(long nb, char *str, int *i)
{
	if (nb > 9)
	{
		write_string(nb / 10, str, i);
		write_string(nb % 10, str, i);
	}
	else
	{
		str[*i] = nb + 48;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long		nb;
	int			len;
	int			i;

	nb = (long)n;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = digits_length(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
		i++;
	}
	write_string(nb, str, &i);
	str[i] = '\0';
	return (str);
}

/* int main(void)
{
	printf("%s\n", ft_itoa(-0));
	printf("%s\n\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-5));
	printf("%s\n\n", ft_itoa(5));
	printf("%s\n", ft_itoa(-19));
	printf("%s\n\n", ft_itoa(19));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-7826));
	printf("%s\n\n", ft_itoa(7826));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n\n", ft_itoa(2147483647));
} */