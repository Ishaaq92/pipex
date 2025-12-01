/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:59:29 by ishaaq            #+#    #+#             */
/*   Updated: 2025/11/30 20:17:01 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**set_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;

	i = -1;
	while (envp[++i] != NULL)
		if (strncmp(envp[i], "PATH", 4) == 0)
			paths = ft_split(envp[i], ':');

	i = -1;
	while (paths[++i] != 0)
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
	}
	ft_memmove(paths[0], paths[0] + 5, ft_strlen(paths[0]) - 6);
	return (paths);
}

int	check_access(t_cmd *cmd, char *path)
{
	char	*tmp;

	tmp = ft_strjoin(path, cmd->cmd);
	if (access(tmp, 0) == 0)
	{
		cmd->path = tmp;
		return (1);
	}
	else
		free(tmp);
	return (0);
}

int	validate_cmds(t_data *data)
{
	int		count;
	int		i;
	char	**paths;

	i = -1;
	count = 0;
	paths = data->paths;
	while (paths[++i] != 0 && count != 2)
	{
		count += check_access(data->cmd1, paths[i]);
		count += check_access(data->cmd2, paths[i]);
	}
	if (count != 2)
		return (write(2, "Bad command path(s)\n", 12), exit(1), 1);
	return (0);
}

t_cmd	*init_cmd(char *full_cmd)
{
	char	**options_lst;
	t_cmd	*cmd;
	char	*tmp;

	cmd = malloc(sizeof(t_cmd));
	options_lst = ft_split(full_cmd, ' ');
	tmp = options_lst[0];
	options_lst[0] = ft_strdup("a.out");
	cmd->options = options_lst;
	cmd->cmd = tmp;
	return (cmd);
}

void	init_data(t_data *data, char **av, char **envp)
{
	if (access(av[1], 0) != 0 || access(av[4], 0) != 0)
		return (write(2, "Bad paths\n", 12), exit(1));
	data->file1 = ft_strdup(av[1]);
	data->file2 = ft_strdup(av[4]);

	data->cmd1 = init_cmd(av[2]);
	data->cmd2 = init_cmd(av[3]);

	data->paths = set_paths(envp);
	validate_cmds(data);
}
