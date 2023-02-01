/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:27:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 07:42:58 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

/* int main(void)
{
	int nb;
	int *tab;
	int i;

	nb = 5;
	tab = ft_calloc(nb, sizeof(int));
	i = 0;
	while (i < nb)
	{
		printf("[%d] ", tab[i]);
		i++;
	}
} */