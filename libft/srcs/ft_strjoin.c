/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:26:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/08 10:07:03 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	if (s1)
		ft_strlcpy(final, s1, len + 1);
	if (s2)
		ft_strlcat(final, s2, len + 1);
	return (final);
}
