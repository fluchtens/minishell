/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:14:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 07:41:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max_size(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;
	int		count;

	res = 0;
	sign = 1;
	i = 0;
	count = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
				sign = -1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if (count++ > 19 || res < 0)
			return (max_size(sign));
	}
	return (sign * (int)res);
}

/* int main()
{
	printf("0 ft %d\n",ft_atoi("0"));
	printf("0    %d\n",atoi("0"));
	printf("+ ft %d\n",ft_atoi("+300"));
	printf("+    %d\n",atoi("+300"));
	printf("- ft %d\n",ft_atoi("-300"));
	printf("-    %d\n",atoi("-300"));
	printf("-+ ft %d\n",ft_atoi("-+2147483"));
	printf("-+    %d\n",atoi("-+2147483"));
	printf("-- ft %d\n",ft_atoi("--300"));
	printf("--    %d\n",atoi("--300"));
	printf("INT MAX ft %d\n",ft_atoi("2147483647"));
	printf("INT MAX    %d\n",atoi("2147483647"));
	printf("INT MIN ft %d\n",ft_atoi("-2147483648"));
	printf("INT MIN    %d\n",atoi("-2147483648"));
	printf("INT OVER ft %d\n",ft_atoi("30000000000"));
	printf("INT OVER    %d\n",atoi("30000000000"));
	printf("-INT OVER ft %d\n",ft_atoi("-30000000000"));
	printf("-INT OVER    %d\n",atoi("-30000000000"));
	printf("+LONG ft %d\n",ft_atoi("9223372036854775807"));
	printf("+LONG    %d\n",atoi("9223372036854775807"));
	printf("-LONG ft %d\n",ft_atoi("-9223372036854775808"));
	printf("-LONG    %d\n",atoi("-9223372036854775808"));
	printf("LONG OVER ft %d\n",ft_atoi("44444119223372036854775807"));
	printf("LONG OVER    %d\n",atoi("44444119223372036854775807"));
	printf("-LONG OVER ft %d\n",ft_atoi("-1000000000000000000000"));
	printf("-LONG OVER    %d\n",atoi("-1000000000000000000000"));
	printf("UNSIGNED LONG MAX ft %d\n",ft_atoi("18446744073709551615"));
	printf("UNSIGNED LONG MAX    %d\n",atoi("18446744073709551615"));
	printf("-UNSIGNED LONG MAX ft %d\n",ft_atoi("-18446744073709551615"));
	printf("-UNSIGNED LONG MAX    %d\n",atoi("-18446744073709551615"));
	printf("UNSIGNED LONG OVER ft %d\n",ft_atoi("10000000000000000"));
	printf("UNSIGNED LONG OVER    %d\n",atoi("10000000000000000"));
	printf("-UNSIGNED LONG OVER ft %d\n",ft_atoi("-30000000000000000"));
	printf("-UNSIGNED LONG OVER    %d\n",atoi("-30000000000000000"));
	printf("ulongover1 ft %d\n",ft_atoi("18446744073709551616"));
	printf("ulongover1    %d\n",atoi("18446744073709551616"));
	printf("ulongover2 ft %d\n",ft_atoi("18446744073709551617"));
	printf("ulongover2    %d\n",atoi("18446744073709551617"));
	printf("ulongover3 ft %d\n",ft_atoi("18446744073709551618"));
	printf("ulongover3    %d\n",atoi("18446744073709551618"));
	printf("ulongover4 ft %d\n",ft_atoi("18446744073709551619"));
	printf("ulongover4    %d\n",atoi("18446744073709551619"));
} */