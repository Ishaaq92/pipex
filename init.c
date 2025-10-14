/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:59:29 by ishaaq            #+#    #+#             */
/*   Updated: 2025/10/14 19:14:22 by ishaaq           ###   ########.fr       */
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

int	check_access(t_data *data, char *path)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = ft_strjoin(path, data->cmd1);
	if (access(tmp, 0) == 0)
	{
		data->cmd1_path = tmp;
		// printf("%s\n", data->cmd1_path);
		count ++;
	}
	else
		free(tmp);
	tmp = ft_strjoin(path, data->cmd2);
	if (access(tmp, 0) == 0)
	{
		data->cmd2_path = tmp;
		count ++;
	}
	else
		free(tmp);
	return (count);
}

int	validate_cmds(t_data *data)
{
	char	**paths;
	int		i;
	int		count;

	i = -1;
	paths = data->paths;
	count = 0;
	while (paths[++i] != 0 && count != 2)
		count += check_access(data, paths[i]);
	if (count != 2)
		return (write(2, "Bad command path(s)\n", 12), exit(1), 1);
	return (0);
}

void	init_data(t_data *data, char **av, char **envp)
{
	// Checking if the files exist
	if (access(av[1], 0) != 0 || access(av[4], 0) != 0)
		return (write(2, "Bad paths\n", 12), exit(1));
	data->file1 = ft_strdup(av[1]);
	data->file2 = ft_strdup(av[4]);
	data->cmd1 = ft_strdup(av[2]);
	data->cmd2 = ft_strdup(av[3]);
	data->paths = set_paths(envp);
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	validate_cmds(data);
}
