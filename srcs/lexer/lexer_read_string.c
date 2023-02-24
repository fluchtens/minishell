/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:28:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/23 15:06:26 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	str_quotes_len(char *str, int i, char c)
{
	int	j;

	j = 0;
	if (str[i] == c)
	{
		j++;
		while (str[i + j] && str[i + j] != c)
			j++;
		if (str[i + j] == c)
			j++;
	}
	return (j);
}

int	read_string(char *str, int i, t_lexer **lexer)
{
	int	j;

	j = 0;
	while (str[i + j] && !is_token(str[i + j]))
	{
		j += str_quotes_len(str, i + j, 34);
		j += str_quotes_len(str, i + j, 39);
		if (ft_iswhitespace(str[i + j]))
			break ;
		j++;
	}
	if (!lexer_add_element(ft_substr(str, i, j), 0, lexer))
		return (-1);
	return (j);
}
