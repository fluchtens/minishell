/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/18 15:42:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_new;
	const char	*src_new;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	dst_new = (char *)dst;
	src_new = (char const *)src;
	if (src_new < dst_new)
	{
		i = 0;
		while (++i <= len)
			dst_new[len - i] = src_new[len - i];
	}
	else
	{
		i = -1;
		while (++i < len)
			dst_new[i] = src_new[i];
	}
	return (dst);
}
