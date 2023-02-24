/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 07:54:02 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *str, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	reset_data(data);
	return (1);
}

int	print_token_error(t_data *data, t_lexer *lexer, t_tokens token)
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
	ft_putstr_fd("\n", 2);
	lexer_clear(&lexer);
	reset_data(data);
	return (1);
}

int	print_parser_error(char *str, t_data *data, t_lexer *lexer)
{
	lexer_clear(&lexer);
	return (print_error(str, data));
}

int	print_unknown_cmd_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (127);
}

int	print_export_error(char *c)
{
	ft_putstr_fd("minishell: export: ", 2);
	if (c)
	{
		ft_putchar_fd('\'', 2);
		ft_putstr_fd(c, 2);
		ft_putstr_fd("\': is ", 2);
	}
	ft_putendl_fd("not a valid identifier", 2);
	return (EXIT_FAILURE);
}
