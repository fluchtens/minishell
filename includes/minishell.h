/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/13 11:54:03 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_data
{
	char	**envp;
	char	**paths;
	char	*line;
}	t_data;

/* init */
void	init_everything(t_data *data);
/* parsing */
int		parse_envp(t_data *data);
/* error */
int		print_error(char *str);
/* exit */
void	exit_error(t_data *data, char *str, int error);
/* utils */
void	free_arr(char **arr);
char	**ft_arrdup(char **arr);

#endif