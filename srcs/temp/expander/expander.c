/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:17:51 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/23 15:36:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	loop_if_dollar_sign(t_data *data, char *str, char **tmp, int j)
{
	int		k;
	int		ret;
	char	*tmp2;
	char	*tmp3;

	k = 0;
	ret = 0;
	while (data->envp[k])
	{
		if (ft_strncmp(str + j + 1, data->envp[k],
				equal_sign(data->envp[k]) - 1) == 0
			&& after_dol_lenght(str, j) - j == (int)equal_sign(data->envp[k]))
		{
			tmp2 = ft_strdup(data->envp[k] + equal_sign(data->envp[k]));
			tmp3 = ft_strjoin(*tmp, tmp2);
			free(*tmp);
			*tmp = tmp3;
			free(tmp2);
			ret = equal_sign(data->envp[k]);
		}
		k++;
	}
	if (ret == 0)
		ret = after_dol_lenght(str, j) - j;
	return (ret);
}

static int	handle_digit_after_dollar(int j, char *str)
{
	int	i;

	i = j;
	if (str[j] == '$')
	{
		if (ft_isdigit(str[j + 1]) == 1)
		{
			j += 2;
		}
	}
	return (j - i);
}

static char	*detect_dollar_sign(t_data *data, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = 0;
	tmp = ft_strdup("\0");
	while (str[j])
	{
		j += handle_digit_after_dollar(j, str);
		if (str[j] == '$' && str[j + 1] == '?')
			j += question_mark(&tmp);
		else if (str[j] == '$' && (str[j + 1] != ' ' && (str[j + 1] != '"'
					|| str[j + 2] != '\0')) && str[j + 1] != '\0')
			j += loop_if_dollar_sign(data, str, &tmp, j);
		else
		{
			tmp2 = char_to_str(str[j++]);
			tmp3 = ft_strjoin(tmp, tmp2);
			free(tmp);
			tmp = tmp3;
			free(tmp2);
		}
	}
	return (tmp);
}

char	**expander(t_data *data, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i] != NULL)
	{
		if (str[i][dollar_sign(str[i]) - 2] != '\'' && dollar_sign(str[i]) != 0
			&& str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = detect_dollar_sign(data, str[i]);
			free(str[i]);
			str[i] = tmp;
		}
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			str[i] = delete_quotes(str[i], '\"');
			str[i] = delete_quotes(str[i], '\'');
		}
		i++;
	}
	return (str);
}

char	*expander_str(t_data *data, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (str[dollar_sign(str) - 2] != '\'' && dollar_sign(str) != 0
		&& str[dollar_sign(str)] != '\0')
	{
		tmp = detect_dollar_sign(data, str);
		free(str);
		str = tmp;
	}
	str = delete_quotes(str, '\"');
	str = delete_quotes(str, '\'');
	return (str);
}
