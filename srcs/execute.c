/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:02 by ishaaq            #+#    #+#             */
/*   Updated: 2025/11/30 20:17:01 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(t_data *data)
{
	char	*av[] = {"a.out", NULL};
	int		child;
	int		fd[2];
	char	text[8];

	pipe(fd);
	child = fork();
	if (child == -1)
		return (write(2, "Error\n", 6), 1);
	if (child == 0)
	{
		close(fd[0]);
		write(fd[1], "test\n\0", 5);
		printf("I think this is the child process\n");
		if (execve(data->cmd1->path, av, data->envp) == -1)
			return (write(2, "Error\n", 6), exit(1), 0);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &text, 5);
		wait(NULL);
		printf("I think this is the parent process\n");
		close(fd[0]);
	}
	printf("The string from the child process is %s\n", text);
	return (1);
}
