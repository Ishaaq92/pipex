/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:50:44 by ishaaq            #+#    #+#             */
/*   Updated: 2025/10/14 14:50:45 by ishaaq           ###   ########.fr       */
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
	char	**paths;
}	t_data;

#endif
