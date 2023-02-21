#include "minishell.h"

int	mini_env(t_data *data, t_simple_cmds *simple_cmd)
{
	int		i;

	(void) simple_cmd;
	i = 0;
	while (data->envp[i])
	{
		ft_putendl_fd(data->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
