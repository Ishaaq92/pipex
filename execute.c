/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:02 by ishaaq            #+#    #+#             */
/*   Updated: 2025/10/14 19:31:27 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(t_data *data)
{
	char	*av[] = {"a.out", NULL};

	// if (fork() != 0)
	// 	return ;
	if (execve(data->cmd1_path, av, data->envp) == -1)
		return (write(2, "Error\n", 6), 0);
	return (1);
}
