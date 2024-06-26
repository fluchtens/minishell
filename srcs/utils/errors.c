/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 14:19:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(str, 2);
	reset_data(data);
	loop(data);
}

void	print_token_error(t_data *data, t_lexer *lexer, t_tokens token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
	if (token == GREAT)
		ft_putstr_fd("'>'", 2);
	else if (token == GREAT_GREAT)
		ft_putstr_fd("'>>'", 2);
	else if (token == LESS)
		ft_putstr_fd("'<'", 2);
	else if (token == LESS_LESS)
		ft_putstr_fd("'<<'", 2);
	else if (token == PIPE)
		ft_putstr_fd("'|'", 2);
	ft_putchar_fd('\n', 2);
	lexer_clear(&lexer);
	reset_data(data);
	loop(data);
}

void	print_parser_error(char *str, t_data *data, t_lexer *lexer)
{
	lexer_clear(&lexer);
	print_error(str, data);
}
