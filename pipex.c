/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:50:48 by ishaaq            #+#    #+#             */
/*   Updated: 2025/10/14 14:56:16 by ishaaq           ###   ########.fr       */
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

int	validate_cmds(t_data *data, char **envp)
{
	char	*tmp1;
	char	*tmp2;
	char	**paths;
	int		i;

	i = -1;
	paths = data->paths;
	while (paths[++i] != 0)
	{
		tmp1 = ft_strjoin(paths[i], data->cmd1);
		tmp2 = ft_strjoin(paths[i], data->cmd2);
		if (access(tmp1, 0) != 0)
			break ;
		free(tmp1);
		free(tmp2);
	}
	if (envp[i] == 0)
		return (write(2, "Bad paths\n", 12), exit(1), 1);
	return (0);
}

void	init_data(t_data *data, char **av, char **envp)
{
	// Checking if the files exist
	if (access(av[1], 0) != 0 || access(av[4], 0) != 0)
		return (write(2, "Bad paths\n", 12), exit(1));
	validate_cmds(data, envp);
	data->file1 = ft_strdup(av[1]);
	data->file2 = ft_strdup(av[4]);
	data->cmd1 = ft_strdup(av[2]);
	data->cmd2 = ft_strdup(av[3]);
	data->paths = set_paths(envp);
}

void	ft_quit(t_data *data)
{
	int		i;
	char	**paths;

	paths = data->paths;
	i = -1;
	while (paths[++i] != 0)
		free(paths[i]);
	free(paths);
	free(data->file1);
	free(data->file2);
	free(data->cmd1);
	free(data->cmd2);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	**paths;
	t_data	data;

	if (ac != 5)
		return (write(2, "error\n", 6),1);
	init_data(&data, av, envp);
	paths = data.paths;
	i = -1;
	while (paths[++i] != 0)
		printf("%s\n", paths[i]);
	ft_quit(&data);
}
