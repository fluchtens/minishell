/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:15:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 07:43:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* int	main(void)
{
	printf("%d\n", ft_isprint(32));
	printf("%d\n", ft_isprint(126));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", ft_isprint(5));
} */