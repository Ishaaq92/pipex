/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:50:44 by ishaaq            #+#    #+#             */
/*   Updated: 2025/10/14 19:27:49 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "Libft/libft.h"

typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**paths;
	char	**envp;
}	t_data;

int		execute_cmd(t_data *data);
void	ft_quit(t_data *data);
char	**set_paths(char **envp);
void	init_data(t_data *data, char **av, char **envp);
int		validate_cmds(t_data *data);

#endif
