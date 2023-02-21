/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:40 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/18 15:42:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	search;
	size_t	i;

	str = (char *)s;
	search = (char)c;
	i = 0;
	while (str[i] && str[i] != search)
		i++;
	if (str[i] == search)
		return ((char *)&str[i]);
	return (NULL);
}
