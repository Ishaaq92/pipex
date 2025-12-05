/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:02 by ishaaq            #+#    #+#             */
/*   Updated: 2025/12/05 19:26:04 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_second_cmd(t_data *data)
{
	// char	*av[] = {"a.out", data->file1, NULL};
	int		child;
	int fd;
	
	fd = open(data->file2, O_RDWR);
	child = fork();
	if (child == -1)
		return (write(2, "Error\n", 6), ft_quit(data), 1);
	else if (child == 0)
	{
		dup2(fd, STDOUT_FILENO);
		printf("heree");
		if (execve(data->cmd2->path, data->cmd2->options, data->envp) == -1)
			return (write(2, "Error\n", 6), ft_quit(data), 1);
	}
	printf("heree");
	wait(NULL);
	return (0);
}

int	append_to_file(t_data *data, char *buffer)
{
	int fd;
	
	fd = open(data->file1, O_RDWR);
	if (fd < 0)
		return (write(2, "Error\n", 6), ft_quit(data), 1);
	write(fd, buffer, sizeof(buffer));
	close(fd);
	return (0);
}

int	execute_cmd(t_data *data)
{
	char	buffer[1024];
	int		fd[2];
	int		file1_fd;
	int		child;

	if (pipe(fd) == -1)
		return (write(2, "Error\n", 6), ft_quit(data), 1);
	child = fork();
	if (child == -1)
		return (write(2, "Error\n", 6), ft_quit(data), 1);
	if (child == 0)
	{
		close(fd[0]);
		file1_fd = open(data->file1, O_RDWR);
		dup2(file1_fd, STDIN_FILENO);
		close(file1_fd);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (execve(data->cmd1->path, data->cmd1->options, data->envp) == -1)
			return (write(2, "Error\n", 6), ft_quit(data), 1);
	}
	else
	{
		printf("test");
		wait(NULL);
		close(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
		close(fd[0]);
	}
	// append_to_file(data, buffer);
	// execute_second_cmd(data);
	return (0);
}

