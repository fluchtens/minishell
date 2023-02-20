/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:04:10 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/18 15:42:31 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_new;
	char const	*src_new;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	dst_new = (char *)dst;
	src_new = (char const *)src;
	i = 0;
	while (i < n)
	{
		dst_new[i] = src_new[i];
		i++;
	}
	return (dst);
}
