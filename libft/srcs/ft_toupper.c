/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:04:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int	main(void)
{
	printf("%d\n", toupper('A'));
	printf("%d\n", ft_toupper('A'));
    printf("%d\n", toupper('a'));
	printf("%d\n", ft_toupper('a'));
} */