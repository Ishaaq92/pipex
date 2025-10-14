/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:50:48 by ishaaq            #+#    #+#             */
/*   Updated: 2025/10/14 15:26:15 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	**paths;
	t_data	data;

	if (ac != 5)
		return (write(2, "error\n", 6),1);
	init_data(&data, av, envp);
	i = -1;
	paths = data.paths;
	while (paths[++i] != 0)
		printf("%s\n", paths[i]);
	ft_quit(&data);
}
