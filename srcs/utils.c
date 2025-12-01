/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:00:33 by ishaaq            #+#    #+#             */
/*   Updated: 2025/11/30 20:23:44 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_quit(t_data *data)
{
	char	**paths;
	int		i;

	paths = data->paths;
	i = -1;
	while (paths[++i] != 0)
		free(paths[i]);
	free(paths);
	free(data->file1);
	free(data->file2);
	free(data->cmd1->cmd);
	free(data->cmd2->cmd);
	free(data->cmd1->path);
	free(data->cmd2->path);
	free(data->cmd1);
	free(data->cmd2);
}
