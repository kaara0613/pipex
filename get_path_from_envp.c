/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:36:50 by kaara             #+#    #+#             */
/*   Updated: 2025/01/24 14:58:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	path = ft_split(envp[i] + 5, ':');
	if (path == NULL)
	{
		perror("ft_sprit return NULL");
		free_exit(pipex, false);
	}
	return (path);
}
