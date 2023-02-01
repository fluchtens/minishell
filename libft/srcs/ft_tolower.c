/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:24 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:04:16 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* int	main(void)
{
	printf("%d\n", tolower('a'));
	printf("%d\n", ft_tolower('a'));
	printf("%d\n", tolower('A'));
	printf("%d\n", ft_tolower('A'));
} */