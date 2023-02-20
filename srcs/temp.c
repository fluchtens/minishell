/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:32:40 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/20 08:18:02 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(t_data *data)
{
    t_lexer *current = data->lexer;

    while (current)
    {
        printf("[%d] = %s -> [%d]\n", current->i, current->str, current->token);
        current = current->next;
    }
}
