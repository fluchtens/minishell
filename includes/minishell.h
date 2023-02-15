/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/15 07:49:51 by fluchten         ###   ########.fr       */
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
	char	*pwd;
	char	*old_pwd;
}	t_data;

/* init */
void	init_everything(t_data *data);
/* parsing */
char	**parse_envp(char **arr);
int		parse_paths(t_data *data);
int		parse_pwd(t_data *data);
/* utils */
int		print_error(char *str);
void	exit_and_free(t_data *data, char *str, int error);
void	free_everything(t_data *data);
void	free_array(char **array);

#endif