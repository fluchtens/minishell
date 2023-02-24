/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:35:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 07:53:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_last(t_lexer *lexer)
{
	t_lexer	*last;

	if (!lexer)
		return (NULL);
	last = lexer;
	while (last->next)
		last = last->next;
	return (last);
}
