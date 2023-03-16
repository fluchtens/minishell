/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_closed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/16 08:09:27 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_closed_quotes(char *str)
{
	int		len;
	int		top;
	bool	result;
	char	*stack;
	int		i;

	len = ft_strlen(str);
	stack = malloc(sizeof(char) * len);
	if (!stack)
		return (0);
	i = 0;
	top = -1;
	while (i++ < len)
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (top >= 0 && stack[top] == str[i])
				top--;
			else
				stack[++top] = str[i];
		}
	}
	result = (top == -1);
	free(stack);
	return (result);
}
