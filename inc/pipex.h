/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:50:44 by ishaaq            #+#    #+#             */
/*   Updated: 2025/12/05 18:43:31 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../Libft/libft.h"

typedef	struct	s_cmd
{
	char	*cmd;
	char	**options;
	char	*path;
}		t_cmd;

typedef struct s_data
{
	char	*file1;
	char	*file2;
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	**paths;
	char	**envp;
}	t_data;

int		execute_cmd(t_data *data);
void	ft_quit(t_data *data);
char	**set_paths(char **envp);
void	init_data(t_data *data, char **av, char **envp);
int		validate_cmds(t_data *data);
char	**ft_arrappend(char **lst, char *item);

#endif
