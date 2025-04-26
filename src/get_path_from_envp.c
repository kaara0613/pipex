/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:36:50 by kaara             #+#    #+#             */
/*   Updated: 2025/04/26 13:12:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char	**get_path_from_envp(char *const *envp, t_pipex *pipex)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", sizeof(char) * 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
	{
		ft_dprintf("PATH not found in envp\n");
		free_exit(pipex, 1);
	}
	path = ft_split(envp[i] + 5, ':');
	if (path == NULL)
	{
		ft_dprintf("ft_sprit return NULL\n");
		free_exit(pipex, 1);
	}
	return (path);
}
