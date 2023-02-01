/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:05 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 07:43:21 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* int	main(void)
{
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", ft_isascii('4'));
	printf("%d\n", ft_isascii('\n'));
} */