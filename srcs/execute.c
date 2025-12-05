/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:02 by ishaaq            #+#    #+#             */
/*   Updated: 2025/12/05 20:14:15 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_second_cmd(t_data *data, int fd_in)
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
		close(fd);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
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
	int		fd[2];
	int		file1_fd;
	int		file2_fd;
	int		child;

	file1_fd = open(data->file1, O_RDWR);
	if (pipe(fd) == -1 || file1_fd < 0)
		return (write(2, "Error\n", 6), ft_quit(data), 1);
	child = fork();
	if (child == -1)
		return (write(2, "Error\n", 6), ft_quit(data), 1);
	if (child == 0)
	{
		close(fd[0]);
		dup2(file1_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(file1_fd);
		if (execve(data->cmd1->path, data->cmd1->options, data->envp) == -1)
			return (write(2, "Error\n", 6), ft_quit(data), 1);
	}
	file2_fd = open(data->file2, O_RDWR);
	child  = fork();
	if (child == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(file2_fd, STDOUT_FILENO);
		execute_second_cmd(data, fd[0]);
	}
	close(fd[1]);
	close(fd[0]);
	return (0);
}

