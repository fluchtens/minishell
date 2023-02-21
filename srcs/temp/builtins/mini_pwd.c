#include "minishell.h"

int	mini_pwd(t_data *data, t_simple_cmds *simple_cmd)
{
	(void) simple_cmd;
	ft_putendl_fd(data->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
